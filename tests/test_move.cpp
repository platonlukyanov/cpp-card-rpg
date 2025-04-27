#include <gtest/gtest.h>
#include "move.h"
#include "card_factory.h"
#include "player.h"
#include "leverage_card.h"

class MoveTest : public ::testing::Test {
protected:
    void SetUp() override {
        factory = std::make_unique<CardFactory>();
        player = std::make_unique<Player>("test_id", "test_secret");
        player->setDepartment("разработка");
        card = factory->createCard("Тимлид", 1);
    }

    std::unique_ptr<CardFactory> factory;
    std::unique_ptr<Player> player;
    std::unique_ptr<Card> card;
};

TEST_F(MoveTest, ConstructorSetsCorrectValues) {
    Move move(*player, std::move(card));
    EXPECT_EQ(move.getActor().getId(), "test_id");
}

TEST_F(MoveTest, IsAbleToAcceptReturnsTrueInitially) {
    Move move(*player, std::move(card));
    EXPECT_TRUE(move.isAbleToAccept());
}

TEST_F(MoveTest, AcceptUpdatesMoveState) {
    Move move(*player, std::move(card));
    move.accept();
    EXPECT_FALSE(move.isAbleToAccept());
}

TEST_F(MoveTest, DeclineUpdatesMoveState) {
    Move move(*player, std::move(card));
    move.decline();
    EXPECT_FALSE(move.isAbleToAccept());
}

TEST_F(MoveTest, TradeUpdatesPlayerMoney) {
    Move move(*player, std::move(card));
    Player buyer("buyer_id", "buyer_secret");

    buyer.setDepartment("разработка");
    buyer.gainMoney(20); // Даем покупателю начальные деньги
    int initialMoney = buyer.getMoney();
    move.trade(10, buyer);
    EXPECT_EQ(buyer.getMoney(), initialMoney - 10);
}

TEST_F(MoveTest, CantTradeIfCardIsntPossibleToPlay) {
    Move move(*player, std::move(card));
    Player buyer("buyer_id", "buyer_secret");
    buyer.setDepartment("финансы"); // can't buy a card of a character from different department
    buyer.gainMoney(20);
    move.trade(10, buyer);
    EXPECT_EQ(buyer.getMoney(), 20);
}

TEST_F(MoveTest, UseLeverageUpdatesPlayerStats) {
    Move move(*player, std::move(card));
    Player target("target_id", "target_secret");
    auto leverageCard = factory->createCard("Раскрыть статус миграции двоюродной сестры", 1);
    move.useLeverage(*dynamic_cast<LeverageCard*>(leverageCard.get()), target);
    EXPECT_EQ(target.getTrust(), 6); // Начальное доверие 10, минус 4 от карты рычага
} 
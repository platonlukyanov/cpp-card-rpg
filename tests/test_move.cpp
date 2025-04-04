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
    buyer.gainMoney(20); // Даем покупателю начальные деньги
    int initialMoney = buyer.getMoney();
    move.trade(10, buyer);
    EXPECT_EQ(buyer.getMoney(), initialMoney - 10);
}

TEST_F(MoveTest, UseLeverageUpdatesPlayerStats) {
    Move move(*player, std::move(card));
    Player target("target_id", "target_secret");
    target.gainMoney(5);
    target.gainReputation(10);
    auto leverageCard = factory->createCard("Рассказать о твите из прошлого десятелетия", 1);
    move.useLeverage(*dynamic_cast<LeverageCard*>(leverageCard.get()), target);
    EXPECT_EQ(target.getTrust(), 9); // Начальное доверие 10, минус 4 от карты рычага, так как доверие < 50
    EXPECT_EQ(target.getReputation(), 5); // Начальное доверие 0, минус 1 от карты рычага
    EXPECT_EQ(target.getMoney(), 5); // Начальное деньги 0, минус 0 от карты рычага
} 
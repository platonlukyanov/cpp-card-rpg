#include <gtest/gtest.h>
#include "action_card.h"
#include "player.h"

class ActionCardTest : public ::testing::Test {
protected:
    void SetUp() override {
        card = std::make_unique<ActionCard>(1, "Тестовая карта", 10, 5, 10);
        player = std::make_unique<Player>("test_id", "test_secret");
    }

    std::unique_ptr<ActionCard> card;
    std::unique_ptr<Player> player;
};

TEST_F(ActionCardTest, GetReputationChangeReturnsCorrectValue) {
    EXPECT_EQ(card->getReputationChange(), 10);
}

TEST_F(ActionCardTest, GetMoneyChangeReturnsCorrectValue) {
    EXPECT_EQ(card->getMoneyChange(), 5);
}

TEST_F(ActionCardTest, IsPossibleToPlayReturnsTrue) {
    EXPECT_TRUE(card->isPossibleToPlay(*player));
}

TEST_F(ActionCardTest, ExecuteUpdatesPlayerStats) {
    card->execute(*player);
    
    EXPECT_EQ(player->getReputation(), 1); // 10% от 10
    EXPECT_EQ(player->getMoney(), 5);
    EXPECT_EQ(player->getTrust(), 20); // 10 (базовое) + 10 (изменение)
} 
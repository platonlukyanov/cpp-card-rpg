#include <gtest/gtest.h>
#include "own_reputation_after_move_condition_action_card.h"
#include "player.h"

class OwnReputationAfterMoveConditionActionCardTest : public ::testing::Test {
protected:
    void SetUp() override {
        card = std::make_unique<OwnReputationAfterMoveConditionActionCard>(1, "Тестовая карта", 10, 5, 50);
        player = std::make_unique<Player>("test_id", "test_secret");
    }

    std::unique_ptr<OwnReputationAfterMoveConditionActionCard> card;
    std::unique_ptr<Player> player;
};

TEST_F(OwnReputationAfterMoveConditionActionCardTest, GetMinReputationReturnsCorrectValue) {
    EXPECT_EQ(card->getMinReputation(), 50);
}

TEST_F(OwnReputationAfterMoveConditionActionCardTest, IsPossibleToPlayReturnsTrueWhenReputationWillMeetCondition) {
    player->gainReputation(50);
    EXPECT_TRUE(card->isPossibleToPlay(*player));
}

TEST_F(OwnReputationAfterMoveConditionActionCardTest, IsPossibleToPlayReturnsFalseWhenReputationWillNotMeetCondition) {
    player->gainReputation(35);
    EXPECT_FALSE(card->isPossibleToPlay(*player));
}

TEST_F(OwnReputationAfterMoveConditionActionCardTest, ExecuteUpdatesPlayerStats) {
    player->gainReputation(45);
    card->execute(*player);
    
    EXPECT_EQ(player->getReputation(), 46); // 45 + 1 (10% от 10)
    EXPECT_EQ(player->getMoney(), 5);
    EXPECT_EQ(player->getTrust(), 10); // Базовое доверие
} 
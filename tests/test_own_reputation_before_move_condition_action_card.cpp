/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include <gtest/gtest.h>

#include "own_reputation_before_move_condition_action_card.h"
#include "player.h"

class OwnReputationBeforeMoveConditionActionCardTest : public ::testing::Test {
    protected:
        void SetUp() override {
            card = std::make_unique<OwnReputationBeforeMoveConditionActionCard>(
                1, "Test card", 10, 5, 50);
            player = std::make_unique<Player>("test_id", "test_secret");
        }

        std::unique_ptr<OwnReputationBeforeMoveConditionActionCard> card;
        std::unique_ptr<Player> player;
};

TEST_F(OwnReputationBeforeMoveConditionActionCardTest,
       GetMinReputationReturnsCorrectValue) {
    EXPECT_EQ(card->getMinReputation(), 50);
}

TEST_F(OwnReputationBeforeMoveConditionActionCardTest,
       IsPossibleToPlayReturnsTrueWhenReputationMeetsCondition) {
    player->gainReputation(60);
    EXPECT_TRUE(card->isPossibleToPlay(*player));
}

TEST_F(OwnReputationBeforeMoveConditionActionCardTest,
       IsPossibleToPlayReturnsFalseWhenReputationBelowCondition) {
    player->gainReputation(40);
    EXPECT_FALSE(card->isPossibleToPlay(*player));
}

TEST_F(OwnReputationBeforeMoveConditionActionCardTest,
       ExecuteUpdatesPlayerStats) {
    player->gainReputation(60);
    card->execute(*player);

    EXPECT_EQ(player->getReputation(), 70);  // 60 + 10
    EXPECT_EQ(player->getMoney(), 5);
    EXPECT_EQ(player->getTrust(), 10);  // Base trust
}
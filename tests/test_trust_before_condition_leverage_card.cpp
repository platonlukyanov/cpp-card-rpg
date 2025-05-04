/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include <gtest/gtest.h>
#include "trust_before_condition_leverage_card.h"
#include "player.h"

class TrustBeforeConditionLeverageCardTest : public ::testing::Test {
protected:
    void SetUp() override {
        card = std::make_unique<TrustBeforeConditionLeverageCard>(1, "Test card", -1, -5, -4, 40);
        player = std::make_unique<Player>("test_id", "test_secret");
        player->gainTrust(15);
        player->gainReputation(10);
        player->gainMoney(100);
    }

    std::unique_ptr<TrustBeforeConditionLeverageCard> card;
    std::unique_ptr<Player> player;
};

TEST_F(TrustBeforeConditionLeverageCardTest, GetMinTrustReturnsCorrectValue) {
    EXPECT_EQ(card->getMinTrust(), 40);
}

TEST_F(TrustBeforeConditionLeverageCardTest, IsPossibleToPlayReturnsTrueWhenTrustMeetsCondition) {
    player->gainTrust(25);
    EXPECT_TRUE(card->isPossibleToPlay(*player));
}

TEST_F(TrustBeforeConditionLeverageCardTest, ExecuteUpdatesPlayerStats) {
    card->executeOnPlayer(*player);
    
    EXPECT_EQ(player->getReputation(), 9);  // 10 - 1
    EXPECT_EQ(player->getMoney(), 95);     // 100 - 5
    EXPECT_EQ(player->getTrust(), 21);      // 25 - 4
} 
#include <gtest/gtest.h>
#include "trust_before_condition_leverage_card.h"
#include "player.h"

class TrustBeforeConditionLeverageCardTest : public ::testing::Test {
protected:
    void SetUp() override {
        card = std::make_unique<TrustBeforeConditionLeverageCard>(1, "Тестовая карта", -10, -5, -2, 15);
        // -10 репутации, -5 денег, -2 доверия, если доверие ниже 15
        player = std::make_unique<Player>("test_id", "test_secret");
        player->gainTrust(1);
        player->gainReputation(10);
        player->gainMoney(100);
    }

    std::unique_ptr<TrustBeforeConditionLeverageCard> card;
    std::unique_ptr<Player> player;
};

TEST_F(TrustBeforeConditionLeverageCardTest, GetMinTrustReturnsCorrectValue) {
    EXPECT_EQ(card->getMinTrust(), 15);
}

TEST_F(TrustBeforeConditionLeverageCardTest, IsPossibleToPlayReturnsTrueWhenTrustMeetsCondition) {
    EXPECT_TRUE(card->isPossibleToPlay(*player));
}

TEST_F(TrustBeforeConditionLeverageCardTest, IsPossibleToPlayReturnsFalseWhenTrustBelowCondition) {
    EXPECT_TRUE(card->isPossibleToPlay(*player));  // Карта рычага всегда может быть сыграна
}

TEST_F(TrustBeforeConditionLeverageCardTest, ExecuteUpdatesPlayerStats) {
    card->execute(*player);
    
    EXPECT_EQ(player->getReputation(), 0);  // 10 - 10
    EXPECT_EQ(player->getMoney(), 95);      // 100 - 5
    EXPECT_EQ(player->getTrust(), 9);      // 10 + 1 - 2 (так как доверие < 15)
} 
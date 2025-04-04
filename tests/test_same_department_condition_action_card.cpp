#include <gtest/gtest.h>
#include "same_department_condition_action_card.h"
#include "player.h"

class SameDepartmentConditionActionCardTest : public ::testing::Test {
protected:
    void SetUp() override {
        card = std::make_unique<SameDepartmentConditionActionCard>(1, "Тестовая карта", 10, 5, "разработка");
        player = std::make_unique<Player>("test_id", "test_secret");
    }

    std::unique_ptr<SameDepartmentConditionActionCard> card;
    std::unique_ptr<Player> player;
};

TEST_F(SameDepartmentConditionActionCardTest, GetDepartmentReturnsCorrectValue) {
    EXPECT_EQ(card->getDepartment(), "разработка");
}

TEST_F(SameDepartmentConditionActionCardTest, IsPossibleToPlayReturnsTrueWhenDepartmentMatches) {
    player->setDepartment("разработка");
    EXPECT_TRUE(card->isPossibleToPlay(*player));
}

TEST_F(SameDepartmentConditionActionCardTest, IsPossibleToPlayReturnsFalseWhenDepartmentDoesNotMatch) {
    player->setDepartment("финансы");
    EXPECT_FALSE(card->isPossibleToPlay(*player));
}

TEST_F(SameDepartmentConditionActionCardTest, ExecuteUpdatesPlayerStats) {
    player->setDepartment("разработка");
    card->execute(*player);
    
    EXPECT_EQ(player->getReputation(), 1); // 10% от 10
    EXPECT_EQ(player->getMoney(), 5);
    EXPECT_EQ(player->getTrust(), 10); // Базовое доверие
} 
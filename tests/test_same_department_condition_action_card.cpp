/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include <gtest/gtest.h>
#include "same_department_condition_action_card.h"
#include "player.h"

class SameDepartmentConditionActionCardTest : public ::testing::Test {
protected:
    void SetUp() override {
        card = std::make_unique<SameDepartmentConditionActionCard>(1, "Test card", 10, 5, "development");
        player = std::make_unique<Player>("test_id", "test_secret");
    }

    std::unique_ptr<SameDepartmentConditionActionCard> card;
    std::unique_ptr<Player> player;
};

TEST_F(SameDepartmentConditionActionCardTest, GetDepartmentReturnsCorrectValue) {
    EXPECT_EQ(card->getDepartment(), "development");
}

TEST_F(SameDepartmentConditionActionCardTest, IsPossibleToPlayReturnsTrueWhenDepartmentMatches) {
    player->setDepartment("development");
    EXPECT_TRUE(card->isPossibleToPlay(*player));
}

TEST_F(SameDepartmentConditionActionCardTest, IsPossibleToPlayReturnsFalseWhenDepartmentDoesNotMatch) {
    player->setDepartment("finance");
    EXPECT_FALSE(card->isPossibleToPlay(*player));
}

TEST_F(SameDepartmentConditionActionCardTest, ExecuteUpdatesPlayerStats) {
    player->setDepartment("development");
    card->execute(*player);
    
    EXPECT_EQ(player->getReputation(), 10);
    EXPECT_EQ(player->getMoney(), 5);
    EXPECT_EQ(player->getTrust(), 10); // Base trust
}
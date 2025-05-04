#include <gtest/gtest.h>
#include "ally_reputation_condition_action_card.h"
#include "player.h"
#include "character_card.h"

class AllyReputationConditionActionCardTest : public ::testing::Test {
protected:
    void SetUp() override {
        card = std::make_unique<AllyReputationConditionActionCard>(1, "Test Card", 10, 5, 40);
        player = std::make_unique<Player>("test_id", "test_secret");
        character = std::make_unique<CharacterCard>(2, "Ally", 50, 20, "development");
    }

    std::unique_ptr<AllyReputationConditionActionCard> card;
    std::unique_ptr<Player> player;
    std::unique_ptr<CharacterCard> character;
};

TEST_F(AllyReputationConditionActionCardTest, GetMinAllyReputationReturnsCorrectValue) {
    EXPECT_EQ(card->getMinAllyReputation(), 40);
}

TEST_F(AllyReputationConditionActionCardTest, IsPossibleToPlayReturnsTrueWhenAllyMeetsCondition) {
    player->setDepartment("development");
    player->addAlly(*character);
    EXPECT_TRUE(card->isPossibleToPlay(*player));
}

TEST_F(AllyReputationConditionActionCardTest, IsPossibleToPlayReturnsFalseWhenNoAllyMeetsCondition) {
    player->setDepartment("development");
    auto weakAlly = std::make_unique<CharacterCard>(3, "Weak ally", 30, 10, "development");
    player->addAlly(*weakAlly);
    EXPECT_FALSE(card->isPossibleToPlay(*player));
}

TEST_F(AllyReputationConditionActionCardTest, ExecuteUpdatesPlayerStats) {
    player->setDepartment("development");
    player->addAlly(*character);
    card->execute(*player);
    
    EXPECT_EQ(player->getReputation(), 10);
    EXPECT_EQ(player->getMoney(), 5);
    EXPECT_EQ(player->getTrust(), 20); // 10 (base) + 10 (change)
} 
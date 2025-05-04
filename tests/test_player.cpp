#include <gtest/gtest.h>
#include "player.h"
#include "character_card.h"

class PlayerTest : public ::testing::Test {
protected:
    void SetUp() override {
        player = std::make_unique<Player>("test_id", "test_secret");
        character = std::make_unique<CharacterCard>(1, "Test character", 30, 20, "development");
    }

    std::unique_ptr<Player> player;
    std::unique_ptr<CharacterCard> character;
};

TEST_F(PlayerTest, GetIdReturnsCorrectValue) {
    EXPECT_EQ(player->getId(), "test_id");
}

TEST_F(PlayerTest, GetSecretReturnsCorrectValue) {
    EXPECT_EQ(player->getSecret(), "test_secret");
}

TEST_F(PlayerTest, GetReputationReturnsZeroInitially) {
    EXPECT_EQ(player->getReputation(), 0);
}

TEST_F(PlayerTest, GetMoneyReturnsZeroInitially) {
    EXPECT_EQ(player->getMoney(), 0);
}

TEST_F(PlayerTest, GetTrustReturnsTenInitially) {
    EXPECT_EQ(player->getTrust(), 10);
}

TEST_F(PlayerTest, SetAndGetDepartment) {
    player->setDepartment("development");
    EXPECT_EQ(player->getDepartment(), "development");
}

TEST_F(PlayerTest, AddAllyIncreasesAlliesCount) {
    player->setDepartment("development");
    player->addAlly(*character);
    EXPECT_EQ(player->getAllies().size(), 1);
}

TEST_F(PlayerTest, HasAllyFromDepartmentReturnsTrueForMatchingDepartment) {
    player->setDepartment("development");
    player->addAlly(*character);
    EXPECT_TRUE(player->hasAllyFromDepartment("development"));
}

TEST_F(PlayerTest, HasAllyFromDepartmentReturnsFalseForDifferentDepartment) {
    player->setDepartment("development");
    player->addAlly(*character);
    EXPECT_FALSE(player->hasAllyFromDepartment("finance"));
}

TEST_F(PlayerTest, HasAllyWithReputationAboveReturnsTrueForMatchingAlly) {
    player->setDepartment("development");
    player->addAlly(*character);
    EXPECT_TRUE(player->hasAllyWithReputationAbove(25));
}

TEST_F(PlayerTest, HasAllyWithReputationAboveReturnsFalseForNoMatchingAlly) {
    player->setDepartment("development");
    player->addAlly(*character);
    EXPECT_FALSE(player->hasAllyWithReputationAbove(35));
} 
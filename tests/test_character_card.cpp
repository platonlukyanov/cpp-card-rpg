/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include <gtest/gtest.h>

#include "character_card.h"
#include "player.h"

class CharacterCardTest : public ::testing::Test {
    protected:
        void SetUp() override {
            card = std::make_unique<CharacterCard>(1, "Test card", 30, 20,
                                                   "development");
            player = std::make_unique<Player>("test_id", "test_secret");
        }

        std::unique_ptr<CharacterCard> card;
        std::unique_ptr<Player> player;
};

TEST_F(CharacterCardTest, GetReputationReturnsCorrectValue) {
    EXPECT_EQ(card->getReputation(), 30);
}

TEST_F(CharacterCardTest, GetMoneyReturnsCorrectValue) {
    EXPECT_EQ(card->getMoney(), 20);
}

TEST_F(CharacterCardTest, GetDepartmentReturnsCorrectValue) {
    EXPECT_EQ(card->getDepartment(), "development");
}

TEST_F(CharacterCardTest, IsPossibleToPlayReturnsTrueForSameDepartment) {
    player->setDepartment("development");
    EXPECT_TRUE(card->isPossibleToPlay(*player));
}

TEST_F(CharacterCardTest, IsPossibleToPlayReturnsFalseForDifferentDepartment) {
    player->setDepartment("finance");
    EXPECT_FALSE(card->isPossibleToPlay(*player));
}

TEST_F(CharacterCardTest, ExecuteAddsAllyAndUpdatesStats) {
    player->setDepartment("development");
    card->execute(*player);

    EXPECT_EQ(player->getAllies().size(), 1);
    EXPECT_EQ(player->getReputation(), 3);
    EXPECT_EQ(player->getTrust(), 11);  // 10 (base) + 1 (from character card)
}
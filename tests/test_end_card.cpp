#include <gtest/gtest.h>
#include "end_card.h"
#include "player.h"

class EndCardTest : public ::testing::Test {
protected:
    void SetUp() override {
        card = std::make_unique<EndCard>(1);
        player = std::make_unique<Player>("test_id", "test_secret");
    }

    std::unique_ptr<EndCard> card;
    std::unique_ptr<Player> player;
};

TEST_F(EndCardTest, IsPossibleToPlayReturnsTrue) {
    EXPECT_TRUE(card->isPossibleToPlay(*player));
}

TEST_F(EndCardTest, ExecuteDoesNotUpdatePlayerStats) {
    card->execute(*player);
    
    EXPECT_EQ(player->getReputation(), 0);
    EXPECT_EQ(player->getMoney(), 0);
    EXPECT_EQ(player->getTrust(), 10); // Base trust
} 
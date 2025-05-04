/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include <gtest/gtest.h>
#include "game.h"
#include "card_factory.h"
#include "player.h"
#include "ai.h"

class GameTest : public ::testing::Test {
protected:
    void SetUp() override {
        factory = std::make_unique<CardFactory>();
        
        std::vector<UserPlayerInput> players;
        UserPlayerInput playerInput;
        playerInput.playerName = "player_id";
        playerInput.playerSecret = "player_secret";
        playerInput.isAI = false;
        players.push_back(playerInput);
        
        UserPlayerInput aiInput;
        aiInput.playerName = "ai_id";
        aiInput.playerSecret = "ai_secret";
        aiInput.isAI = true;
        players.push_back(aiInput);

        game.initialize(players);

        player = game.getPlayers()[0];
        ai = game.getPlayers()[1];
    }

    std::unique_ptr<CardFactory> factory;
    std::shared_ptr<Player> player;
    std::shared_ptr<Player> ai;
    Game game;
};
TEST_F(GameTest, GetPlayersReturnsCorrectValue) {
    EXPECT_EQ(game.getPlayers().size(), 2);
}

TEST_F(GameTest, OfferMoveReturnsValidMove) {
    auto move = game.offerMove();
    ASSERT_NE(move, nullptr);
}

TEST_F(GameTest, NextAdvancesGameState) {
    game.next();
    // Check that the game is not over yet (75% of the game should not be over)
    EXPECT_FALSE(game.isEnd());
}

TEST_F(GameTest, IsEndReturnsFalseInitially) {
    EXPECT_FALSE(game.isEnd());
}

TEST_F(GameTest, IsEndReturnsTrueAfterEndCard) {
    std::unique_ptr<Move> currentMove = game.offerMove();

    while (currentMove->getCard()->getType() != Card::Type::END) {
        game.next();
        currentMove = game.offerMove();
    }

    EXPECT_TRUE(game.isEnd());
}

TEST_F(GameTest, DetermineWinnerReturnsNullptrWhenGameNotEnd) {
    EXPECT_EQ(game.determineWinner(), nullptr);
}

TEST_F(GameTest, DetermineWinnerReturnsPlayerWithMostTrust) {
    std::unique_ptr<Move> currentMove = game.offerMove();
    while (currentMove->getCard()->getType() != Card::Type::END) {
        game.next();
        currentMove = game.offerMove();
    }

    // create a situation when player with most trust wins
    player->gainTrust(100);
    ai->loseTrust(0);

    ASSERT_NE(game.determineWinner(), nullptr);
    EXPECT_EQ(game.determineWinner()->getSecret(), player->getSecret());
}

TEST_F(GameTest, DetermineWinnerReturnsPlayerWithMostReputation) {
    std::unique_ptr<Move> currentMove = game.offerMove();
    while (currentMove->getCard()->getType() != Card::Type::END) {
        game.next();
        currentMove = game.offerMove();
    }
    ASSERT_EQ(game.isEnd(), true);
    player->loseTrust(100);
    ai->loseTrust(100);

    // create a situation when player with most reputation wins
    player->gainReputation(100);
    ai->loseReputation(100);
    
    ASSERT_NE(game.determineWinner(), nullptr);
    EXPECT_EQ(game.determineWinner()->getSecret(), player->getSecret());
}

TEST_F(GameTest, DetermineWinnerReturnsPlayerWithMostMoney) {
    std::unique_ptr<Move> currentMove = game.offerMove();
    while (currentMove->getCard()->getType() != Card::Type::END) {
        game.next();
        currentMove = game.offerMove();
    }
    ASSERT_EQ(game.isEnd(), true);
    player->loseTrust(100);
    ai->loseTrust(100);
    player->loseReputation(100);
    ai->loseReputation(100);

    // create a situation when player with most money wins
    player->gainMoney(100);
    ai->loseMoney(100);

    ASSERT_NE(game.determineWinner(), nullptr);
    EXPECT_EQ(game.determineWinner()->getSecret(), player->getSecret());
}
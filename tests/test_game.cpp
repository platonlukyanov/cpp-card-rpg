#include <gtest/gtest.h>
#include "game.h"
#include "card_factory.h"
#include "player.h"
#include "ai.h"

class GameTest : public ::testing::Test {
protected:
    void SetUp() override {
        factory = std::make_unique<CardFactory>();
        player = std::make_unique<Player>("player_id", "player_secret");
        ai = std::make_unique<AI>("ai_id", "ai_secret");
        game = std::make_unique<Game>();
        
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
        
        game->initialize(players);
    }

    std::unique_ptr<CardFactory> factory;
    std::unique_ptr<Player> player;
    std::unique_ptr<AI> ai;
    std::unique_ptr<Game> game;
};

TEST_F(GameTest, InitializeSetsUpPlayers) {
    const auto& players = game->getPlayers();
    EXPECT_EQ(players.size(), 2);
    EXPECT_EQ(players[0]->getId(), "player_id");
    EXPECT_EQ(players[1]->getId(), "ai_id");
}

TEST_F(GameTest, OfferMoveReturnsNullptrInitially) {
    auto move = game->offerMove();
    EXPECT_EQ(move, nullptr);
}

TEST_F(GameTest, NextAdvancesGameState) {
    game->next();
    // Проверяем, что игра не закончилась
    EXPECT_FALSE(game->isEnd());
}

TEST_F(GameTest, IsEndReturnsFalseInitially) {
    EXPECT_FALSE(game->isEnd());
}

TEST_F(GameTest, DetermineWinnerReturnsNullptrInitially) {
    auto winner = game->determineWinner();
    EXPECT_EQ(winner, nullptr);
} 
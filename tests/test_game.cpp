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
    }

    std::unique_ptr<CardFactory> factory;
    std::unique_ptr<Player> player;
    std::unique_ptr<AI> ai;
    Game game;
};
TEST_F(GameTest, GetPlayersReturnsCorrectValue) {
    EXPECT_EQ(game.getPlayers().size(), 2);
}

TEST_F(GameTest, OfferMoveReturnsValidMove) {
    auto move = game.offerMove();
    ASSERT_NE(move, nullptr);
    EXPECT_TRUE(move->isAbleToAccept());
}

TEST_F(GameTest, NextAdvancesGameState) {
    game.next();
    // Проверяем, что игра не закончилась (до 75% игры не должна, а это первый тест)
    EXPECT_FALSE(game.isEnd());
}

TEST_F(GameTest, IsEndReturnsFalseInitially) {
    EXPECT_FALSE(game.isEnd());
}

TEST_F(GameTest, DetermineWinnerReturnsNullptrInitially) {
    auto winner = game.determineWinner();
    EXPECT_EQ(winner, nullptr);
} 
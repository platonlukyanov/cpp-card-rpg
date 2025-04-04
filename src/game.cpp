#include "game.h"
#include "ai.h"

Game::Game() : stack_(new Stack()) {}

Game::~Game() {
    delete stack_;
    for (auto player : players_) {
        delete player;
    }
}

void Game::initialize(const std::vector<UserPlayerInput>& players) {
    for (const auto& playerInput : players) {
        Player* player;
        if (playerInput.isAI) {
            player = new AI(playerInput.playerName, playerInput.playerSecret);
        } else {
            player = new Player(playerInput.playerName, playerInput.playerSecret);
        }
        players_.push_back(player);
    }
}

const std::vector<Player*>& Game::getPlayers() const {
    return players_;
}

Move* Game::offerMove() {
    // TODO: Implement move offering
    return nullptr;
}

void Game::next() {
    // TODO: Implement turn switching
}

bool Game::isEnd() const {
    // TODO: Implement game end check
    return false;
}

Player* Game::determineWinner() const {
    // TODO: Implement winner determination
    return nullptr;
} 
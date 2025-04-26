#pragma once

#include <vector>
#include <queue>
#include <string>
#include "player.h"
#include "stack.h"
#include "move.h"

struct UserPlayerInput {
    std::string playerName;
    std::string playerSecret;
    bool isAI;
};

class Game {
public:
    Game();

    void initialize(const std::vector<UserPlayerInput>& players);
    const std::vector<std::shared_ptr<Player>> getPlayers() const;
    std::unique_ptr<Move> offerMove(); 
    void next();
    bool isEnd() const;
    std::shared_ptr<Player> determineWinner() const;

private:
    std::vector<std::shared_ptr<Player>> players_;
    std::unique_ptr<Stack> stack_;
    std::queue<std::shared_ptr<Player>> playersQueue_;
}; 
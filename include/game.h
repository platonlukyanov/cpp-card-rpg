#pragma once

#include <vector>
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
    ~Game();

    void initialize(const std::vector<UserPlayerInput>& players);
    const std::vector<Player*>& getPlayers() const;
    Move* offerMove();
    void next();
    bool isEnd() const;
    Player* determineWinner() const;

private:
    std::vector<Player*> players_;
    Stack* stack_;
    std::vector<std::string> playersQueue_;
}; 
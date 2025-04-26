#pragma once

#include "player.h"
#include "stack.h"
#include "move.h"
#include <memory>

class AI : public Player {
public:
    AI(const std::string& id, const std::string& secret);
    ~AI() override = default;

    std::unique_ptr<Move> makeMove(Stack& stack);

private:
    static constexpr const char* AI_NAME = "AI";
}; 
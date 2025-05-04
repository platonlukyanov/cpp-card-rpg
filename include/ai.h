/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#pragma once

#include "player.h"
#include "stack.h"
#include "move.h"
#include <memory>

/**
 * @brief Controls computer players in the game
 * 
 * The AI class extends Player to provide automated gameplay:
 * - Makes decisions about playing cards
 * - Evaluates card values
 * - Targets other players with leverage
 * - Manages resources and stats
 */
class AI : public Player {
public:
    /**
     * @brief Creates a new AI player
     * 
     * @param id Unique identifier for the AI
     * @param secret Secret key for authentication
     */
    AI(const std::string& id, const std::string& secret);
    ~AI() override = default;

    /**
     * @brief Makes a move based on current game state
     * Evaluates top card and decides whether to play it
     * 
     * @param stack Current game stack
     * @return std::unique_ptr<Move> The AI's chosen move
     */
    std::unique_ptr<Move> makeMove(Stack& stack);

private:
    static constexpr const char* AI_NAME = "AI"; ///< Display name for AI players
}; 
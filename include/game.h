/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#ifndef INCLUDE_GAME_H
#define INCLUDE_GAME_H

#include <queue>
#include <string>
#include <vector>

#include "move.h"
#include "player.h"
#include "stack.h"

/**
 * @brief Structure for player initialization data
 * Used when creating new players at game start
 */
struct UserPlayerInput {
        std::string playerName;    ///< Display name shown to other players
        std::string playerSecret;  ///< Authentication key for the player
        bool isAI;                 ///< Whether the player is controlled by AI
};

/**
 * @brief Main game controller class
 *
 * The Game class manages the overall game state and flow:
 * - Initializes players and card deck
 * - Manages turn order and player actions
 * - Processes card effects and player interactions
 * - Tracks game progress and determines winner
 *
 * The game ends when the CEO Death card is drawn, and the winner
 * is determined based on CEO trust, reputation, and money scores.
 */
class Game {
    public:
        /**
         * @brief Creates a new game instance
         * Initializes empty game state, ready for player setup
         */
        Game();

        /**
         * @brief Sets up the game with the specified players
         * Creates player instances, initializes card deck, and determines turn
         * order
         *
         * @param players Vector of player initialization data
         */
        void initialize(const std::vector<UserPlayerInput>& players);

        /**
         * @brief Returns all players currently in the game
         *
         * @return const std::vector<std::shared_ptr<Player>> Vector of player
         * pointers
         */
        const std::vector<std::shared_ptr<Player>> getPlayers() const;

        /**
         * @brief Processes the current player's turn
         * Handles card drawing, playing, and trading
         *
         * @return std::unique_ptr<Move> The move made by the current player
         */
        std::unique_ptr<Move> offerMove();

        /**
         * @brief Advances to the next player's turn
         * Updates turn order and game state
         */
        void next();

        /**
         * @brief Checks if the game has reached its end condition
         * Game ends when CEO Death card is drawn
         *
         * @return true if game has ended
         */
        bool isEnd() const;

        /**
         * @brief Determines the winner based on game rules
         * Compares CEO trust, reputation, and money scores
         *
         * @return std::shared_ptr<Player> Pointer to the winning player
         */
        std::shared_ptr<Player> determineWinner() const;

    private:
        std::vector<std::shared_ptr<Player>>
            players_;                   ///< All players in the game
        std::unique_ptr<Stack> stack_;  ///< Card deck and discard pile
        bool isEnd_ = false;            ///< Game end condition flag
        std::queue<std::shared_ptr<Player>>
            playersQueue_;  ///< Current turn order
};

#endif // INCLUDE_GAME_H
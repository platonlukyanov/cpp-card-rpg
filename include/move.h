/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#pragma once

#include <memory>

#include "card.h"
#include "player.h"

class LeverageCard;

/**
 * @brief Represents a player's action in the game
 *
 * The Move class encapsulates a single player action:
 * - Playing a card
 * - Trading a card
 * - Using leverage
 * - Declining an action
 *
 * Moves can be accepted or declined by other players
 * when they involve interaction.
 */
class Move {
    public:
        /**
         * @brief Creates a new move
         *
         * @param actor Player making the move
         * @param card Card involved in the move
         */
        Move(Player& actor, std::unique_ptr<Card> card);
        ~Move();

        /**
         * @brief Returns the player making the move
         *
         * @return Player& Reference to the acting player
         */
        Player& getActor() const;

        /**
         * @brief Returns the card involved in the move
         *
         * @return Card* Pointer to the card
         */
        Card* getCard() const;

        /**
         * @brief Checks if the move can be accepted
         * Some moves (like playing action cards) cannot be accepted
         *
         * @return true if move can be accepted
         */
        bool isAbleToAccept() const;

        /**
         * @brief Accepts the move
         * Called when another player accepts the move
         */
        void accept();
        /**
         * @brief Trades the card for a specific price
         * Called when another player offers to trade the card
         * @param price Price to trade the card for
         * @param buyer Player offering the trade
         */
        void trade(int price, Player& buyer);
        /**
         * @brief Declines the move
         * Called when another player declines any sort of action to the move
         */
        void decline();

    private:
        Player& actor_;               ///< Player making the move
        std::unique_ptr<Card> card_;  ///< Card involved in the move
        bool hasPlayed_;
};
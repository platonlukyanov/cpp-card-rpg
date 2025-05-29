/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#ifndef INCLUDE_PLAYER_HAND_H
#define INCLUDE_PLAYER_HAND_H

#include <memory>
#include <vector>

#include "card.h"
#include "leverage_card.h"

/**
 * @brief Manages a player's collection of cards
 *
 * The PlayerHand class handles all card-related operations for a player:
 * - Storing cards in hand
 * - Playing cards
 * - Managing leverage cards separately
 * - Tracking card positions
 */
class PlayerHand {
    public:
        /**
         * @brief Creates a new empty hand
         */
        PlayerHand();
        ~PlayerHand();

        /**
         * @brief Returns all cards in the hand in a moment
         * @return const std::vector<std::shared_ptr<Card>> Vector of cards
         */
        const std::vector<std::shared_ptr<Card>> getCards() const;
        /**
         * @brief Adds a card to the player's hand
         * @param card Card to add
         */
        void addCard(std::shared_ptr<Card> card);
        /**
         * @brief Plays a card from the hand and returns it
         * @param index Position of card to play
         * @return std::shared_ptr<Card>
         */
        std::shared_ptr<Card> playCard(int index);
        /**
         * @brief Returns all leverage cards in the hand
         * @return const std::vector<std::shared_ptr<LeverageCard>> Vector of
         * leverage cards
         */
        const std::vector<std::shared_ptr<LeverageCard>> getLeverageCards()
            const;

    private:
        std::vector<std::shared_ptr<Card>> cards_;  ///< All cards in hand
        std::vector<std::shared_ptr<LeverageCard>>
            leverageCards_;  ///< Only leverage cards
};

#endif  // INCLUDE_PLAYER_HAND_H
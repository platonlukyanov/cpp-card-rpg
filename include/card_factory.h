/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#ifndef INCLUDE_CARD_FACTORY_H
#define INCLUDE_CARD_FACTORY_H

#include <memory>

#include "action_card.h"
#include "card.h"
#include "character_card.h"
#include "end_card.h"
#include "leverage_card.h"

/**
 * @brief Factory class for creating different types of cards
 *
 * The CardFactory handles the creation of all card types:
 * - Character cards with department-specific stats
 * - Action cards with various effects
 * - Leverage cards for player interaction
 * - End card for game conclusion
 *
 * Each card type has specific parameters and effects
 * that are set during creation.
 */
class CardFactory {
    public:
        /**
         * @brief Creates a card based on its name
         *
         * @param cardName Name of the card to create
         * @param id Unique identifier for the card
         * @return std::unique_ptr<Card> Created card, or nullptr if name is
         * invalid
         */
        static std::unique_ptr<Card> createCard(const std::string& cardName,
                                                int id);

    private:
        /**
         * @brief Creates a character card with specific stats
         *
         * @param name Character name and role
         * @param id Unique identifier
         * @return std::unique_ptr<CharacterCard> Created character card
         */
        static std::unique_ptr<CharacterCard> createCharacterCard(
            const std::string& name, int id);

        /**
         * @brief Creates an action card with specific effects
         *
         * @param name Action name
         * @param id Unique identifier
         * @return std::unique_ptr<ActionCard> Created action card
         */
        static std::unique_ptr<ActionCard> createActionCard(
            const std::string& name, int id);

        /**
         * @brief Creates a leverage card with specific damage values
         *
         * @param name Leverage name
         * @param id Unique identifier
         * @return std::unique_ptr<LeverageCard> Created leverage card
         */
        static std::unique_ptr<LeverageCard> createLeverageCard(
            const std::string& name, int id);

        /**
         * @brief Creates the end card
         *
         * @param id Unique identifier
         * @return std::unique_ptr<EndCard> Created end card
         */
        static std::unique_ptr<EndCard> createEndCard(int id);
};

#endif  // INCLUDE_CARD_FACTORY_H
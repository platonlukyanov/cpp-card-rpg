/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#ifndef INCLUDE_CHARACTER_CARD_H
#define INCLUDE_CHARACTER_CARD_H

#include <string>

#include "card.h"
#include "player.h"

/**
 * @brief Represents a character card that can become a player's ally
 *
 * Character cards represent employees from different departments that can
 * become allies to players. Each character has their own reputation and
 * money values that affect the player's stats when taken as an ally.
 *
 * Characters can only be taken as allies by players from the same department.
 * When taken as an ally, the player gains 10% of the character's reputation
 * and trust values.
 */
class CharacterCard : public Card {
    public:
        /**
         * @brief Creates a new character card
         *
         * @param id Unique identifier for the card
         * @param name Character's name and role
         * @param reputation Character's reputation value (0-100)
         * @param money Character's money value (0-100)
         * @param department Character's department (development, finance,
         * legal, sales)
         */
        CharacterCard(int id, const std::string& name, int reputation,
                      int money, const std::string& department);
        ~CharacterCard() override = default;

        /**
         * @brief Checks if the character can become an ally
         * Character can only be taken by players from the same department
         *
         * @param player The player attempting to take the character as ally
         * @return true if player is from the same department
         */
        bool isPossibleToPlay(const Player& player) const override;

        /**
         * @brief Makes the character an ally of the player
         * Player gains 10% of character's reputation and trust
         *
         * @param player The player taking the character as ally
         */
        void execute(Player& player) override;

        /**
         * @brief Returns the character's reputation value
         * Used to calculate bonus when taken as ally
         *
         * @return int Reputation value (0-100)
         */
        int getReputation() const;

        /**
         * @brief Returns the character's money value
         * Used for trading and scoring
         *
         * @return int Money value (0-100)
         */
        int getMoney() const;

        /**
         * @brief Returns the character's department
         * Used to check if player can take character as ally
         *
         * @return const std::string& Department name
         */
        const std::string& getDepartment() const;

    private:
        int reputation_;          ///< Character's reputation value (0-100)
        int money_;               ///< Character's money value (0-100)
        std::string department_;  ///< Character's department name
};

#endif  // INCLUDE_CHARACTER_CARD_H
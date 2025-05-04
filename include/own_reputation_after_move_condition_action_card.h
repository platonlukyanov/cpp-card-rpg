/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#pragma once
#include "action_card.h"
#include "player.h"

/**
 * @brief Action card that requires a minimum reputation level after a move
 *
 * This class represents a special type of action card that can only be played
 * if the player has a certain minimum reputation level after their move.
 * When played, the card affects the player's reputation and money.
 */
class OwnReputationAfterMoveConditionActionCard : public ActionCard {
    public:
        /**
         * @brief Creates a new action card with reputation condition
         *
         * @param id Unique identifier for the card
         * @param name Display name of the card
         * @param reputation Impact on player's reputation
         * @param money Impact on player's money
         * @param minReputation Minimum required reputation level to play the
         * card
         */
        OwnReputationAfterMoveConditionActionCard(int id,
                                                  const std::string& name,
                                                  int reputation, int money,
                                                  int minReputation);

        /**
         * @brief Gets the minimum required reputation level
         *
         * @return int Minimum reputation level required to play the card
         */
        int getMinReputation() const;

        /**
         * @brief Checks if the card can be played by the player
         *
         * Verifies if the player meets the minimum reputation requirement
         * after their move
         *
         * @param player The player attempting to play the card
         * @return true if all conditions are met
         */
        bool isPossibleToPlay(const Player& player) const override;

        /**
         * @brief Applies the card's effect to the player
         *
         * Modifies player's stats (reputation, money) according
         * to the card's parameters
         *
         * @param player The player to apply the effect to
         */
        void execute(Player& player) override;

    private:
        int minReputation_;  ///< Minimum required reputation level to play the
                             ///< card
};
/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#pragma once
#include "action_card.h"
#include "player.h"

/**
 * @brief Action card that requires a minimum reputation level for an ally
 *
 * This class represents a special type of action card that can only be played
 * if the player has an ally with a certain minimum reputation level. When
 * successfully played, the card increases the player's reputation.
 */
class AllyReputationConditionActionCard : public ActionCard {
    public:
        /** @brief Creates a new action card with ally reputation condition
         *
         * @param id Unique identifier for the card
         * @param name Display name of the card
         * @param reputation Impact on player's reputation
         * @param money Impact on player's money
         * @param minAllyReputation Minimum required reputation level for an
         * ally
         */
        AllyReputationConditionActionCard(int id, const std::string& name,
                                          int reputation, int money,
                                          int minAllyReputation);

        /**
         * @brief Gets the minimum required reputation level
         * @return int Minimum reputation level required for an ally
         */
        int getMinAllyReputation() const;
        /**
         * @brief Checks if the card can be played by the player
         *
         * Verifies if the player has an ally with the required reputation level
         *
         * @param player
         * @return true If all conditions are met
         * @return false  If no ally meets the condition
         */
        bool isPossibleToPlay(const Player& player) const override;
        /**
         * @brief Applies the card's effect to the player
         *
         * Modifies player's stats (reputation, money, trust) according
         * to the card's parameters
         *
         * @param player The player to apply the effect to
         */
        void execute(Player& player) override;

    private:
        int minAllyReputation_;
};
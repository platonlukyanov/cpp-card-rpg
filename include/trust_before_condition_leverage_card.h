/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#ifndef INCLUDE_TRUST_BEFORE_CONDITION_LEVERAGE_CARD_H
#define INCLUDE_TRUST_BEFORE_CONDITION_LEVERAGE_CARD_H
#include "leverage_card.h"
#include "player.h"

/**
 * @brief Leverage card that requires a minimum trust level to be used
 *
 * This class represents a special type of leverage card that can only be used
 * if the player has a certain minimum trust level. When successfully used,
 * the card affects the player's reputation, money, and trust.
 */
class TrustBeforeConditionLeverageCard : public LeverageCard {
    public:
        /**
         * @brief Creates a new leverage card with trust condition
         *
         * @param id Unique identifier for the card
         * @param name Display name of the card
         * @param reputation Impact on player's reputation
         * @param money Impact on player's money
         * @param trust Impact on player's trust
         * @param minTrust Minimum required trust level to use the card
         */
        TrustBeforeConditionLeverageCard(int id, const std::string& name,
                                         int reputation, int money, int trust,
                                         int minTrust);

        /**
         * @brief Gets the minimum required trust level
         *
         * @return int Minimum trust level required to use the card
         */
        int getMinTrust() const;

        /**
         * @brief Checks if the card can be played by the player
         *
         * Verifies if the player meets the minimum trust requirement
         *
         * @param player The player attempting to play the card
         * @return true if all conditions are met
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
        void executeOnPlayer(Player& player) override;

    private:
        int minTrust_;  ///< Minimum required trust level to use the card
};
#endif  // INCLUDE_TRUST_BEFORE_CONDITION_LEVERAGE_CARD_H
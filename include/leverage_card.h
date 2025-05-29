/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#ifndef INCLUDE_LEVERAGE_CARD_H
#define INCLUDE_LEVERAGE_CARD_H

#include "card.h"

/**
 * @brief Special card that can be used against other players
 *
 * Leverage cards represent sensitive information or actions that can be used
 * to damage another player's stats. Unlike action cards, leverage cards:
 * - Are kept hidden in player's hand until used
 * - Can target any player
 * - Can be used for negotiation (player can offer not to use the card)
 * - Deal damage to reputation, money and trust when used
 */
class LeverageCard : public Card {
    public:
        /**
         * @brief Creates a new leverage card
         *
         * @param id Unique card identifier
         * @param name Card name describing the leverage
         * @param reputationDamage Damage to reputation (-100 to +100)
         * @param moneyDamage Damage to money (-100 to +100)
         * @param trustDamage Damage to trust (-100 to +100)
         */
        LeverageCard(int id, const std::string& name, int reputationDamage,
                     int moneyDamage, int trustDamage);
        ~LeverageCard() override = default;

        /**
         * @brief Checks if the card can be played
         * Leverage cards can always be played, as they target other players
         *
         * @param player Player attempting to play the card
         * @return true Always returns true
         */
        bool isPossibleToPlay(const Player& player) const override;

        /**
         * @brief Adds the card to player's hand for later use
         * Unlike other cards, leverage cards are stored until needed
         *
         * @param player Player receiving the card
         */
        void execute(Player& player) override;

        /**
         * @brief Applies the card's damage effects to target player
         * Reduces target player's stats based on damage values
         *
         * @param player Player being targeted by the leverage
         */
        virtual void executeOnPlayer(Player& player);

        /**
         * @brief Returns the reputation damage value
         * @return int Damage amount (-100 to +100)
         */
        int getReputationDamage() const;

        /**
         * @brief Returns the money damage value
         * @return int Damage amount (-100 to +100)
         */
        int getMoneyDamage() const;

        /**
         * @brief Returns the trust damage value
         * @return int Damage amount (-100 to +100)
         */
        int getTrustDamage() const;

        /**
         * @brief Removes the card from player's hand after use
         * Called after the leverage has been used against a target
         *
         * @param player Player who used the leverage
         */
        void deactivate(Player& player);

    private:
        int reputationDamage_;  ///< Amount of reputation damage
        int moneyDamage_;       ///< Amount of money damage
        int trustDamage_;       ///< Amount of trust damage
        int indexInHand_;       ///< Card's position in player's hand

    protected:
        /**
         * @brief Applies reputation damage to target
         * @param player Target player
         */
        void executeReputationDamage(Player& player);

        /**
         * @brief Applies money damage to target
         * @param player Target player
         */
        void executeMoneyDamage(Player& player);

        /**
         * @brief Applies trust damage to target
         * @param player Target player
         */
        void executeTrustDamage(Player& player);

        /**
         * @brief Executes any additional effects before damage
         * Can be overridden by derived classes
         *
         * @param player Target player
         */
        virtual void executePreeffects(Player& player);
};

#endif // INCLUDE_LEVERAGE_CARD_H
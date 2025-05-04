/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#pragma once

#include "card.h"

/**
 * @brief Action card with immediate effects on player stats
 * 
 * Action cards represent various corporate decisions and actions
 * that can immediately change a player's reputation, money, and trust.
 * Each action can have both positive and negative effects on
 * different characteristics.
 * 
 * A card can only be played if the player has sufficient resources
 * to withstand negative effects (values cannot go below 0).
 */
class ActionCard : public Card {
public:
    /**
     * @brief Creates a new action card
     * 
     * @param id Unique card identifier
     * @param name Action name
     * @param reputationChange Reputation change (-100 to +100)
     * @param moneyChange Money change (-100 to +100)
     * @param trustChange Trust change (-100 to +100)
     */
    ActionCard(int id, const std::string& name, 
               int reputationChange, int moneyChange, int trustChange);
    ~ActionCard() override = default;

    /**
     * @brief Checks if the player can play the card
     * 
     * Card can only be played if after its effects
     * all player stats will remain non-negative
     * 
     * @param player Player attempting to play the card
     * @return true if all stats will remain >= 0
     */
    bool isPossibleToPlay(const Player& player) const override;

    /**
     * @brief Applies card effects to the player
     * 
     * Changes player's reputation, money and trust
     * according to the card's values
     * 
     * @param player Player affected by the card
     */
    void execute(Player& player) override;

    /**
     * @brief Returns the reputation change
     * @return int Change amount (-100 to +100)
     */
    int getReputationChange() const;

    /**
     * @brief Returns the money change
     * @return int Change amount (-100 to +100)
     */
    int getMoneyChange() const;

    /**
     * @brief Returns the trust change
     * @return int Change amount (-100 to +100)
     */
    int getTrustChange() const;

protected:
    int reputationChange_; ///< Player's reputation change
    int moneyChange_;      ///< Player's money change
    int trustChange_;      ///< Player's trust change
}; 
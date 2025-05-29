/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#ifndef INCLUDE_SAME_DEPARTMENT_CONDITION_ACTION_CARD_H
#define INCLUDE_SAME_DEPARTMENT_CONDITION_ACTION_CARD_H
#include "action_card.h"
#include "player.h"

/**
 * @brief Action card that requires the player to be in a specific department
 *
 * This class represents a special type of action card that can only be played
 * if the player belongs to a specific department. When played, the card affects
 * the player's reputation and money.
 */
class SameDepartmentConditionActionCard : public ActionCard {
    public:
        /**
         * @brief Creates a new action card with department condition
         *
         * @param id Unique identifier for the card
         * @param name Display name of the card
         * @param reputation Impact on player's reputation
         * @param money Impact on player's money
         * @param department Required department for the player to play this
         * card
         */
        SameDepartmentConditionActionCard(int id, const std::string& name,
                                          int reputation, int money,
                                          const std::string& department);

        /**
         * @brief Gets the required department for this card
         *
         * @return const std::string& Department name required to play the card
         */
        const std::string& getDepartment() const;

        /**
         * @brief Checks if the card can be played by the player
         *
         * Verifies if the player belongs to the required department
         *
         * @param player The player attempting to play the card
         * @return true if the player is in the required department
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
        std::string department_;  ///< Department required to play this card
};
#endif  // INCLUDE_SAME_DEPARTMENT_CONDITION_ACTION_CARD_H
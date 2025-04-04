#include "own_reputation_after_move_condition_action_card.h"

OwnReputationAfterMoveConditionActionCard::OwnReputationAfterMoveConditionActionCard(
    int id, const std::string& name, int reputation, int money, int minReputation)
    : ActionCard(id, name, reputation, money, 0)
    , minReputation_(minReputation) {}

int OwnReputationAfterMoveConditionActionCard::getMinReputation() const {
    return minReputation_;
}

bool OwnReputationAfterMoveConditionActionCard::isPossibleToPlay(const Player& player) const {
    return (player.getReputation() + getReputationChange() / 10) >= minReputation_;
}

void OwnReputationAfterMoveConditionActionCard::execute(Player& player) {
    player.gainReputation(getReputationChange() / 10);
    player.gainMoney(getMoneyChange());
} 
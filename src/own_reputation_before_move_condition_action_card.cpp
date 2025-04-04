#include "own_reputation_before_move_condition_action_card.h"

OwnReputationBeforeMoveConditionActionCard::OwnReputationBeforeMoveConditionActionCard(
    int id, const std::string& name, int reputation, int money, int minReputation)
    : ActionCard(id, name, reputation, money, 0)
    , minReputation_(minReputation) {}

int OwnReputationBeforeMoveConditionActionCard::getMinReputation() const {
    return minReputation_;
}

bool OwnReputationBeforeMoveConditionActionCard::isPossibleToPlay(const Player& player) const {
    return player.getReputation() >= minReputation_;
}

void OwnReputationBeforeMoveConditionActionCard::execute(Player& player) {
    player.gainReputation(getReputationChange() / 10);
    player.gainMoney(getMoneyChange());
} 
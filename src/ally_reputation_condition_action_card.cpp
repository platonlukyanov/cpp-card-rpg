#include "ally_reputation_condition_action_card.h"

AllyReputationConditionActionCard::AllyReputationConditionActionCard(
    int id, const std::string& name, int reputation, int money, int minAllyReputation)
    : ActionCard(id, name, reputation, money, 10)
    , minAllyReputation_(minAllyReputation) {}

int AllyReputationConditionActionCard::getMinAllyReputation() const {
    return minAllyReputation_;
}

bool AllyReputationConditionActionCard::isPossibleToPlay(const Player& player) const {
    return player.hasAllyWithReputationAbove(minAllyReputation_);
}

void AllyReputationConditionActionCard::execute(Player& player) {
    player.gainReputation(getReputationChange() / 10);
    player.gainMoney(getMoneyChange());
    player.gainTrust(getTrustChange());
} 
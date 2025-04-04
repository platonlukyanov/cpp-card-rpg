#include "same_department_condition_action_card.h"

SameDepartmentConditionActionCard::SameDepartmentConditionActionCard(
    int id, const std::string& name, int reputation, int money, const std::string& department)
    : ActionCard(id, name, reputation, money, 0)
    , department_(department) {}

const std::string& SameDepartmentConditionActionCard::getDepartment() const {
    return department_;
}

bool SameDepartmentConditionActionCard::isPossibleToPlay(const Player& player) const {
    return player.getDepartment() == department_;
}

void SameDepartmentConditionActionCard::execute(Player& player) {
    player.gainReputation(getReputationChange() / 10);
    player.gainMoney(getMoneyChange());
} 
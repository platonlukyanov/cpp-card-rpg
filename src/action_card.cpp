#include "action_card.h"
#include "player.h"

ActionCard::ActionCard(int id, const std::string& name,
                      int reputationChange, int moneyChange, int trustChange)
    : Card(id, Type::ACTION, name),
      reputationChange_(reputationChange),
      moneyChange_(moneyChange),
      trustChange_(trustChange) {}

bool ActionCard::isPossibleToPlay(const Player& player) const {
    // По умолчанию карту действия можно сыграть
    return true;
}

void ActionCard::execute(Player& player) {
    player.gainReputation(reputationChange_);
    player.gainMoney(moneyChange_);
    player.gainTrust(trustChange_);
}

int ActionCard::getReputationChange() const {
    return reputationChange_;
}

int ActionCard::getMoneyChange() const {
    return moneyChange_;
}

int ActionCard::getTrustChange() const {
    return trustChange_;
} 
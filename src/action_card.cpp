#include "action_card.h"
#include "player.h"

ActionCard::ActionCard(int id, const std::string& name,
                      int reputationChange, int moneyChange, int trustChange)
    : Card(id, Type::ACTION, name),
      reputationChange_(reputationChange),
      moneyChange_(moneyChange),
      trustChange_(trustChange) {}

bool ActionCard::isPossibleToPlay(const Player& player) const {
    // by default, action card can be played
    bool canPlayDueToReputation = player.getReputation() >= -reputationChange_;
    bool canPlayDueToMoney = player.getMoney() >= -moneyChange_;
    bool canPlayDueToTrust = player.getTrust() >= -trustChange_;
    return canPlayDueToReputation && canPlayDueToMoney && canPlayDueToTrust;
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
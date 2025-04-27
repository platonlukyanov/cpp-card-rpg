#include "trust_before_condition_leverage_card.h"

TrustBeforeConditionLeverageCard::TrustBeforeConditionLeverageCard(
    int id, const std::string& name, int reputationDamage, int moneyDamage, int trustDamage, int minTrust)
    : LeverageCard(id, name, reputationDamage, moneyDamage, trustDamage)
    , minTrust_(minTrust) {}

int TrustBeforeConditionLeverageCard::getMinTrust() const {
    return minTrust_;
}

bool TrustBeforeConditionLeverageCard::isPossibleToPlay(const Player& player) const {
    return true;  // Карта рычага всегда может быть сыграна
}

void TrustBeforeConditionLeverageCard::executeOnPlayer(Player& player) {
    executePreeffects(player);
    if (player.getTrust() < getMinTrust()) {
        executeTrustDamage(player);
    }
    executeMoneyDamage(player);
    executeReputationDamage(player);
} 
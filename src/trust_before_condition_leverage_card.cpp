/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include "trust_before_condition_leverage_card.h"

TrustBeforeConditionLeverageCard::TrustBeforeConditionLeverageCard(
    int id, const std::string& name, int reputationDamage, int moneyDamage,
    int trustDamage, int minTrust)
    : LeverageCard(id, name, reputationDamage, moneyDamage, trustDamage),
      minTrust_(minTrust) {
}

int TrustBeforeConditionLeverageCard::getMinTrust() const {
    return minTrust_;
}

bool TrustBeforeConditionLeverageCard::isPossibleToPlay(
    const Player& player) const {
    return true;  // Leverage cards can always be played
}

void TrustBeforeConditionLeverageCard::executeOnPlayer(Player& player) {
    executePreeffects(player);
    if (player.getTrust() < getMinTrust()) {
        executeTrustDamage(player);
    }
    executeMoneyDamage(player);
    executeReputationDamage(player);
}
#include "leverage_card.h"
#include "player.h"

LeverageCard::LeverageCard(int id, const std::string& name,
                          int reputationDamage, int moneyDamage, int trustDamage)
    : Card(id, Type::LEVERAGE, name),
      reputationDamage_(reputationDamage),
      moneyDamage_(moneyDamage),
      trustDamage_(trustDamage) {}

bool LeverageCard::isPossibleToPlay(const Player& player) const {
    // По умолчанию карту рычага можно сыграть
    return true;
}

void LeverageCard::executeReputationDamage(Player& player) {
    if (reputationDamage_ < 0) {
        player.loseReputation(-reputationDamage_);
    } else {
        player.gainReputation(reputationDamage_);
    }
}

void LeverageCard::executeMoneyDamage(Player& player) {
    if (moneyDamage_ < 0) {
        player.loseMoney(-moneyDamage_);
    } else {
        player.gainMoney(moneyDamage_);
    }
}

void LeverageCard::executeTrustDamage(Player& player) {
    if (trustDamage_ < 0) {
        player.loseTrust(-trustDamage_);
    } else {
        player.gainTrust(trustDamage_);
    }
}

void LeverageCard::executePreeffects(Player& player) {}

void LeverageCard::execute(Player& player) {
    executePreeffects(player);
    executeMoneyDamage(player);
    executeReputationDamage(player);
    executeTrustDamage(player); 
}

int LeverageCard::getReputationDamage() const {
    return reputationDamage_;
}

int LeverageCard::getMoneyDamage() const {
    return moneyDamage_;
}

int LeverageCard::getTrustDamage() const {
    return trustDamage_;
} 
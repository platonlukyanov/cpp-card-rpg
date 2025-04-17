#pragma once
#include "leverage_card.h"
#include "player.h"

class TrustBeforeConditionLeverageCard : public LeverageCard {
public:
    TrustBeforeConditionLeverageCard(int id,
                const std::string& name,
                int reputation,
                int money,
                int trust,
                int minTrust);
    
    int getMinTrust() const;
    bool isPossibleToPlay(const Player& player) const override;
    void execute(Player& player) override;

private:
    int minTrust_;
}; 
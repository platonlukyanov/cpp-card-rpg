#pragma once

#include "card.h"

class ActionCard : public Card {
public:
    ActionCard(int id, const std::string& name, 
               int reputationChange, int moneyChange, int trustChange);
    ~ActionCard() override = default;

    bool isPossibleToPlay(const Player& player) const override;
    void execute(Player& player) override;

    int getReputationChange() const;
    int getMoneyChange() const;
    int getTrustChange() const;

protected:
    int reputationChange_;
    int moneyChange_;
    int trustChange_;
}; 
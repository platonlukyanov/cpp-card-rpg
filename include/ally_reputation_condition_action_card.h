#pragma once
#include "action_card.h"
#include "player.h"

class AllyReputationConditionActionCard : public ActionCard {
public:
    AllyReputationConditionActionCard(int id, const std::string& name, int reputation, int money, int minAllyReputation);
    
    int getMinAllyReputation() const;
    bool isPossibleToPlay(const Player& player) const override;
    void execute(Player& player) override;

private:
    int minAllyReputation_;
}; 
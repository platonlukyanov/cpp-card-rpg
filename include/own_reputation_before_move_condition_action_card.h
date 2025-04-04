#pragma once
#include "action_card.h"
#include "player.h"

class OwnReputationBeforeMoveConditionActionCard : public ActionCard {
public:
    OwnReputationBeforeMoveConditionActionCard(int id, const std::string& name, int reputation, int money, int minReputation);
    
    int getMinReputation() const;
    bool isPossibleToPlay(const Player& player) const override;
    void execute(Player& player) override;

private:
    int minReputation_;
}; 
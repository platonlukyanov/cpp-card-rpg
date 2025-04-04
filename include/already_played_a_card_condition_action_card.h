#pragma once
#include "action_card.h"

class AlreadyPlayedACardConditionActionCard : public ActionCard {
public:
    AlreadyPlayedACardConditionActionCard(int id, const std::string& name, int reputation, int money, std::unique_ptr<Card> forbiddenCard);
    
    const Card* getForbiddenCard() const;
    bool isPossibleToPlay(const Player& player) const override;
    void execute(Player& player) override;

private:
    std::unique_ptr<Card> forbiddenCard_;
}; 
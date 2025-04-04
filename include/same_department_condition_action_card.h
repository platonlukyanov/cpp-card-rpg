#pragma once
#include "action_card.h"
#include "player.h"

class SameDepartmentConditionActionCard : public ActionCard {
public:
    SameDepartmentConditionActionCard(int id, const std::string& name, int reputation, int money, const std::string& department);
    
    const std::string& getDepartment() const;
    bool isPossibleToPlay(const Player& player) const override;
    void execute(Player& player) override;

private:
    std::string department_;
}; 
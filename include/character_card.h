#pragma once

#include "card.h"
#include "player.h"
#include <string>

class CharacterCard : public Card {
public:
    CharacterCard(int id, const std::string& name, int reputation, int money, const std::string& department);
    ~CharacterCard() override = default;

    bool isPossibleToPlay(const Player& player) const override;
    void execute(Player& player) override;

    int getReputation() const;
    int getMoney() const;
    const std::string& getDepartment() const;

private:
    int reputation_;
    int money_;
    std::string department_;
}; 
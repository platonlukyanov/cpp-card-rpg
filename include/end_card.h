#pragma once

#include "card.h"

class EndCard : public Card {
public:
    EndCard(int id);
    ~EndCard() override = default;

    bool isPossibleToPlay(const Player& player) const override;
    void execute(Player& player) override;
}; 
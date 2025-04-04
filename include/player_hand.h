#pragma once

#include <vector>
#include "card.h"

class PlayerHand {
public:
    PlayerHand();
    ~PlayerHand();

    const std::vector<Card*>& getCards() const;
    void addCard(Card* card);
    Card* playCard(int index);
    const std::vector<Card*>& getLeverageCards() const;

private:
    std::vector<Card*> cards_;
}; 
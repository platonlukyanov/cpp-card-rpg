#pragma once

#include <vector>
#include "card.h"
#include <memory>

class PlayerHand {
public:
    PlayerHand();
    ~PlayerHand();

    const std::vector<std::shared_ptr<Card>> getCards() const;
    void addCard(std::shared_ptr<Card> card);
    std::shared_ptr<Card> playCard(int index);
    const std::vector<std::shared_ptr<Card>> getLeverageCards() const;

private:
    std::vector<std::shared_ptr<Card>> cards_;
}; 
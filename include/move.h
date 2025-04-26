#pragma once

#include "player.h"
#include "card.h"
#include <memory>

class LeverageCard;

class Move {
public:
    Move(Player& actor, std::unique_ptr<Card> card);
    ~Move();

    Player& getActor() const;
    bool isAbleToAccept() const;
    void accept();
    void trade(int price, Player& buyer);
    void decline();
    void useLeverage(LeverageCard& card, Player& target);
    Card* getCard() const;

private:
    Player& actor_;
    std::unique_ptr<Card> card_;
    bool hasPlayed_;
}; 
#pragma once

#include <vector>
#include <memory>
#include "card.h"

class Stack {
public:
    Stack();
    ~Stack();

    bool isEmpty() const;
    std::unique_ptr<Card> drawCard();
    Card* popCard();
    void pushCard(std::unique_ptr<Card> card);
    void shuffle();
    void fetchPlayersCards(int count);
    Card* peekCard() const;

private:
    std::vector<Card*> cards_;
}; 
#pragma once

#include <vector>
#include <memory>
#include "card.h"
#include "character_card.h"

class Stack {
public:
    Stack();
    ~Stack();

    bool isEmpty() const;
    std::unique_ptr<Card> drawCard();
    Card* popCard();
    void pushCard(std::unique_ptr<Card> card);
    void insertCard(std::unique_ptr<Card> card, int index);
    void shuffle();
    std::vector<std::unique_ptr<CharacterCard>> fetchPlayersCards(int count);
    Card* peekCard() const;

private:
    std::vector<Card*> cards_;
}; 
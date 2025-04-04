#include "stack.h"
#include <algorithm>
#include <random>
#include <chrono>

Stack::Stack() {}

Stack::~Stack() {
    for (auto card : cards_) {
        delete card;
    }
}

bool Stack::isEmpty() const {
    return cards_.empty();
}

std::unique_ptr<Card> Stack::drawCard() {
    if (cards_.empty()) {
        return nullptr;
    }

    auto card = cards_.back();
    cards_.pop_back();
    return std::unique_ptr<Card>(card);
}

Card* Stack::popCard() {
    if (cards_.empty()) {
        return nullptr;
    }

    auto card = cards_.back();
    cards_.pop_back();
    return card;
}

void Stack::pushCard(std::unique_ptr<Card> card) {
    if (card) {
        auto rawCard = card.release();
        if (rawCard) {
            cards_.push_back(rawCard);
        }
    }
}

void Stack::shuffle() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(cards_.begin(), cards_.end(), gen);
}

void Stack::fetchPlayersCards(int count) {
    // TODO: Implement fetching cards for players
}

Card* Stack::peekCard() const {
    if (cards_.empty()) {
        return nullptr;
    }
    return cards_.back();
} 
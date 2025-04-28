#include "stack.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>
#include "character_card.h"

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

void Stack::insertCard(std::unique_ptr<Card> card, int index) {
    if (!card) {
        return;
    }
    auto rawCard = card.release();
    if (rawCard) {
        cards_.insert(cards_.begin() + index, rawCard);
    }
}

void Stack::shuffle() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(cards_.begin(), cards_.end(), gen);
}

std::vector<std::unique_ptr<CharacterCard>> Stack::fetchPlayersCards(int count) {
    std::vector<std::unique_ptr<CharacterCard>> cards;
    std::vector<std::unique_ptr<Card>> cardsToReturnBack;

    while (cards.size() < static_cast<size_t>(count)) {
        std::unique_ptr<Card> card = drawCard();

        if (card->getType() == Card::Type::CHARACTER) {
            cards.emplace_back(std::unique_ptr<CharacterCard>(
                static_cast<CharacterCard*>(card.release())
            ));
        } else {
            cardsToReturnBack.emplace_back(std::move(card));
        }
    }

    for (auto& card : cardsToReturnBack) {
        pushCard(std::move(card));
    }

    return cards;
}

Card* Stack::peekCard() const {
    if (cards_.empty()) {
        return nullptr;
    }
    return cards_.back();
} 
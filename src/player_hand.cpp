#include "player_hand.h"

PlayerHand::PlayerHand() {}

PlayerHand::~PlayerHand() {
    for (auto card : cards_) {
        delete card;
    }
}

const std::vector<Card*>& PlayerHand::getCards() const {
    return cards_;
}

void PlayerHand::addCard(Card* card) {
    cards_.push_back(card);
}

Card* PlayerHand::playCard(int index) {
    if (index < 0 || index >= static_cast<int>(cards_.size())) {
        return nullptr;
    }
    Card* card = cards_[index];
    cards_.erase(cards_.begin() + index);
    return card;
}

const std::vector<Card*>& PlayerHand::getLeverageCards() const {
    static std::vector<Card*> leverageCards;
    leverageCards.clear();
    for (auto card : cards_) {
        if (card->getType() == Card::Type::LEVERAGE) {
            leverageCards.push_back(card);
        }
    }
    return leverageCards;
} 
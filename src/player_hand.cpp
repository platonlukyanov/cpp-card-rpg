/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include "player_hand.h"

#include <memory>

PlayerHand::PlayerHand() {
}

PlayerHand::~PlayerHand() {
    cards_.clear();
}

const std::vector<std::shared_ptr<Card>> PlayerHand::getCards() const {
    return cards_;
}

void PlayerHand::addCard(std::shared_ptr<Card> card) {
    cards_.push_back(card);
}

std::shared_ptr<Card> PlayerHand::playCard(int index) {
    if (index < 0 || index >= static_cast<int>(cards_.size())) {
        return nullptr;
    }
    std::shared_ptr<Card> card = cards_[index];
    cards_.erase(cards_.begin() + index);
    return card;
}

const std::vector<std::shared_ptr<LeverageCard>> PlayerHand::getLeverageCards() const {
    static std::vector<std::shared_ptr<LeverageCard>> leverageCards;
    leverageCards.clear();
    for (auto card : cards_) {
        if (card->getType() == Card::Type::LEVERAGE) {
            std::shared_ptr<LeverageCard> leverageCard = std::dynamic_pointer_cast<LeverageCard>(card);
            leverageCards.push_back(leverageCard);
        }
    }
    return leverageCards;
}

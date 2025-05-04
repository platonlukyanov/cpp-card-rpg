/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include "move.h"
#include "leverage_card.h"

Move::Move(Player& actor, std::unique_ptr<Card> card)
    : actor_(actor), card_(std::move(card)), hasPlayed_(false) {}

Move::~Move() = default;

Player& Move::getActor() const {
    return actor_;
}

bool Move::isAbleToAccept() const {
    return !hasPlayed_ && card_->isPossibleToPlay(actor_);
}

void Move::accept() {
    if (!isAbleToAccept()) {
        return;
    }
    
    card_->execute(actor_);
    hasPlayed_ = true;
}

void Move::trade(int price, Player& buyer) {
    if (!card_->isPossibleToPlay(buyer)) {
        return;
    }
    if (hasPlayed_) {
        return;
    }
    
    buyer.loseMoney(price);
    actor_.gainMoney(price);
    card_->execute(buyer);
    hasPlayed_ = true;
}

void Move::decline() {
    hasPlayed_ = true;
}

Card* Move::getCard() const {
    return card_.get();
}
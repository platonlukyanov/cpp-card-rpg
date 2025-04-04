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
    if (hasPlayed_) {
        return;
    }
    
    buyer.loseMoney(price);
    actor_.gainMoney(price);
    hasPlayed_ = true;
}

void Move::decline() {
    hasPlayed_ = true;
}

void Move::useLeverage(LeverageCard& leverageCard, Player& target) {
    if (hasPlayed_) {
        return;
    }
    
    leverageCard.execute(target);
    hasPlayed_ = true;
} 
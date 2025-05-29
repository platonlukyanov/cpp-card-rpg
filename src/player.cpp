/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include "player.h"

#include "player_hand.h"

Player::Player(const std::string& id, const std::string& secret)
    : id_(id),
      secret_(secret),
      reputation_(0),
      money_(0),
      trust_(10),
      hand_(std::make_shared<PlayerHand>()) {
}

const std::string& Player::getId() const {
    return id_;
}

const std::string& Player::getSecret() const {
    return secret_;
}

int Player::getReputation() const {
    return reputation_;
}

int Player::getMoney() const {
    return money_;
}

int Player::getTrust() const {
    return trust_;
}

const std::string& Player::getPlayerName() const {
    return playerName_;
}

const std::string& Player::getDepartment() const {
    return department_;
}

void Player::loseMoney(int amount) {
    money_ = std::max(0, money_ - amount);
}

void Player::loseReputation(int amount) {
    reputation_ = std::max(0, reputation_ - amount);
}

void Player::loseTrust(int amount) {
    trust_ = std::max(0, trust_ - amount);
}

void Player::gainMoney(int amount) {
    money_ = std::min(100, money_ + amount);
}

void Player::gainReputation(int amount) {
    reputation_ = std::min(100, reputation_ + amount);
}

void Player::gainTrust(int amount) {
    trust_ = std::min(100, trust_ + amount);
}

void Player::setName(const std::string& name) {
    playerName_ = name;
}

void Player::setDepartment(const std::string& department) {
    department_ = department;
}

std::shared_ptr<PlayerHand> Player::getHand() {
    return hand_;
}

const std::vector<Ally>& Player::getAllies() const {
    return allies_;
}

void Player::addAlly(const CharacterCard& card) {
    allies_.emplace_back(card);
}

bool Player::hasAllyFromDepartment(const std::string& department) const {
    for (const auto& ally : allies_) {
        if (ally.getDepartment() == department) {
            return true;
        }
    }
    return false;
}

bool Player::hasAllyWithReputationAbove(int reputation) const {
    for (const auto& ally : allies_) {
        if (ally.getReputation() > reputation) {
            return true;
        }
    }
    return false;
}
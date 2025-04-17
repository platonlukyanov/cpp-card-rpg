#include "character_card.h"

CharacterCard::CharacterCard(int id, const std::string& name, 
                           int reputation, int money, const std::string& department)
    : Card(id, Type::CHARACTER, name),
      reputation_(reputation),
      money_(money),
      department_(department) {}

bool CharacterCard::isPossibleToPlay(const Player& player) const {
    // Персонажа можно взять в союзники, если он из того же отдела
    return player.getDepartment() == department_;
}

void CharacterCard::execute(Player& player) {
    // При взятии персонажа в союзники, игрок получает 10% от его репутации и доверия
    player.gainReputation(reputation_ / 10);
    player.gainTrust(1); // Базовое доверие за союзника (10% oт стандартных 10)
    player.addAlly(*this);
}

int CharacterCard::getReputation() const {
    return reputation_;
}

int CharacterCard::getMoney() const {
    return money_;
}

const std::string& CharacterCard::getDepartment() const {
    return department_;
} 
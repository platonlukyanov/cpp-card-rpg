/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include "character_card.h"

CharacterCard::CharacterCard(int id, const std::string& name, int reputation,
                             int money, const std::string& department)
    : Card(id, Type::CHARACTER, name),
      reputation_(reputation),
      money_(money),
      department_(department) {
}

bool CharacterCard::isPossibleToPlay(const Player& player) const {
    // Character can be taken in allies if it is from the same department
    return player.getDepartment() == department_;
}

void CharacterCard::execute(Player& player) {
    // When taking a character card to an ally, the player gains 10% of the
    // character's reputation and trust
    player.gainReputation(reputation_ / 10);
    player.gainTrust(
        1);  // Base trust for an ally (10% of the character's reputation is 1)
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
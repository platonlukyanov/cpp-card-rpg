/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include "ally.h"

#include "character_card.h"

Ally::Ally(const CharacterCard& card)
    : name_(card.getName()),
      reputation_(card.getReputation()),
      money_(card.getMoney()),
      department_(card.getDepartment()) {
}

const std::string& Ally::getName() const {
    return name_;
}

int Ally::getReputation() const {
    return reputation_;
}

int Ally::getMoney() const {
    return money_;
}

const std::string& Ally::getDepartment() const {
    return department_;
}
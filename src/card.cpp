/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include "card.h"

Card::Card(int id, Type type, const std::string& name)
    : id_(id), type_(type), name_(name) {}

int Card::getId() const {
    return id_;
}

Card::Type Card::getType() const {
    return type_;
}

const std::string& Card::getName() const {
    return name_;
} 
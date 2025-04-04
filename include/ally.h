#pragma once

#include <string>

class CharacterCard;

class Ally {
public:
    Ally(const CharacterCard& card);
    ~Ally() = default;

    const std::string& getName() const;
    int getReputation() const;
    int getMoney() const;
    const std::string& getDepartment() const;

private:
    std::string name_;
    int reputation_;
    int money_;
    std::string department_;
}; 
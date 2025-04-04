#pragma once

#include <string>

class Player;

class Card {
public:
    enum class Type {
        ACTION,
        CHARACTER,
        LEVERAGE,
        END
    };

    Card(int id, Type type, const std::string& name);
    virtual ~Card() = default;

    int getId() const;
    Type getType() const;
    const std::string& getName() const;

    virtual bool isPossibleToPlay(const Player& player) const = 0;
    virtual void execute(Player& player) = 0;

protected:
    int id_;
    Type type_;
    std::string name_;
}; 
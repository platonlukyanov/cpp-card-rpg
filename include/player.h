#pragma once

#include <string>
#include <vector>
#include "card.h"
#include "ally.h"

class PlayerHand;
class CharacterCard;

class Player {
public:
    Player(const std::string& id, const std::string& secret);
    virtual ~Player() = default;

    const std::string& getId() const;
    const std::string& getSecret() const;
    int getReputation() const;
    int getMoney() const;
    int getTrust() const;
    const std::string& getPlayerName() const;
    const std::string& getDepartment() const;

    void loseMoney(int amount);
    void loseReputation(int amount);
    void loseTrust(int amount);
    void gainMoney(int amount);
    void gainReputation(int amount);
    void gainTrust(int amount);
    void setName(const std::string& name);
    void setDepartment(const std::string& department);

    PlayerHand& getHand();
    const std::vector<Ally>& getAllies() const;
    void addAlly(const CharacterCard& card);
    bool hasAllyFromDepartment(const std::string& department) const;
    bool hasAllyWithReputationAbove(int reputation) const;

protected:
    std::string id_;
    std::string secret_;
    std::string playerName_;
    std::string department_;
    int reputation_;
    int money_;
    int trust_;
    PlayerHand* hand_;
    std::vector<Ally> allies_;
}; 
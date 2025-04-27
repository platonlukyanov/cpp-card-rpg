#pragma once

#include "card.h"

class LeverageCard : public Card {
public:
    LeverageCard(int id, const std::string& name,
                 int reputationDamage, int moneyDamage, int trustDamage);
    ~LeverageCard() override = default;

    bool isPossibleToPlay(const Player& player) const override;
    void execute(Player& player) override;
    virtual void executeOnPlayer(Player& player);
    int getReputationDamage() const;
    int getMoneyDamage() const;
    int getTrustDamage() const;

private:
    int reputationDamage_;
    int moneyDamage_;
    int trustDamage_;

protected:
        void executeReputationDamage(Player& player);
        void executeMoneyDamage(Player& player);
        void executeTrustDamage(Player& player);
        virtual void executePreeffects(Player& player);
}; 
#pragma once

#include <memory>
#include "card.h"
#include "character_card.h"
#include "action_card.h"
#include "leverage_card.h"
#include "end_card.h"

class CardFactory {
public:
    static std::unique_ptr<Card> createCard(const std::string& cardName, int id);
    
private:
    static std::unique_ptr<CharacterCard> createCharacterCard(const std::string& name, int id);
    static std::unique_ptr<ActionCard> createActionCard(const std::string& name, int id);
    static std::unique_ptr<LeverageCard> createLeverageCard(const std::string& name, int id);
    static std::unique_ptr<EndCard> createEndCard(int id);
}; 
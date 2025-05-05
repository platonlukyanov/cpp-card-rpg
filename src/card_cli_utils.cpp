/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include <iostream>

#include "action_card.h"
#include "card.h"
#include "character_card.h"
#include "cli_game_utils.h"
#include "leverage_card.h"

void displayCardShort(std::shared_ptr<Card> card) {
    if (!card) return;

    std::cout << card->getName();

    if (card->getType() == Card::Type::LEVERAGE) {
        auto leverageCard = std::dynamic_pointer_cast<LeverageCard>(card);
        std::cout << " (Damage: ";
        printColored(std::to_string(leverageCard->getMoneyDamage()),
                     Color::GREEN);
        std::cout << ", ";
        printColored(std::to_string(leverageCard->getReputationDamage()),
                     Color::RED);
        std::cout << ", ";
        printColored(std::to_string(leverageCard->getTrustDamage()),
                     Color::BLUE);
        std::cout << ")";
    }
    std::cout << std::endl;
}

void displayCard(std::shared_ptr<Card> card) {

    std::cout << card->getName();

    switch (card->getType()) {
        case Card::Type::ACTION: {
            std::shared_ptr<ActionCard> actionCard = std::dynamic_pointer_cast<ActionCard>(card);
            std::cout << " (Action)" << std::endl;
            printStat("Money", actionCard->getMoneyChange(), Color::GREEN);
            printStat("Reputation", actionCard->getReputationChange(),
                      Color::RED);
            printStat("Trust", actionCard->getTrustChange(), Color::BLUE);
            break;
        }
        case Card::Type::CHARACTER: {
            std::shared_ptr<CharacterCard> characterCard = std::dynamic_pointer_cast<CharacterCard>(card);
            std::cout << " (Character)" << std::endl;
            std::cout << " Department: " << characterCard->getDepartment()
                      << std::endl;
            printStat("Reputation", characterCard->getReputation(), Color::RED);
            printStat("Money", characterCard->getMoney(), Color::GREEN);
            break;
        }
        case Card::Type::LEVERAGE: {
            std::shared_ptr<LeverageCard> leverageCard = std::dynamic_pointer_cast<LeverageCard>(card);
            std::cout << " (Leverage)" << std::endl;
            std::cout << "Damage:" << std::endl;
            printStat("Money", leverageCard->getMoneyDamage(), Color::GREEN);
            printStat("Reputation", leverageCard->getReputationDamage(),
                      Color::RED);
            printStat("Trust", leverageCard->getTrustDamage(), Color::BLUE);
            break;
        }
        default:
            std::cout << std::endl;
    }
}

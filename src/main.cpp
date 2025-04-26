#include <iostream>
#include "game.h"
#include <vector>
#include "player_hand.h"
#include "leverage_card.h"
#include "action_card.h"
#include "character_card.h"

void printGreen(const std::string& text) {
    std::cout << "\033[32m" << text << "\033[0m";
}

void printRed(const std::string& text) {
    std::cout << "\033[31m" << text << "\033[0m";
}

void printBlue(const std::string& text) {
    std::cout << "\033[34m" << text << "\033[0m";
}

void displayCard(Card* card) {
    std::cout << card->getName();
    
    if (card->getType() == Card::Type::ACTION) {
        ActionCard* actionCard = dynamic_cast<ActionCard*>(card);
        std::cout << " (Action)" << std::endl;
        std::cout << "    Money: ";
        printGreen(std::to_string(actionCard->getMoneyChange()));
        std::cout << std::endl;
        std::cout << "    Reputation: ";
        printRed(std::to_string(actionCard->getReputationChange()));
        std::cout << std::endl;
        std::cout << "    Trust: ";
        printBlue(std::to_string(actionCard->getTrustChange()));
        std::cout << std::endl;
    }
    if (card->getType() == Card::Type::CHARACTER) {
        CharacterCard* characterCard = dynamic_cast<CharacterCard*>(card);
        std::cout << " (Character)" << std::endl;
        std::cout << "    Department: " << characterCard->getDepartment() << std::endl;
        std::cout << "    Reputation: ";
        printRed(std::to_string(characterCard->getReputation()));
        std::cout << std::endl;
        std::cout << "    Money: ";
        printGreen(std::to_string(characterCard->getMoney()));
        std::cout << std::endl;
    }
    if (card->getType() == Card::Type::LEVERAGE) {
        LeverageCard* leverageCard = dynamic_cast<LeverageCard*>(card);
        std::cout << " (Leverage)" << std::endl;
        std::cout << "Damage: " << std::endl;
        std::cout << "    Money: ";
        printGreen(std::to_string(leverageCard->getMoneyDamage()));
        std::cout << std::endl;
        std::cout << "    Reputation: ";
        printRed(std::to_string(leverageCard->getReputationDamage()));
        std::cout << std::endl;
        std::cout << "    Trust: ";
        printBlue(std::to_string(leverageCard->getTrustDamage()));
        std::cout << std::endl;
    }
}

void displayCardShort(Card* card) {
    std::cout << card->getName();

    if (card->getType() == Card::Type::ACTION) {
        ActionCard* actionCard = dynamic_cast<ActionCard*>(card);
        std::cout << " (";
        printGreen(std::to_string(actionCard->getMoneyChange()));
        std::cout << ", ";
        printRed(std::to_string(actionCard->getReputationChange()));
        std::cout << ", ";
        printBlue(std::to_string(actionCard->getTrustChange()));
        std::cout << ")";
    }

    if (card->getType() == Card::Type::CHARACTER) {
        CharacterCard* characterCard = dynamic_cast<CharacterCard*>(card);
        std::cout << " (" << characterCard->getDepartment() << ")";
    }

    if (card->getType() == Card::Type::LEVERAGE) {
        LeverageCard* leverageCard = dynamic_cast<LeverageCard*>(card);
        std::cout << " (Damage: ";
        printGreen(std::to_string(leverageCard->getMoneyDamage()));
        std::cout << ", ";
        printRed(std::to_string(leverageCard->getReputationDamage()));
        std::cout << ", ";
        printBlue(std::to_string(leverageCard->getTrustDamage()));
        std::cout << ")";
    }
    
    std::cout << std::endl;
}

void displayPlayer(Player* player) {
    std::cout << "Id: " << player->getId() << std::endl;
    std::cout << "Name: " << player->getPlayerName() << std::endl;
    std::cout << "Secret: " << player->getSecret() << std::endl;
    std::cout << "Money: " << player->getMoney() << std::endl;
    std::cout << "Reputation: " << player->getReputation() << std::endl;
    std::cout << "Trust: " << player->getTrust() << std::endl;
    std::cout << "Department: " << player->getDepartment() << std::endl;
    
    PlayerHand& hand = player->getHand();
    std::cout << "Hand size: " << hand.getCards().size() << std::endl;

}


void showCurrentPlayerStats(Player* player) {
    printGreen("Money: ");
    std::cout << player->getMoney() << std::endl;
    printRed("Reputation: ");
    std::cout << player->getReputation() << std::endl;
    printBlue("Trust: ");
    std::cout << player->getTrust() << std::endl;
    std::cout << std::endl;
}

void showCurrentPlayerCards(Player* player) {
    if (player->getHand().getCards().size() == 0) {
        return;
    }
    std::cout << "Cards: ";

    for (auto& card : player->getHand().getCards()) {
        displayCardShort(card);
    }
    std::cout << std::endl;
}

std::string cliSelect(const std::vector<std::string>& options) {
    for (int i = 0; static_cast<size_t>(i) < options.size(); ++i) {
        std::cout << "    " << i + 1 << ") " << options[i] << std::endl;
    }
    std::cout << "Enter number: ";
    size_t number;
    std::cin >> number;
    
    if (number < 1 || number > options.size()) {
        return "";
    }
    
    return options[number - 1];
}

bool secretBrickwall(Player& player, int attempts = 0) {
    std::cout << "Secret: ";
    std::string userAnswer;
    std::cin >> userAnswer;

    if (userAnswer == player.getSecret()) {
        return true;
    }

    if (attempts < 10) {
        std::cout << "Wrong secret!" << std::endl;
        return secretBrickwall(player, attempts + 1);
    }

    std::cout << "Too many attempts!" << std::endl;

    return false;

}

int main() {
    Game game;
    std::vector<UserPlayerInput> players = {
        UserPlayerInput{
            .playerName = "Zach",
            .playerSecret = "12345",
            .isAI = false,
        },
        UserPlayerInput{
            .playerName = "Bob",
            .playerSecret = "67890",
            .isAI = false,
        }, 
    };

    game.initialize(players);    
    
    while (!game.isEnd()) {
        auto move = game.offerMove();
        
        Player& actor = move->getActor();
        std::cout << "Current player: " << actor.getPlayerName() << std::endl;
        showCurrentPlayerStats(&actor);
        showCurrentPlayerCards(&actor);

        bool isAuthorized = secretBrickwall(actor);

        if (!isAuthorized) {
            game.next();
            continue;
        }
        
        std::vector<std::string> options;

        options.push_back("Decline");
        options.push_back("Trade");

        if (move->isAbleToAccept()) {
            options.push_back("Accept");
        }

        if (actor.getHand().getLeverageCards().size() > 0) {
            options.push_back("Leverage");
        }
        Card* card = move->getCard();
        displayCard(card);
        
        std::cout << "Options:" << std::endl;
        auto option = cliSelect(options);
        
        if (option == "Decline") {
            move->decline();
        }

        if (option == "Accept") {
            move->accept();
        }

        // if (option == "Leverage") {
        //     std::cout << "Leverage" << std::endl;
        //     // TODO: Implement leverage
        // } 

        // if (option == "Trade") {
        //     std::cout << "Trade" << std::endl;
        //     // TODO: Implement trade
        // }

        game.next();
    }
   return 0;
}

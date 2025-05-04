/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include "move.h"
#include "game.h"
#include "player.h"
#include "leverage_card.h"
#include "cli_game_utils.h"
#include "card_cli_utils.h"
#include "player_cli_utils.h"
#include <iostream>
#include <action_card.h>
#include <algorithm>

const std::vector<std::shared_ptr<Player>> getHumanPlayers(const std::vector<std::shared_ptr<Player>>& players) {
    std::vector<std::shared_ptr<Player>> humanPlayers;
    for (const auto& player : players) {
        if (player->getId() != "AI") {
            humanPlayers.push_back(player);
        }
    }
    return humanPlayers;
}

bool promptForTrade(Move& move, const std::vector<std::shared_ptr<Player>>& players) {
    if (players.empty()) {
        return false;
    }
    Player& actor = move.getActor();

    std::cout << "Choose buyer" << std::endl;
    std::vector<std::string> options;
    std::vector<std::shared_ptr<Player>> buyers;

    for (const auto& player : getHumanPlayers(players)) {
        if (player->getId() == actor.getId()) continue;
        options.push_back(player->getPlayerName());
        buyers.push_back(player);
    }

    if (options.empty()) return false;

    int buyerIndex = cliSelect(options);
    if (buyerIndex < 0) return false;

    auto buyer = buyers[buyerIndex];

    std::cout << "Enter price: ";
    size_t price;
    if (!(std::cin >> price) || price < 1) {
        clearInput();
        return false;
    }
    clearInput();

    std::cout << buyer->getPlayerName() << ", please verify your purchase by entering your secret" << std::endl;

    if (!secretBrickwall(*buyer)) {
        std::cout << "Canceled purchase, no verification" << std::endl;
        return false;
    }

    move.trade(price, *buyer);

    std::cout << "Transaction from " << actor.getPlayerName() << " to " << buyer->getPlayerName() << std::endl;
    std::cout << "For: " << price << std::endl;
    std::cout << "Was successful! ✅" << std::endl;

    return true;
}

void promptForLeverage(Move& move, std::vector<std::shared_ptr<Player>>& players) {
    Player& player = move.getActor();

    auto leverageCards = player.getHand()->getLeverageCards();
    if (leverageCards.empty()) {
        std::cout << "No leverage cards available." << std::endl;
        return;
    }

    std::cout << "Select leverage (enter number)" << std::endl;
    for (size_t i = 0; i < leverageCards.size(); ++i) {
        std::cout << " " << i + 1 << ") ";
        displayCardShort(leverageCards[i]);
    }

    size_t number;
    std::cout << "Enter number: ";
    if (!(std::cin >> number) || number < 1 || number > leverageCards.size()) {
        clearInput();
        return;
    }
    clearInput();

    auto leverageCard = std::dynamic_pointer_cast<LeverageCard>(leverageCards[number - 1]);
    std::cout << "Leverage selected: " << leverageCard->getName() << std::endl;

    std::cout << "Choose target" << std::endl;
    std::vector<std::string> options;
    std::vector<std::shared_ptr<Player>> targets;

    for (const auto& potentialTarget : players) {
        if (potentialTarget->getId() == player.getId()) continue;
        options.push_back(potentialTarget->getPlayerName());
        targets.push_back(potentialTarget);
    }

    if (options.empty()) return;

    int targetIndex = cliSelect(options);
    if (targetIndex < 0) return;

    auto target = targets[targetIndex];
    if (target->getId() != "AI") {
        std::cout << target->getPlayerName() << ", do you want to buy this card? (Yes/No)" << std::endl;
        bool isAuthorized = secretBrickwall(*target);
        if (!isAuthorized) return;

        std::vector<std::string> buyoutOptions = {"Yes", "No"};
        int optionIndex = cliSelect(buyoutOptions);
        if (optionIndex < 0) return;

        if (buyoutOptions[optionIndex] == "Yes") {
            if (promptForTrade(move, getHumanPlayers(players))) {
                leverageCard->deactivate(player);
                leverageCard->deactivate(*target);
                return;
            }
        }
    }

    leverageCard->executeOnPlayer(*target);
    leverageCard->deactivate(player);

    std::cout << "Target: " << target->getPlayerName() << std::endl;
    std::cout << "Money: " << target->getMoney() << std::endl;
    std::cout << "Reputation: " << target->getReputation() << std::endl;
    std::cout << "Trust: " << target->getTrust() << std::endl;
    std::cout << std::endl;
}

void greetPlayers() {
    std::cout << "Hello, players!" << std::endl;
    std::cout << "Welcome to the game!" << std::endl;
}

std::vector<UserPlayerInput> promptForPlayers() {
    std::vector<UserPlayerInput> playersInput;

    std::cout << "Enter 'stop' when you are done adding players" << std::endl;

    std::string playerName;
    while (playerName != "stop") {
        std::cout << "Enter player name: ";
        std::cin >> playerName;

        if (playerName == "stop") {
            break;
        }
        std::cout << "Create player secret: ";
        std::string playerSecret;
        std::cin >> playerSecret; 
        UserPlayerInput playerInput;
        playerInput.playerName = playerName;
        playerInput.playerSecret = playerSecret;
        playerInput.isAI = false;
        playersInput.push_back(playerInput);
    }

    std::cout << "Do you want to add AI player? (Yes/No)" << std::endl;
    std::vector<std::string> options = {"Yes", "No"};
    bool didWantToAddAI = options[cliSelect(options)] == "Yes"; 

    if (didWantToAddAI) {
        UserPlayerInput aiInput;
        aiInput.playerName = "AI";
        aiInput.playerSecret = "ai";
        aiInput.isAI = true;
        playersInput.push_back(aiInput);
    }

    return playersInput;
}

void gameEnd(std::shared_ptr<Move> move, Game& game) {
    std::cout << move->getCard()->getName() << std::endl;
    std::cout << "Game is finished" << std::endl;

    auto winner = game.determineWinner();
    if (winner) {
        std::cout << "Winner: ";
        displayPlayer(winner.get());
    } else {
        std::cout << "No one wins 😢" << std::endl;
    }
}

void humanPlayerMove(std::shared_ptr<Move> move, std::vector<std::shared_ptr<Player>>& players) {
    Player& actor = move->getActor();

    if (!secretBrickwall(actor)) {
        return;
    }

    std::vector<std::string> options = {"Decline", "Trade"};
    if (move->isAbleToAccept()) options.push_back("Accept");
    if (!actor.getHand()->getLeverageCards().empty()) options.push_back("Leverage");

    Card* card = move->getCard();
    displayCard(card);

    std::cout << "Options:" << std::endl;
    int optionIndex = cliSelect(options);
    if (optionIndex < 0) {
        std::cout << "Invalid option selected. Skipping turn." << std::endl;
        return;
    }

    const std::string& option = options[optionIndex];
    if (option == "Decline") {
        move->decline();
    } else if (option == "Accept") {
        move->accept();
    } else if (option == "Leverage") {
        promptForLeverage(*move, players);
    } else if (option == "Trade") {
        promptForTrade(*move, players);
    }
}

void aiOffersTrade(std::unique_ptr<Move> move, std::vector<std::shared_ptr<Player>>& players) {
    displayCard(move->getCard());
    std::vector<std::shared_ptr<Player>> humanPlayers = getHumanPlayers(players);
    
    int price = 5;

    if (move->getCard()->getType() == Card::Type::CHARACTER) {
        CharacterCard* characterCard = dynamic_cast<CharacterCard*>(move->getCard());
        price = characterCard->getMoney() / 10 * 2;
    }

    if (move->getCard()->getType() == Card::Type::ACTION) {
        ActionCard* actionCard = dynamic_cast<ActionCard*>(move->getCard());
        price = actionCard->getMoneyChange() > 0 ? actionCard->getMoneyChange() * 2 : 5;
    }

    std::sort(humanPlayers.begin(), humanPlayers.end(), [](const std::shared_ptr<Player>& a, const std::shared_ptr<Player>& b) {
        return a->getMoney() > b->getMoney();
    });

    for (const auto& player : humanPlayers) {
        if (player->getMoney() < price) continue;
        std::cout << "AI offers " << player->getPlayerName() << " to buy this card for " << price << std::endl;
        bool isAuthorized = secretBrickwall(*player);
        if (!isAuthorized) return;

        std::cout << "Do you want to buy this card? (Yes/No)" << std::endl;
        std::vector<std::string> buyoutOptions = {"Yes", "No"};
        int optionIndex = cliSelect(buyoutOptions);
        if (optionIndex < 0) return;
        if (buyoutOptions[optionIndex] == "Yes") {
            std::cout << "AI and " << player->getPlayerName() << " agree on price: " << price << std::endl;
            move->trade(price, *player);
            std::cout << "Transaction from AI to " << player->getPlayerName() << " was successful! ✅" << std::endl;
            return;
        }
    }

    move->decline();
}

void aiPlayerMove(std::unique_ptr<Move> move, std::vector<std::shared_ptr<Player>>& players) {
    Player& actor = move->getActor();
    
    if (actor.getId() != "AI") {
        return;
    }
    std::vector<std::string> options = {"Decline", "Trade"};
    if (move->isAbleToAccept()) options.push_back("Accept");
    if (!actor.getHand()->getLeverageCards().empty()) options.push_back("Leverage");

    Card* card = move->getCard();
    displayCard(card);

    std::cout << "Options:" << std::endl;

    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << " " << i + 1 << ") " << options[i] << std::endl;
    }

    if (!actor.getHand()->getLeverageCards().empty()) {
        // find the player with the most trust
        std::vector<std::shared_ptr<Player>> humanPlayers = getHumanPlayers(players);
        std::sort(humanPlayers.begin(), humanPlayers.end(), [](const std::shared_ptr<Player>& a, const std::shared_ptr<Player>& b) {
            return a->getTrust() > b->getTrust();
        });

        auto maxTrustPlayer = humanPlayers.back();
        std::cout << "AI targets " << maxTrustPlayer->getPlayerName() << std::endl;
       
        LeverageCard* leverageCard = dynamic_cast<LeverageCard*>(card);

        leverageCard->executeOnPlayer(*maxTrustPlayer);
        std::cout << "AI targets " << maxTrustPlayer->getPlayerName() << std::endl;
        leverageCard->deactivate(actor);
        std::cout << "AI targets " << maxTrustPlayer->getPlayerName() << std::endl;
        return;
    }

    if (card->getType() == Card::Type::CHARACTER) {
        if (card->isPossibleToPlay(actor)) {
            std::cout << "AI accepts this card" << std::endl;
            move->accept();
            return;
        }
        aiOffersTrade(std::move(move), players);
        return;
    }

    if (card->getType() == Card::Type::ACTION) {
        ActionCard* actionCard = dynamic_cast<ActionCard*>(card);

        if (actionCard->getTrustChange() < 0) {
            aiOffersTrade(std::move(move), players);
            return;
        }
        std::cout << "AI accepts this card" << std::endl;
        move->accept();
    }

    if (card->getType() == Card::Type::LEVERAGE) {
        std::cout << "AI accepts this card" << std::endl;
        move->accept();
        return;
    }
}

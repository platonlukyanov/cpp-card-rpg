#include "move.h"
#include "game.h"
#include "player.h"
#include "leverage_card.h"
#include "cli_game_utils.h"
#include "card_cli_utils.h"
#include "player_cli_utils.h"
#include <iostream>

bool promptForTrade(Move& move, const std::vector<std::shared_ptr<Player>>& players) {
    Player& actor = move.getActor();

    std::cout << "Choose buyer" << std::endl;
    std::vector<std::string> options;
    std::vector<std::shared_ptr<Player>> buyers;

    for (const auto& player : players) {
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

void promptForLeverage(Move& move, Game& game) {
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

    for (const auto& potentialTarget : game.getPlayers()) {
        if (potentialTarget->getId() == player.getId()) continue;
        options.push_back(potentialTarget->getPlayerName());
        targets.push_back(potentialTarget);
    }

    if (options.empty()) return;

    int targetIndex = cliSelect(options);
    if (targetIndex < 0) return;

    auto target = targets[targetIndex];

    std::cout << target->getPlayerName() << ", do you want to buy this card? (Yes/No)" << std::endl;
    bool isAuthorized = secretBrickwall(*target);
    if (!isAuthorized) return;

    std::vector<std::string> buyoutOptions = {"Yes", "No"};
    int optionIndex = cliSelect(buyoutOptions);
    if (optionIndex < 0) return;

    if (buyoutOptions[optionIndex] == "Yes") {
        if (promptForTrade(move, game.getPlayers())) {
            leverageCard->deactivate(player);
            return;
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

void humanPlayerMove(std::shared_ptr<Move> move, Game& game) {
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
        promptForLeverage(*move, game);
    } else if (option == "Trade") {
        promptForTrade(*move, game.getPlayers());
    }
}
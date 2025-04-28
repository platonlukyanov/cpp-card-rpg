#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <limits>
#include <map>
#include "game.h"
#include "player_hand.h"
#include "leverage_card.h"
#include "action_card.h"
#include "character_card.h"
#include "cli_game_utils.h"
#include "card_cli_utils.h"
#include "player_cli_utils.h"
#include "cli_game_scenarios.h"

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
        aiInput.playerName = "AIII";
        aiInput.playerSecret = "ai";
        aiInput.isAI = true;
        playersInput.push_back(aiInput);
    }

    return playersInput;
}

int main() {
    Game game;

    greetPlayers();
    std::vector<UserPlayerInput> playersInput = promptForPlayers();

    game.initialize(playersInput);

    while (!game.isEnd()) {
        auto move = game.offerMove();

        if (game.isEnd()) {
            gameEnd(std::move(move), game);
            break;
        }

        Player& actor = move->getActor();
        std::cout << "Current player: " << actor.getPlayerName() << std::endl;

        showCurrentPlayerStats(&actor);
        showCurrentPlayerCards(actor);
        
        humanPlayerMove(std::move(move), game);

        game.next();
    }

    return 0;
}

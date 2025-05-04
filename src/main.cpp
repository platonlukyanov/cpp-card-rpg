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

int main() {
    Game game;

    greetPlayers();
    std::vector<UserPlayerInput> playersInput = promptForPlayers();

    game.initialize(playersInput);
    std::vector <std::shared_ptr<Player>> players = game.getPlayers();

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
        
        if (actor.getId() == "AI") {
            aiPlayerMove(std::move(move), players);
        } else {
            humanPlayerMove(std::move(move), players);
        }

        game.next();
    }

    return 0;
}

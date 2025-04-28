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

    std::vector<UserPlayerInput> playersInput = {
        {"Zach", "12345", false},
        {"Bob", "67890", false},
    };

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

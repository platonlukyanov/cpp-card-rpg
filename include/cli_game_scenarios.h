#ifndef CLI_GAME_SCENARIOS_H
#define CLI_GAME_SCENARIOS_H
#include <vector>
#include <memory>
#include "move.h"
#include "game.h"
#include "player.h"

bool promptForTrade(Move& move, const std::vector<std::shared_ptr<Player>>& players);
void promptForLeverage(Move& move, Game& game);
void gameEnd(std::shared_ptr<Move> move, Game& game);

#endif
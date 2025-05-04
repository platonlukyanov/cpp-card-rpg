#ifndef CLI_GAME_SCENARIOS_H
#define CLI_GAME_SCENARIOS_H
#include <vector>
#include <memory>
#include "move.h"
#include "game.h"
#include "player.h"

bool promptForTrade(Move& move, const std::vector<std::shared_ptr<Player>>& players);
void promptForLeverage(Move& move, std::vector<std::shared_ptr<Player>>& players);
void gameEnd(std::shared_ptr<Move> move, Game& game);
void humanPlayerMove(std::shared_ptr<Move>, std::vector<std::shared_ptr<Player>>& players);
void greetPlayers();
std::vector<UserPlayerInput> promptForPlayers();
void aiPlayerMove(std::unique_ptr<Move> move, std::vector<std::shared_ptr<Player>>& players);

#endif
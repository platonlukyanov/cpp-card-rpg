/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#ifndef CLI_GAME_SCENARIOS_H
#define CLI_GAME_SCENARIOS_H
#include <memory>
#include <vector>

#include "game.h"
#include "move.h"
#include "player.h"

bool promptForTrade(Move& move,
                    const std::vector<std::shared_ptr<Player>>& players);
void promptForLeverage(Move& move,
                       std::vector<std::shared_ptr<Player>>& players);
void gameEnd(std::shared_ptr<Move> move, Game& game);
void humanPlayerMove(std::shared_ptr<Move>,
                     std::vector<std::shared_ptr<Player>>& players);
void greetPlayers();
std::vector<UserPlayerInput> promptForPlayers();
void aiPlayerMove(std::unique_ptr<Move> move,
                  std::vector<std::shared_ptr<Player>>& players);

#endif
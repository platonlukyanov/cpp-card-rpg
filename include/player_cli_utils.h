/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#ifndef PLAYER_CLI_UTILS_H
#define PLAYER_CLI_UTILS_H
#include "player.h"

void displayPlayer(Player* player);
void showCurrentPlayerStats(Player* player);
void showCurrentPlayerCards(Player& player);
bool secretBrickwall(Player& player);

#endif
/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#ifndef CARD_CLI_UTILS_H
#define CARD_CLI_UTILS_H
#include <memory>

#include "card.h"

void displayCard(std::shared_ptr<Card> card);
void displayCardShort(std::shared_ptr<Card> card);

#endif
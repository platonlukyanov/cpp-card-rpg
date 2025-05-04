/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include "end_card.h"

#include "player.h"

EndCard::EndCard(int id) : Card(id, Type::END, "CEO Death") {
}

bool EndCard::isPossibleToPlay(const Player& player) const {
    // EndCard can always be played
    return true;
}

void EndCard::execute(Player& player) {
    // EndCard does not have any effects, it simply signals the end of the game
}
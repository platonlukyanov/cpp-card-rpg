#include "end_card.h"
#include "player.h"

EndCard::EndCard(int id) : Card(id, Type::END, "Смерть CEO") {}

bool EndCard::isPossibleToPlay(const Player& player) const {
    // EndCard всегда можно сыграть
    return true;
}

void EndCard::execute(Player& player) {
    // EndCard не имеет эффектов, он просто сигнализирует о конце игры
} 
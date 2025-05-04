/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include "ai.h"

#include <memory>

#include "character_card.h"

AI::AI(const std::string& id, const std::string& secret) : Player(id, secret) {
    setName(AI_NAME);
}

std::unique_ptr<Move> AI::makeMove(Stack& stack) {
    if (stack.isEmpty()) {
        return nullptr;
    }

    // Look at the top card, not taking it from the stack
    auto card = stack.peekCard();
    if (!card) {
        return nullptr;
    }

    // Check if the card is possible to play
    if (!card->isPossibleToPlay(*this)) {
        return nullptr;
    }

    // Check the department of the character card
    if (auto characterCard = dynamic_cast<CharacterCard*>(card)) {
        if (characterCard->getDepartment() != getDepartment()) {
            return nullptr;
        }
    }

    // if all checks passed, take the card from the stack
    return std::make_unique<Move>(*this, stack.drawCard());
}

#include "ai.h"
#include "character_card.h"
#include <memory>

AI::AI(const std::string& id, const std::string& secret)
    : Player(id, secret) {
        setName(AI_NAME);
}

std::unique_ptr<Move> AI::makeMove(Stack& stack) {
    if (stack.isEmpty()) {
        return nullptr;
    }

    // Смотрим верхнюю карту, не забирая её из стека
    auto card = stack.peekCard();
    if (!card) {
        return nullptr;
    }

    // Проверяем, можно ли сыграть карту
    if (!card->isPossibleToPlay(*this)) {
        return nullptr;
    }

    // Проверяем отдел для карт персонажей
    if (auto characterCard = dynamic_cast<CharacterCard*>(card)) {
        if (characterCard->getDepartment() != getDepartment()) {
            return nullptr;
        }
    }

    // Если все проверки пройдены, забираем карту из стека
    return std::make_unique<Move>(*this, stack.drawCard());
} 

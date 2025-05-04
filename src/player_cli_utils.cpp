/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include "player.h"
#include "cli_game_utils.h"
#include "card_cli_utils.h"

void displayPlayer(Player* player) {
    if (!player) return;

    std::cout << "Id: " << player->getId() << std::endl;
    std::cout << "Name: " << player->getPlayerName() << std::endl;
    std::cout << "Secret: " << player->getSecret() << std::endl;
    std::cout << "Money: " << player->getMoney() << std::endl;
    std::cout << "Reputation: " << player->getReputation() << std::endl;
    std::cout << "Trust: " << player->getTrust() << std::endl;
    std::cout << "Department: " << player->getDepartment() << std::endl;

    auto hand = player->getHand();
    std::cout << "Hand size: " << hand->getCards().size() << std::endl;
}

void showCurrentPlayerStats(Player* player) {
    if (!player) return;

    printColored("Money: ", Color::GREEN);
    std::cout << player->getMoney() << std::endl;

    printColored("Reputation: ", Color::RED);
    std::cout << player->getReputation() << std::endl;

    printColored("Trust: ", Color::BLUE);
    std::cout << player->getTrust() << std::endl;

    std::cout << std::endl;
}

void showCurrentPlayerCards(Player& player) {
    auto hand = player.getHand();
    if (!hand) return;

    const auto& cards = hand->getCards();
    if (cards.empty()) {
        std::cout << "No cards." << std::endl;
        return;
    }

    std::cout << "Cards: ";
    for (size_t i = 0; i < cards.size(); ++i) {
        displayCardShort(cards[i]);
        if (i < cards.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

bool secretBrickwall(Player& player) {
    constexpr int MAX_ATTEMPTS = 3;
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        std::cout << "Secret: ";
        std::string userAnswer;
        std::cin >> userAnswer;

        if (userAnswer == player.getSecret()) return true;

        std::cout << "Wrong secret! Attempts remaining: " << (MAX_ATTEMPTS - attempts - 1) << std::endl;
        ++attempts;
    }

    std::cout << "Too many attempts!" << std::endl;
    return false;
}
#include "game.h"
#include "ai.h"
#include <stdexcept>
#include "card_factory.h"
#include "player_hand.h"

const int GAME_LENGTH = 37;

Game::Game() : stack_(std::make_unique<Stack>()) {
    std::array<std::string, GAME_LENGTH - 1> cards = {
      "Team Lead",
      "Financial Consultant",
      "Lawyer",
      "Sales Manager",
      "Developer",
      "Financial Analyst",
      "PR Specialist",
      "Marketer",
      "Tester",
      "Accountant",
      "Legal Counsel",
      "Sales Agent",
      "Web Developer",
      "Chief Financial Officer",
      "Intellectual Property Specialist",
      "Marketing Manager",
      "Software Architect",
      "Financial Controller",
      "Litigation Lawyer", 
      "Sales Director",
      "Development",
      "Frame a colleague and get a promotion",
      "Present a big project",
      "Sell business information to competitors",
      "Fire an employee",
      "Organize a corporate event",
      "Get a loan",
      "Create a new department",
      "Hire a new employee",
      "Conduct an audit",
      "Create a new product",
      "Reveal the migration status of a cousin",
      "Tell about a tweet from the last decade",
      "Call the tax inspectorate",
      "Reveal secret information",
      "Accuse of plagiarism",
    };

    for (int i = 0; static_cast<size_t>(i) < cards.size(); ++i) {
        auto card = CardFactory::createCard(cards[i], i + 1);
        stack_->pushCard(std::move(card));
    }
    stack_->shuffle();
    std::unique_ptr<Card> endCard = CardFactory::createCard("CEO Death", cards.size() + 1);

    // we need to insert end card to the last 25% of the game
    int endCardIndex = static_cast<int>(GAME_LENGTH * 75 / 100);
    stack_->insertCard(std::move(endCard), GAME_LENGTH - endCardIndex);
}

void Game::initialize(const std::vector<UserPlayerInput>& players) {
    std::vector<std::unique_ptr<CharacterCard>> cards = stack_->fetchPlayersCards(players.size());
    if (cards.size() < players.size()) {
        throw std::runtime_error("Not enough cards for players"); }
    for (int i = 0; static_cast<size_t>(i) < cards.size(); ++i) {
        auto& playerInput = players[i];
        auto& card = cards[i];
        
        std::shared_ptr<Player> player;
        std::string id = std::to_string(i);
        if (playerInput.isAI) {
            player = std::make_shared<AI>("AI", playerInput.playerSecret);
        } else {
            player = std::make_shared<Player>(id, playerInput.playerSecret);
            player->setName(playerInput.playerName);
        }
        
        player->setDepartment(card->getDepartment());
        player->gainReputation(card->getReputation());
        player->gainMoney(card->getMoney());
        std::string playerName = player->getPlayerName() + " (" + card->getName() + ")";
        player->setName(playerName);

        players_.push_back(player);
    }

    for (auto& player : players_) {
        playersQueue_.push(player);
    }
}

const std::vector<std::shared_ptr<Player>> Game::getPlayers() const {
    return players_; 
}

std::unique_ptr<Move> Game::offerMove() {
    std::shared_ptr<Player> actor = playersQueue_.front();

    std::unique_ptr<Card> card = stack_->drawCard();
    if (!card) {
        return nullptr;
    }
    
    if (card->getType() == Card::Type::END) {
        isEnd_ = true;
    }

    std::unique_ptr<Move> move = std::make_unique<Move>(*actor, std::move(card));

    return move;
}

void Game::next() {
   playersQueue_.push(playersQueue_.front());
   playersQueue_.pop();
}

bool Game::isEnd() const {
    return isEnd_;
}

std::shared_ptr<Player> Game::determineWinner() const {
    if (!isEnd_) {
        return nullptr;
    }

    std::shared_ptr<Player> winner = players_.front();
    int trust = 0;

    for (std::shared_ptr<Player> player : players_) {
        if (player->getTrust() > trust) {
            winner = player;
            trust = player->getTrust();
            continue;
        }
        if (player->getTrust() == trust && player->getReputation() > winner->getReputation()) {
            winner = player;
            continue;
        }
        if (player->getTrust() == trust && player->getReputation() == winner->getReputation() && player->getMoney() > winner->getMoney()) {
            winner = player;
            continue;
        }
    }

    return winner;
}

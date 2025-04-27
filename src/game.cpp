#include "game.h"
#include "ai.h"
#include <stdexcept>
#include "card_factory.h"
#include "player_hand.h"

Game::Game() : stack_(std::make_unique<Stack>()) {
    std::array<std::string, 6> cards = {
      "Тимлид",
      "Финансовый консультант",
    //   "Юрист",
    //   "Менеджер по продажам",
    //   "Разработчик",
    //   "Финансовый аналитик",
    //   "Специалист по PR",
    //   "Маркетолог",
    //   "Тестировщик",
    //   "Бухгалтер",
    //   "Юрисконсульт",
    //   "Продажный агент",
    //   "Веб-разработчик",
    //   "Финансовый директор",
    //   "Специалист по интеллектуальной собственности",
    //   "Менеджер по маркетингу",
    //   "Архитектор программного обеспечения",
    //   "Финансовый контроллер",
    //   "Судебный юрист", 
    //   "Директор по продажам",
    //   "Разработка",
    //   "Подставить коллегу и получить повышение",
    //   "Презентовать большой проект",
    //   "Продать информацию о бизнесе конкурентам",
    //   "Уволить сотрудника",
    //   "Провести корпоративное мероприятие",
    //   "Получить кредит",
    //   "Создать новый отдел",
    //   "Нанять нового сотрудника",
    //   "Провести аудит",
    //   "Создать новый продукт",
    //   "Раскрыть статус миграции двоюродной сестры",
      "Рассказать о твите из прошлого десятелетия",
      "Вызвать налоговую инспекцию",
      "Раскрыть секретную информацию",
      "Обвинить в плагиате",
    };

    for (int i = 0; static_cast<size_t>(i) < cards.size(); ++i) {
        auto card = CardFactory::createCard(cards[i], i + 1);
        stack_->pushCard(std::move(card));
    }
    stack_->shuffle();
    stack_->pushCard(CardFactory::createCard("Смерть CEO", cards.size() + 1));
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
            player = std::make_shared<AI>(id, playerInput.playerSecret);
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

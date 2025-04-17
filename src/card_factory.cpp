#include "card_factory.h"
#include "trust_before_condition_leverage_card.h"

std::unique_ptr<Card> CardFactory::createCard(const std::string& cardName, int id) {
    // Персонажи
    if (cardName == "Тимлид") return createCharacterCard("Тимлид", id);
    if (cardName == "Финансовый консультант") return createCharacterCard("Финансовый консультант", id);
    if (cardName == "Юрист") return createCharacterCard("Юрист", id);
    if (cardName == "Менеджер по продажам") return createCharacterCard("Менеджер по продажам", id);
    if (cardName == "Разработчик") return createCharacterCard("Разработчик", id);
    if (cardName == "Финансовый аналитик") return createCharacterCard("Финансовый аналитик", id);
    if (cardName == "Специалист по PR") return createCharacterCard("Специалист по PR", id);
    if (cardName == "Маркетолог") return createCharacterCard("Маркетолог", id);
    if (cardName == "Тестировщик") return createCharacterCard("Тестировщик", id);
    if (cardName == "Бухгалтер") return createCharacterCard("Бухгалтер", id);
    if (cardName == "Юрисконсульт") return createCharacterCard("Юрисконсульт", id);
    if (cardName == "Продажный агент") return createCharacterCard("Продажный агент", id);
    if (cardName == "Веб-разработчик") return createCharacterCard("Веб-разработчик", id);
    if (cardName == "Финансовый директор") return createCharacterCard("Финансовый директор", id);
    if (cardName == "Специалист по интеллектуальной собственности") return createCharacterCard("Специалист по интеллектуальной собственности", id);
    if (cardName == "Менеджер по маркетингу") return createCharacterCard("Менеджер по маркетингу", id);
    if (cardName == "Архитектор программного обеспечения") return createCharacterCard("Архитектор программного обеспечения", id);
    if (cardName == "Финансовый контроллер") return createCharacterCard("Финансовый контроллер", id);
    if (cardName == "Судебный юрист") return createCharacterCard("Судебный юрист", id);
    if (cardName == "Директор по продажам") return createCharacterCard("Директор по продажам", id);

    // Действия
    if (cardName == "Подставить коллегу и получить повышение") return createActionCard("Подставить коллегу и получить повышение", id);
    if (cardName == "Презентовать большой проект") return createActionCard("Презентовать большой проект", id);
    if (cardName == "Продать информацию о бизнесе конкурентам") return createActionCard("Продать информацию о бизнесе конкурентам", id);
    if (cardName == "Уволить сотрудника") return createActionCard("Уволить сотрудника", id);
    if (cardName == "Провести корпоративное мероприятие") return createActionCard("Провести корпоративное мероприятие", id);
    if (cardName == "Получить кредит") return createActionCard("Получить кредит", id);
    if (cardName == "Создать новый отдел") return createActionCard("Создать новый отдел", id);
    if (cardName == "Нанять нового сотрудника") return createActionCard("Нанять нового сотрудника", id);
    if (cardName == "Провести аудит") return createActionCard("Провести аудит", id);
    if (cardName == "Создать новый продукт") return createActionCard("Создать новый продукт", id);

    // Leverage-карты
    if (cardName == "Раскрыть статус миграции двоюродной сестры") return createLeverageCard("Раскрыть статус миграции двоюродной сестры", id);
    if (cardName == "Рассказать о твите из прошлого десятелетия") return createLeverageCard("Рассказать о твите из прошлого десятелетия", id);
    if (cardName == "Вызвать налоговую инспекцию") return createLeverageCard("Вызвать налоговую инспекцию", id);
    if (cardName == "Раскрыть секретную информацию") return createLeverageCard("Раскрыть секретную информацию", id);
    if (cardName == "Обвинить в плагиате") return createLeverageCard("Обвинить в плагиате", id);

    // End-карта
    if (cardName == "Смерть CEO") return createEndCard(id);

    return nullptr;
}

std::unique_ptr<CharacterCard> CardFactory::createCharacterCard(const std::string& name, int id) {
    // Создаем карты персонажей с их характеристиками
    if (name == "Тимлид") return std::make_unique<CharacterCard>(id, name, 30, 10, "разработка");
    if (name == "Финансовый консультант") return std::make_unique<CharacterCard>(id, name, 20, 20, "финансы");
    if (name == "Юрист") return std::make_unique<CharacterCard>(id, name, 25, 15, "юриспруденция");
    if (name == "Менеджер по продажам") return std::make_unique<CharacterCard>(id, name, 28, 12, "продажи");
    if (name == "Разработчик") return std::make_unique<CharacterCard>(id, name, 22, 8, "разработка");
    if (name == "Финансовый аналитик") return std::make_unique<CharacterCard>(id, name, 18, 22, "финансы");
    if (name == "Специалист по PR") return std::make_unique<CharacterCard>(id, name, 20, 10, "юриспруденция");
    if (name == "Маркетолог") return std::make_unique<CharacterCard>(id, name, 24, 16, "продажи");
    if (name == "Тестировщик") return std::make_unique<CharacterCard>(id, name, 19, 11, "разработка");
    if (name == "Бухгалтер") return std::make_unique<CharacterCard>(id, name, 21, 19, "финансы");
    if (name == "Юрисконсульт") return std::make_unique<CharacterCard>(id, name, 26, 14, "юриспруденция");
    if (name == "Продажный агент") return std::make_unique<CharacterCard>(id, name, 23, 17, "продажи");
    if (name == "Веб-разработчик") return std::make_unique<CharacterCard>(id, name, 27, 13, "разработка");
    if (name == "Финансовый директор") return std::make_unique<CharacterCard>(id, name, 29, 21, "финансы");
    if (name == "Специалист по интеллектуальной собственности") return std::make_unique<CharacterCard>(id, name, 32, 18, "юриспруденция");
    if (name == "Менеджер по маркетингу") return std::make_unique<CharacterCard>(id, name, 31, 19, "продажи");
    if (name == "Архитектор программного обеспечения") return std::make_unique<CharacterCard>(id, name, 35, 15, "разработка");
    if (name == "Финансовый контроллер") return std::make_unique<CharacterCard>(id, name, 33, 17, "финансы");
    if (name == "Судебный юрист") return std::make_unique<CharacterCard>(id, name, 34, 16, "юриспруденция");
    if (name == "Директор по продажам") return std::make_unique<CharacterCard>(id, name, 36, 14, "продажи");

    return nullptr;
}

std::unique_ptr<ActionCard> CardFactory::createActionCard(const std::string& name, int id) {
    // Создаем карты действий с их эффектами
    if (name == "Подставить коллегу и получить повышение") 
        return std::make_unique<ActionCard>(id, name, -10, 10, -2);
    if (name == "Презентовать большой проект") 
        return std::make_unique<ActionCard>(id, name, 4, -1, 1);
    if (name == "Продать информацию о бизнесе конкурентам") 
        return std::make_unique<ActionCard>(id, name, -20, 25, -5);
    if (name == "Уволить сотрудника") 
        return std::make_unique<ActionCard>(id, name, -5, 5, 1);
    if (name == "Провести корпоративное мероприятие") 
        return std::make_unique<ActionCard>(id, name, 3, -2, 1);
    if (name == "Получить кредит") 
        return std::make_unique<ActionCard>(id, name, 0, 20, -2);
    if (name == "Создать новый отдел") 
        return std::make_unique<ActionCard>(id, name, 2, -10, 3);
    if (name == "Нанять нового сотрудника") 
        return std::make_unique<ActionCard>(id, name, 1, -5, 1);
    if (name == "Провести аудит") 
        return std::make_unique<ActionCard>(id, name, 5, -3, 2);
    if (name == "Создать новый продукт") 
        return std::make_unique<ActionCard>(id, name, 6, -8, 4);

    return nullptr;
}

std::unique_ptr<LeverageCard> CardFactory::createLeverageCard(const std::string& name, int id) {
    // Создаем leverage-карты с их эффектами
    if (name == "Раскрыть статус миграции двоюродной сестры") 
        return std::make_unique<TrustBeforeConditionLeverageCard>(id, name, -10, -5, -4, 50);
    if (name == "Рассказать о твите из прошлого десятелетия") 
        return std::make_unique<LeverageCard>(id, name, -50, 0, -10);
    if (name == "Вызвать налоговую инспекцию") 
        return std::make_unique<LeverageCard>(id, name, -80, -100, -20);
    if (name == "Раскрыть секретную информацию") 
        return std::make_unique<LeverageCard>(id, name, -120, 0, -30);
    if (name == "Обвинить в плагиате") 
        return std::make_unique<LeverageCard>(id, name, -90, -60, -10);

    return nullptr;
}

std::unique_ptr<EndCard> CardFactory::createEndCard(int id) {
    return std::make_unique<EndCard>(id);
} 
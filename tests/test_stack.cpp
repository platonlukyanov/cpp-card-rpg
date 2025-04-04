#include <gtest/gtest.h>
#include "stack.h"
#include "card_factory.h"

class StackTest : public ::testing::Test {
protected:
    void SetUp() override {
        stack = std::make_unique<Stack>();
        factory = std::make_unique<CardFactory>();
    }

    std::unique_ptr<Stack> stack;
    std::unique_ptr<CardFactory> factory;
};

TEST_F(StackTest, IsEmptyReturnsTrueInitially) {
    EXPECT_TRUE(stack->isEmpty());
}

TEST_F(StackTest, PushCardIncreasesSize) {
    auto card = factory->createCard("Тимлид", 1);
    stack->pushCard(std::move(card));
    EXPECT_FALSE(stack->isEmpty());
}

TEST_F(StackTest, DrawCardReturnsCorrectCard) {
    auto card = factory->createCard("Тимлид", 1);
    stack->pushCard(std::move(card));
    
    auto drawnCard = stack->drawCard();
    ASSERT_NE(drawnCard, nullptr);
    EXPECT_EQ(drawnCard->getName(), "Тимлид");
    EXPECT_TRUE(stack->isEmpty());
}

TEST_F(StackTest, DrawCardReturnsNullptrWhenEmpty) {
    auto drawnCard = stack->drawCard();
    EXPECT_EQ(drawnCard, nullptr);
}

TEST_F(StackTest, PopCardReturnsCorrectCard) {
    auto card = factory->createCard("Тимлид", 1);
    stack->pushCard(std::move(card));
    
    auto poppedCard = stack->popCard();
    ASSERT_NE(poppedCard, nullptr);
    EXPECT_EQ(poppedCard->getName(), "Тимлид");
    EXPECT_TRUE(stack->isEmpty());
}

TEST_F(StackTest, PopCardReturnsNullptrWhenEmpty) {
    auto poppedCard = stack->popCard();
    EXPECT_EQ(poppedCard, nullptr);
}

TEST_F(StackTest, ShuffleChangesCardOrder) {
    // Добавляем больше карт для лучшего перемешивания
    stack->pushCard(factory->createCard("Тимлид", 1));
    stack->pushCard(factory->createCard("Финансовый консультант", 2));
    stack->pushCard(factory->createCard("Юрист", 3));
    stack->pushCard(factory->createCard("Менеджер по продажам", 4));
    stack->pushCard(factory->createCard("Разработчик", 5));
    
    // Сохраняем начальный порядок
    std::vector<std::string> initialOrder;
    for (int i = 0; i < 5; ++i) {
        auto card = stack->popCard();
        initialOrder.push_back(card->getName());
        stack->pushCard(std::unique_ptr<Card>(card));
    }
    
    // Перемешиваем несколько раз
    bool orderChanged = false;
    for (int i = 0; i < 10; ++i) {
        stack->shuffle();
        
        // Проверяем, что порядок изменился
        for (int j = 0; j < 5; ++j) {
            auto card = stack->popCard();
            if (card->getName() != initialOrder[j]) {
                orderChanged = true;
                break;
            }
            stack->pushCard(std::unique_ptr<Card>(card));
        }
        
        if (orderChanged) {
            break;
        }
    }
    
    EXPECT_TRUE(orderChanged);
} 
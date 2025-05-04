/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
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
    auto card = factory->createCard("Team Lead", 1);
    stack->pushCard(std::move(card));
    EXPECT_FALSE(stack->isEmpty());
}

TEST_F(StackTest, DrawCardReturnsCorrectCard) {
    auto card = factory->createCard("Team Lead", 1);
    stack->pushCard(std::move(card));
    
    auto drawnCard = stack->drawCard();
    ASSERT_NE(drawnCard, nullptr);
    EXPECT_EQ(drawnCard->getName(), "Team Lead");
    EXPECT_TRUE(stack->isEmpty());
}

TEST_F(StackTest, DrawCardReturnsNullptrWhenEmpty) {
    auto drawnCard = stack->drawCard();
    EXPECT_EQ(drawnCard, nullptr);
}

TEST_F(StackTest, PopCardReturnsCorrectCard) {
    auto card = factory->createCard("Team Lead", 1);
    stack->pushCard(std::move(card));
    
    auto poppedCard = stack->popCard();
    ASSERT_NE(poppedCard, nullptr);
    EXPECT_EQ(poppedCard->getName(), "Team Lead");
    EXPECT_TRUE(stack->isEmpty());
}

TEST_F(StackTest, PopCardReturnsNullptrWhenEmpty) {
    auto poppedCard = stack->popCard();
    EXPECT_EQ(poppedCard, nullptr);
}

TEST_F(StackTest, ShuffleChangesCardOrder) {
    // Adding more cards to improve shuffling
    stack->pushCard(factory->createCard("Team Lead", 1));
    stack->pushCard(factory->createCard("Financial Consultant", 2));
    stack->pushCard(factory->createCard("Lawyer", 3));
    stack->pushCard(factory->createCard("Sales Manager", 4));
    stack->pushCard(factory->createCard("Developer", 5));
    
    // Keep initial order 
    std::vector<std::string> initialOrder;
    for (int i = 0; i < 5; ++i) {
        auto card = stack->popCard();
        initialOrder.push_back(card->getName());
        stack->pushCard(std::unique_ptr<Card>(card));
    }
    
    // Shuffle multiple times
    bool orderChanged = false;
    for (int i = 0; i < 10; ++i) {
        stack->shuffle();
        
        // Check if order changed
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
TEST_F(StackTest, FetchPlayersCardsReturnsCorrectCards) {
    stack->pushCard(factory->createCard("Team Lead", 1));
    stack->pushCard(factory->createCard("Financial Consultant", 2));
    stack->pushCard(factory->createCard("Lawyer", 3));
    stack->pushCard(factory->createCard("Sales Manager", 4));
    stack->pushCard(factory->createCard("Developer", 5));
    
    auto cards = stack->fetchPlayersCards(3);
    EXPECT_EQ(cards.size(), 3) << "Expected 3 cards to be fetched";

    EXPECT_TRUE(cards[0]->getName() == "Developer") << "Card 0 name mismatch: expected 'Developer', got '" << cards[0]->getName() << "'";
    EXPECT_TRUE(cards[1]->getName() == "Sales Manager") << "Card 1 name mismatch: expected 'Sales Manager', got '" << cards[1]->getName() << "'";
    EXPECT_TRUE(cards[2]->getName() == "Lawyer") << "Card 2 name mismatch: expected 'Lawyer', got '" << cards[2]->getName() << "'";
}

TEST_F(StackTest, FetchPlayersCardsLeavesExactlyNMinusPlayersCount) {
    stack->pushCard(factory->createCard("Lawyer", 3));
    stack->pushCard(factory->createCard("Present a big project", 4));
    stack->pushCard(factory->createCard("Sales Manager", 4));
    stack->pushCard(factory->createCard("Developer", 5));
    
    auto cards = stack->fetchPlayersCards(3);
    EXPECT_EQ(cards.size(), 3) << "Expected 3 cards to be fetched";
    EXPECT_EQ(stack->isEmpty(), false);
}


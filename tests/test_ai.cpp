/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include <gtest/gtest.h>

#include "ai.h"
#include "card_factory.h"
#include "stack.h"

class AITest : public ::testing::Test {
    protected:
        void SetUp() override {
            factory = std::make_unique<CardFactory>();
            stack = std::make_unique<Stack>();
            ai = std::make_unique<AI>("ai_id", "ai_secret");

            // Adding cards to the stack
            stack->pushCard(factory->createCard(
                "Frame a colleague and get a promotion", 2));
            stack->pushCard(factory->createCard(
                "Reveal the migration status of a cousin", 3));
            stack->pushCard(factory->createCard("Financial Consultant", 1));
        }

        std::unique_ptr<CardFactory> factory;
        std::unique_ptr<Stack> stack;
        std::unique_ptr<AI> ai;
};

TEST_F(AITest, GetIdReturnsCorrectValue) {
    EXPECT_EQ(ai->getId(), "ai_id");
}

TEST_F(AITest, GetSecretReturnsCorrectValue) {
    EXPECT_EQ(ai->getSecret(), "ai_secret");
}

TEST_F(AITest, MakeMoveReturnsValidMove) {
    ai->setDepartment("finance");
    auto move = ai->makeMove(*stack);
    ASSERT_NE(move, nullptr);
    EXPECT_TRUE(move->isAbleToAccept());
}

TEST_F(AITest, MakeMoveReturnsNullptrWhenNoCards) {
    stack = std::make_unique<Stack>();
    auto move = ai->makeMove(*stack);
    EXPECT_EQ(move, nullptr);
}

TEST_F(AITest, MakeMoveReturnsNullptrWhenInvalidDepartment) {
    ai->setDepartment("development");
    auto move = ai->makeMove(*stack);
    EXPECT_EQ(move, nullptr);
}

TEST_F(AITest, MakeMoveUpdatesPlayerStats) {
    ai->setDepartment("finance");
    auto move = ai->makeMove(*stack);
    ASSERT_NE(move, nullptr);
    move->accept();

    EXPECT_EQ(ai->getReputation(), 2);
    EXPECT_EQ(ai->getTrust(), 11);  // 10 (base) + 10 (from character card)
}
#include <gtest/gtest.h>
#include "card.h"
#include "character_card.h"

class CardTest : public ::testing::Test {
protected:
    void SetUp() override {
        card = std::make_unique<CharacterCard>(1, "Тестовая карта", 10, 10, "тест");
    }

    std::unique_ptr<Card> card;
};

TEST_F(CardTest, GetIdReturnsCorrectId) {
    EXPECT_EQ(card->getId(), 1);
}

TEST_F(CardTest, GetTypeReturnsCorrectType) {
    EXPECT_EQ(card->getType(), Card::Type::CHARACTER);
}

TEST_F(CardTest, GetNameReturnsCorrectName) {
    EXPECT_EQ(card->getName(), "Тестовая карта");
} 
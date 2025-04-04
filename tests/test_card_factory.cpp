#include <gtest/gtest.h>
#include "card_factory.h"
#include "card.h"

class CardFactoryTest : public ::testing::Test {
protected:
    void SetUp() override {
        factory = std::make_unique<CardFactory>();
    }

    std::unique_ptr<CardFactory> factory;
};

TEST_F(CardFactoryTest, CreateCharacterCard) {
    auto card = factory->createCard("Тимлид", 1);
    ASSERT_NE(card, nullptr);
    EXPECT_EQ(card->getType(), Card::Type::CHARACTER);
    EXPECT_EQ(card->getName(), "Тимлид");
}

TEST_F(CardFactoryTest, CreateActionCard) {
    auto card = factory->createCard("Подставить коллегу и получить повышение", 1);
    ASSERT_NE(card, nullptr);
    EXPECT_EQ(card->getType(), Card::Type::ACTION);
    EXPECT_EQ(card->getName(), "Подставить коллегу и получить повышение");
}

TEST_F(CardFactoryTest, CreateLeverageCard) {
    auto card = factory->createCard("Раскрыть статус миграции двоюродной сестры", 1);
    ASSERT_NE(card, nullptr);
    EXPECT_EQ(card->getType(), Card::Type::LEVERAGE);
    EXPECT_EQ(card->getName(), "Раскрыть статус миграции двоюродной сестры");
}

TEST_F(CardFactoryTest, CreateEndCard) {
    auto card = factory->createCard("Смерть CEO", 1);
    ASSERT_NE(card, nullptr);
    EXPECT_EQ(card->getType(), Card::Type::END);
    EXPECT_EQ(card->getName(), "Смерть CEO");
}

TEST_F(CardFactoryTest, CreateUnknownCardReturnsNullptr) {
    auto card = factory->createCard("Неизвестная карта", 1);
    EXPECT_EQ(card, nullptr);
} 
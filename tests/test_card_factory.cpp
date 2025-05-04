/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
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
    auto card = factory->createCard("Team Lead", 1);
    ASSERT_NE(card, nullptr);
    EXPECT_EQ(card->getType(), Card::Type::CHARACTER);
    EXPECT_EQ(card->getName(), "Team Lead");
}

TEST_F(CardFactoryTest, CreateActionCard) {
    auto card = factory->createCard("Frame a colleague and get a promotion", 1);
    ASSERT_NE(card, nullptr);
    EXPECT_EQ(card->getType(), Card::Type::ACTION);
    EXPECT_EQ(card->getName(), "Frame a colleague and get a promotion");
}

TEST_F(CardFactoryTest, CreateLeverageCard) {
    auto card = factory->createCard("Reveal the migration status of a cousin", 1);
    ASSERT_NE(card, nullptr);
    EXPECT_EQ(card->getType(), Card::Type::LEVERAGE);
    EXPECT_EQ(card->getName(), "Reveal the migration status of a cousin");
}

TEST_F(CardFactoryTest, CreateEndCard) {
    auto card = factory->createCard("CEO Death", 1);
    ASSERT_NE(card, nullptr);
    EXPECT_EQ(card->getType(), Card::Type::END);
    EXPECT_EQ(card->getName(), "CEO Death");
}

TEST_F(CardFactoryTest, CreateUnknownCardReturnsNullptr) {
    auto card = factory->createCard("Unknown Card", 1);
    EXPECT_EQ(card, nullptr);
} 
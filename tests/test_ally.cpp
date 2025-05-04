#include <gtest/gtest.h>
#include "ally.h"
#include "character_card.h"

class AllyTest : public ::testing::Test {
protected:
    void SetUp() override {
        character = std::make_unique<CharacterCard>(1, "Test character", 30, 20, "development");
        ally = std::make_unique<Ally>(*character);
    }

    std::unique_ptr<CharacterCard> character;
    std::unique_ptr<Ally> ally;
};

TEST_F(AllyTest, GetNameReturnsCorrectValue) {
    EXPECT_EQ(ally->getName(), "Test character");
}

TEST_F(AllyTest, GetReputationReturnsCorrectValue) {
    EXPECT_EQ(ally->getReputation(), 30);
}

TEST_F(AllyTest, GetMoneyReturnsCorrectValue) {
    EXPECT_EQ(ally->getMoney(), 20);
}

TEST_F(AllyTest, GetDepartmentReturnsCorrectValue) {
    EXPECT_EQ(ally->getDepartment(), "development");
} 
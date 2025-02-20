#include <gtest/gtest.h>

#include "Square.h"

TEST(SquareTest, AreaAndPerimeter) {
    Point topLeft(0.0, 0.0);
    Square square(topLeft, 5.0);

    EXPECT_EQ(square.area(), 25.0);       // Area = side^2 = 5^2
    EXPECT_EQ(square.perimeter(), 20.0);  // Perimeter = 4 * side = 4 * 5
}

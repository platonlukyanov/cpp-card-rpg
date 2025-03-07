#include <gtest/gtest.h>
#include "Point.h"

TEST(PointTest, Initialization) {
    Point p(3.0, 4.0);
    EXPECT_EQ(p.getX(), 3.0);
    EXPECT_EQ(p.getY(), 4.0);
}

TEST(PointTest, Setters) {
    Point p;
    p.setX(5.0);
    p.setY(6.0);
    EXPECT_EQ(p.getX(), 5.0);
    EXPECT_EQ(p.getY(), 6.0);
}

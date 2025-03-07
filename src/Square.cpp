#include "Square.h"

Square::Square(const Point& topLeft, double sideLength)
    : topLeft(topLeft), sideLength(sideLength) {
}

double Square::area() const {
    return sideLength * sideLength;
}

double Square::perimeter() const {
    return 4 * sideLength;
}

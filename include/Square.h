#ifndef SQUARE_H
#define SQUARE_H

#include "Point.h"

class Square {
    public:
        Square(const Point& topLeft, double sideLength);
        double area() const;
        double perimeter() const;

    private:
        Point topLeft;
        double sideLength;
};

#endif  // SQUARE_H

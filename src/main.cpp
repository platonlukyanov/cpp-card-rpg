#include <iostream>

#include "Point.h"
#include "Square.h"

int main() {
    Point p1(0.0, 0.0);
    Point p2(5.0, 5.0);
    Square square(p1, 5.0);

    std::cout << "Area of square: " << square.area() << std::endl;
    std::cout << "Perimeter of square: " << square.perimeter() << std::endl;

    return 0;
}

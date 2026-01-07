#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point p1(2, 2);
    Point p2(10, 10);

    std::cout << bsp(a, b, c, p1) << std::endl;
    std::cout << bsp(a, b, c, p2) << std::endl;
}

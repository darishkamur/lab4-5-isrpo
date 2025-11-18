#pragma once
#include <cmath>
#include <stdexcept>

namespace triangle {

struct sides {
    double a, b, c;
};

double perimeter(double a, double b, double c);
double area(double a, double b, double c);

} // namespace triangle
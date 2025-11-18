#include "triangle.h"
#include <cmath>
#include <stdexcept>

namespace triangle {

double perimeter(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0)
        throw std::invalid_argument("All sides must be positive");
    if (a + b <= c || a + c <= b || b + c <= a)
        throw std::invalid_argument("Triangle inequality violated");
    return a + b + c;
}

double area(double a, double b, double c) {
    // Проверка корректности — переиспользуем perimeter (он уже проверяет)
    double p = perimeter(a, b, c);
    double s = p / 2.0;
    double area_sq = s * (s - a) * (s - b) * (s - c);
    if (area_sq < 0)
        throw std::logic_error("Negative area under sqrt (should not happen if perimeter passed)");
    return std::sqrt(area_sq);
}

} // namespace triangle
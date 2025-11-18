#include "triangle.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept>

double trianglePerimeter(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0)
        throw std::invalid_argument("Sides must be positive");
    if (a + b <= c || a + c <= b || b + c <= a)
        throw std::invalid_argument("Triangle inequality violated");
    return a + b + c;
}

double triangleArea(double a, double b, double c) {
    double p = trianglePerimeter(a, b, c);
    double s = p / 2.0;
    double area2 = s * (s - a) * (s - b) * (s - c);
    if (area2 < 0) area2 = 0;
    return std::sqrt(area2);
}

void assertEquals(double got, double expected, double eps = 1e-9, const char* msg = "") {
    if (std::abs(got - expected) > eps) {
        std::cerr << "FAIL: " << msg << " — expected " << expected << ", got " << got << std::endl;
        exit(1);
    }
}

void assertThrows(const std::function<void()>& fn, const char* msg = "") {
    try {
        fn();
        std::cerr << "FAIL: " << msg << " — expected exception, but none thrown" << std::endl;
        exit(1);
    } catch (const std::exception&) {
       
    }
}

int main() {
    std::cout << "Running triangle unit tests...\n";

    // Тест 1: периметр 3-4-5
    assertEquals(trianglePerimeter(3, 4, 5), 12.0, 1e-9, "Perimeter 3-4-5");

    // Тест 2: площадь 3-4-5 = 6
    assertEquals(triangleArea(3, 4, 5), 6.0, 1e-9, "Area 3-4-5");

    // Тест 3: равносторонний треугольник a=2 → S = sqrt(3)
    assertEquals(triangleArea(2, 2, 2), std::sqrt(3.0), 1e-9, "Area equilateral a=2");

    // Тест 4: нулевая сторона — исключение
    assertThrows([](){ trianglePerimeter(0, 4, 5); }, "Zero side");

    // Тест 5: нарушение неравенства — исключение
    assertThrows([](){ triangleArea(1, 2, 5); }, "Triangle inequality");

    std::cout << "✅ All tests passed!\n";
    return 0;
}
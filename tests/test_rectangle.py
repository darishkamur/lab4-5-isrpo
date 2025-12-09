import unittest
from src.rectangle import area, perimeter


class RectangleTestCase(unittest.TestCase):

    # Тесты для area()
    def test_area_positive(self):
        self.assertEqual(area(5, 10), 50)

    def test_area_square(self):
        self.assertEqual(area(7, 7), 49)

    def test_area_zero(self):
        self.assertEqual(area(0, 10), 0)
        self.assertEqual(area(5, 0), 0)
        self.assertEqual(area(0, 0), 0)

    def test_area_negative_side_raises_error(self):
        with self.assertRaises(ValueError):
            area(-1, 5)
        with self.assertRaises(ValueError):
            area(5, -3)
        with self.assertRaises(ValueError):
            area(-2, -4)

    # Тесты для perimeter()
    def test_perimeter_positive(self):
        self.assertEqual(perimeter(5, 10), 30)

    def test_perimeter_square(self):
        self.assertEqual(perimeter(6, 6), 24)

    def test_perimeter_zero(self):
        self.assertEqual(perimeter(0, 10), 20)
        self.assertEqual(perimeter(7, 0), 14)
        self.assertEqual(perimeter(0, 0), 0)

    def test_perimeter_negative_side_raises_error(self):
        with self.assertRaises(ValueError):
            perimeter(-1, 5)
        with self.assertRaises(ValueError):
            perimeter(3, -2)
        with self.assertRaises(ValueError):
            perimeter(-1, -1)


if __name__ == '__main__':
    unittest.main()
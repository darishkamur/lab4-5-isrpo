## Unit-тесты (Лабораторная №4)

Реализован модуль `rectangle.py` с функциями:
- `area(a, b)` — площадь прямоугольника;
- `perimeter(a, b)` — периметр.

Написаны unit-тесты с использованием `unittest`.  
Запуск тестов:
```bash
python3 -m unittest discover -s tests -p "test_*.py" -v
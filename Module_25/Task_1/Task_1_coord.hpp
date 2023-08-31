#ifdef __MODULE_25__

/* Заголовочный файл Module_25/Task_1 */
#pragma once

#include <iostream>
#include <string>
#include <sstream>

// точность сравнения
#define EPS 0.00001

// структура координаты
struct S_Coordinate {
    double x;
    double y;
};

// функция ввода координаты, возвращает валидность (не)введенной координаты
static bool parse_coordinate(std::stringstream& ss, S_Coordinate& result) {
    std::string num1, num2;
    ss >> num1 >> num2;
    if (num1.length() && num2.length()) {
        result.x = std::stod(num1);
        result.y = std::stod(num2);

        return true;
    } else {
        return false;
    }
}

// функция сравнения на равенство двух координат
static bool coord_equal(const S_Coordinate& c1, const S_Coordinate& c2) {
    return ((c1.x > c2.x - EPS) && (c1.x < c2.x + EPS) &&
            (c1.y > c2.y - EPS) && (c1.y < c2.y + EPS));
}

// функция вывода на экран координаты
static void print_coordinate(const S_Coordinate& c) {
    std::cout << "(" << c.x << ", " << c.y << ")";
}

#endif

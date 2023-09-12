#ifdef __MODULE_27__
/* Задание 2. Иерархия геометрических фигур
 *  Что нужно сделать
 *  Спроектируйте иерархию классов различных фигур: круг, квадрат, равносторонний треугольник,
 *  прямоугольник.
 *  Для всех этих фигур есть общие поля-данные — это координаты их центра и условный цвет фигуры:
 *  красный, синий или зелёный.
 *  Для отдельных фигур есть и уникальные параметры: радиус для круга, длина ребра для квадрата и
 *  равностороннего треугольника, ширина и высота для прямоугольника. Все данные — это вещественные
 *  числа с удвоенной точностью.
 *  Для каждой из фигур требуется определить метод нахождения площади фигуры, а также метод
 *  нахождения прямоугольника, описывающего фигуру полностью (он может быть больше зоны фигуры, но
 *  не меньше).
 *  Для лучшего понимания задачи приведена иллюстрация. На ней разными цветами помечены площади
 *  фигур, а пунктиром изображены прямоугольники, описывающие фигуры.
 *  Для теста предусмотрите ввод пользователем команд: circle, square, triangle, rectangle,
 *  соответствующих фигурам. Команды должны получать параметры фигур и выводить их цвет, площадь и
 *  описывающий прямоугольник с координатами.
 *  
 *  Советы и рекомендации:
 *  Для цвета фигуры вы можете использовать собственный тип enum, в котором может содержаться и
 *  константа отсутствия цвета — None.
 *  Площадь треугольника считается как length * length * std::sqrt(3) / 4; где length — сторона.
 *  Площадь круга — как atan(1) * 4 * radius;
 *  Геометрические формулы вы можете найти в интернете. */

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "../Module_27.hpp"
#include "Figures.hpp"

static void help() {
    std::cout << "  circle <radius>            - выдача данных по кругу\n";
    std::cout << "  square <edge length>       - выдача данных по квадрату\n";
    std::cout << "  triangle <edge length>     - выдача данных по треугольнику\n";
    std::cout << "  rectangle <width> <height> - выдача данных по прямоугольнику\n";
    std::cout << "  color <color>              - смена цвета будущей фигуры (число или строка)\n";
    std::cout << "  center <x> <y>             - смена координаты центра будущей фигуры\n";
    std::cout << "  help                       - вывод данного сообщения\n";
    std::cout << "  exit                       - выход из задания\n";
    std::cout << "ВНИМАНИЕ! ВВОД ВЕЩЕСТВЕННЫХ ЧИСЕЛ МОЖЕТ ОСУЩЕСТВЛЯТЬСЯ ЧЕРЕЗ ЗАПЯТУЮ!\n";
    std::cout << "ATTENTION! THE INPUT OF REAL NUMBERS CAN BE SEPARATED BY COMMAS!\n";
    std::cout << "\n";
}

static bool check_double(std::string numStr) {
    int points = 0;
    bool rightNumber = false;
    for (unsigned int i = (numStr[0] == '-' || numStr[0] == '+'); i < numStr.length(); i++) {
        if (numStr[i] >= '0' && numStr[i] <= '9')
            rightNumber = true;
        else if (!points && numStr[i] == ',')
            points++;
        else {
            rightNumber = false;
            break;
        }
    }
    return rightNumber;
}

static bool check_uint(std::string numStr) {
    for (unsigned int i = 0; i < numStr.length(); i++) {
        if (numStr[i] < '0' || numStr[i] > '9') {
            return false;
        }
    }
    return true;
}

static void circle_command(std::string part_command, Figure* figure) {
    Circle* circle = (Circle *)figure;
    std::string radius, err;
    std::stringstream buf(part_command);

    buf >> radius >> err;
    if (radius.length() && !err.length() && check_double(radius)) {
        Coordinates left_top, right_bottom;
        circle->set_radius(std::stod(radius));
        circle->get_covering_rect(left_top, right_bottom);

        std::cout << "    Радиус круга: " << circle->get_radius() << "\n";
        std::cout << "    Площадь круга: " << circle->sqr() << "\n";
        std::cout << "    Цвет заполнения круга: " << Colors[(unsigned int)circle->get_color()] << "\n";
        std::cout << "    Координаты описывающего прямоугольника: "
                  << "(" << left_top.get_x() << ", " << left_top.get_y() << ") и "
                  << "(" << right_bottom.get_x() << ", " << right_bottom.get_y() << ")" << "\n";
    } else {
        std::cout << "Команда не распознана!\n";
    }
}

static void square_command(std::string part_command, Figure* figure) {
    Square* square = (Square *)figure;
    std::string edgeLength, err;
    std::stringstream buf(part_command);

    buf >> edgeLength >> err;
    if (edgeLength.length() && !err.length() && check_double(edgeLength)) {
        Coordinates left_top, right_bottom;
        square->set_edge_length(std::stod(edgeLength));
        square->get_covering_rect(left_top, right_bottom);

        std::cout << "    Длина ребра квадрата: " << square->get_edge_length() << "\n";
        std::cout << "    Площадь квадрата: " << square->sqr() << "\n";
        std::cout << "    Цвет заполнения квадрата: " << Colors[(unsigned int)square->get_color()] << "\n";
        std::cout << "    Координаты описывающего прямоугольника: "
                  << "(" << left_top.get_x() << ", " << left_top.get_y() << ") и "
                  << "(" << right_bottom.get_x() << ", " << right_bottom.get_y() << ")" << "\n";
    } else {
        std::cout << "Команда не распознана!\n";
    }
}

static void triangle_command(std::string part_command, Figure* figure) {
    Triangle* triangle = (Triangle *)figure;
    std::string edgeLength, err;
    std::stringstream buf(part_command);

    buf >> edgeLength >> err;
    if (edgeLength.length() && !err.length() && check_double(edgeLength)) {
        Coordinates left_top, right_bottom;
        triangle->set_edge_length(std::stod(edgeLength));
        triangle->get_covering_rect(left_top, right_bottom);

        std::cout << "    Длина ребра треугольника: " << triangle->get_edge_length() << "\n";
        std::cout << "    Площадь треугольника: " << triangle->sqr() << "\n";
        std::cout << "    Цвет заполнения круга: " << Colors[(unsigned int)triangle->get_color()] << "\n";
        std::cout << "    Координаты описывающего прямоугольника: "
                  << "(" << left_top.get_x() << ", " << left_top.get_y() << ") и "
                  << "(" << right_bottom.get_x() << ", " << right_bottom.get_y() << ")" << "\n";
    } else {
        std::cout << "Команда не распознана!\n";
    }
}

static void rectangle_command(std::string part_command, Figure* figure) {
    Rectangle* rectangle = (Rectangle *)figure;
    std::string width, height, err;
    std::stringstream buf(part_command);

    buf >> width >> height >> err;
    if (width.length() && height.length() && !err.length() && check_double(width) && check_double(height)) {
        Coordinates left_top, right_bottom;
        rectangle->set_width(std::stod(width));
        rectangle->set_height(std::stod(height));
        rectangle->get_covering_rect(left_top, right_bottom);

        std::cout << "    Ширина прямоугольника: " << rectangle->get_width() << "\n";
        std::cout << "    Высота прямоугольника: " << rectangle->get_height() << "\n";
        std::cout << "    Площадь прямоугольника: " << rectangle->sqr() << "\n";
        std::cout << "    Цвет заполнения круга: " << Colors[(unsigned int)rectangle->get_color()] << "\n";
        std::cout << "    Координаты описывающего прямоугольника: "
                  << "(" << left_top.get_x() << ", " << left_top.get_y() << ") и "
                  << "(" << right_bottom.get_x() << ", " << right_bottom.get_y() << ")" << "\n";
    } else {
        std::cout << "Команда не распознана!\n";
    }
}

static void change_color(std::string part_command, Figure* figure) {
    std::string n, err;
    std::stringstream buf(part_command);

    buf >> n >> err;
    if (n.length() && !err.length()) {
        if (check_uint(n)) {
            unsigned int color = std::stol(n);
            if (color < (unsigned int)Color::size) {
                figure->set_color((Color)color);
            } else {
                std::cout << "Такого цвета в списке цветов нет!\n";
            }
        } else {
            bool found = false;
            for (unsigned int i = 0; i < (unsigned int)Color::size; i++) {
                if (n == Colors[i]) {
                    figure->set_color((Color)i);
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Такого цвета в списке цветов нет!\n";
            }
        }
    } else {
        std::cout << "Команда не распознана!\n";
    }
}

static void change_center(std::string part_command, Figure* figure) {
    std::string x, y, err;
    std::stringstream buf(part_command);

    buf >> x >> y >> err;
    if (x.length() && y.length() && !err.length() && check_double(x) && check_double(y)) {
        Coordinates c(std::stod(x), std::stod(y));
        figure->set_coordinates(c);
    } else {
        std::cout << "Команда не распознана!\n";
    }
}

void Task_27_2() {
    std::cout << equals << string_tasks[1] << equals;

    // очистка буфера ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string command, operation;
    Figure * figure = new Figure;
    do {
        std::cout << "Введите команду: ";
        std::getline(std::cin, command);
        std::stringstream buffer(command);

        buffer >> operation;
        if (command == "help") {
            help();
        } else if (command == "exit") {
            std::cout << "Работа с заданием окончена!\n";
            break;
        } else if (operation == "circle" && (command.length() > operation.length() + 1)) {
            circle_command(buffer.str().substr(operation.length() + 1), figure);
        } else if (operation == "square" && (command.length() > operation.length() + 1)) {
            square_command(buffer.str().substr(operation.length() + 1), figure);
        } else if (operation == "triangle" && (command.length() > operation.length() + 1)) {
            triangle_command(buffer.str().substr(operation.length() + 1), figure);
        } else if (operation == "rectangle" && (command.length() > operation.length() + 1)) {
            rectangle_command(buffer.str().substr(operation.length() + 1), figure);
        } else if (operation == "color" && (command.length() > operation.length() + 1)) {
            change_color(buffer.str().substr(operation.length() + 1), figure);
        } else if (operation == "center" && (command.length() > operation.length() + 1)) {
            change_center(buffer.str().substr(operation.length() + 1), figure);
        } else {
            std::cout << "Команда не распознана! Введите \"help\" для помощи.\n";
        }
    } while(true);

    delete figure;
}
#endif

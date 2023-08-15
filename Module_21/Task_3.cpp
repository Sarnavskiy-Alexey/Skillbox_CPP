#ifdef __MODULE_21__
/* Задание 3. Математический вектор
 *  Что нужно сделать
 *  Реализуйте структуру двумерного математического вектора и основные операции над ним. Обе
 *  координаты вектора (x и y) должны быть вещественными числами.
 *  Начиная работу с программой, пользователь вводит команду. Затем в зависимости от команды
 *  пользователь вводит аргументы. Это могут быть как векторы, так и обычные скалярные значения.
 *  Результат помещается в стандартный вывод. Это тоже может быть или вектор, или скаляр.
 *  
 *  Реализуйте в виде отдельных функций операции:
 *  - сложение двух векторов — команда add;
 *  - вычитание двух векторов — команда subtract;
 *  - умножение вектора на скаляр — команда scale;
 *  - нахождение длины вектора — команда length;
 *  - нормализация вектора — команда normalize.
 *  
 *  Советы и рекомендации
 *  Для выбора команды используйте конструкцию вида if (operation == "add"). Тут так и напрашиваются
 *  отдельные функции для каждой операции. */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Module_21.hpp"

// структура для вывода в help
struct FAQ_type {
    std::string operation;   // название операции
    std::string description; // описание операции
};

// FAQ
const static std::vector<FAQ_type> FAQ = {
    { "help", "вывод FAQ на экран" },
    { "add", "сложение двух векторов" },
    { "subtract", "вычитание двух векторов" },
    { "scale", "умножение вектора на скаляр" },
    { "length", "нахождение длины вектора" },
    { "normalize", "нормализация вектора" },
    { "exit", "окончание задания" }
};

// структура математического вектора
struct math_vector {
    double x = 0.0; // координата X
    double y = 0.0; // координата Y
};

// функция ввода вектора
static void cin_math_vector(math_vector& result) {
    std::cout << "Введите вектор (координаты X и Y): ";
    std::cin >> result.x >> result.y;
}

// функция для ввода скаляра
static void cin_scalar(double& result) {
    std::cout << "Введите скаляр (вещественное число): ";
    std::cin >> result;
}

// функция сложения двух векторов
static math_vector add(const math_vector& a, const math_vector& b) {
    return { (a.x + b.x),
             (a.y + b.y) };
}

// функция вычитания двух векторов
static math_vector subtract(const math_vector& a, const math_vector& b) {
    return { (a.x - b.x),
             (a.y - b.y) };
}

// функция умножения вектора на скаляр
static math_vector scale(const math_vector& a, const double mult) {
    return { (a.x * mult),
             (a.y * mult) };
}

// функция нахождения длины вектора
static double length(const math_vector& a) {
    return std::sqrt((a.x * a.x) + (a.y * a.y));
}

// функция нормализации вектора
static math_vector normalize(const math_vector& a) {
    return scale(a, 1.0 / length(a));
}

void Task_21_3() {
    std::cout << equals << string_tasks[2] << equals;

    std::string operation;
    do {
        std::cout << "Введите операцию (help - помощь): ";
        std::cin >> operation;
        if (operation == FAQ[0].operation) {
            std::cout << "Возможные операции:\n";
            for (const FAQ_type& f : FAQ) {
                std::cout << "\t" << f.operation << " - " << f.description << "\n";
            }
        } else if (operation == FAQ[1].operation) {
            math_vector a, b, result;
            
            // ввод двух векторов и расчет их суммы
            cin_math_vector(a);
            cin_math_vector(b);
            result = add(a, b);

            std::cout << "Результат: (" << result.x << ", " << result.y << ")\n";
        } else if (operation == FAQ[2].operation) {
            math_vector a, b, result;
            
            // ввод двух векторов и расчет разности между ними
            cin_math_vector(a);
            cin_math_vector(b);
            result = subtract(a, b);

            std::cout << "Результат: (" << result.x << ", " << result.y << ")\n";
        } else if (operation == FAQ[3].operation) {
            math_vector a, result;
            double mult;
            
            // ввод вектора и скаляра и расчет умножения вектора на скаляр
            cin_math_vector(a);
            cin_scalar(mult);
            result = scale(a, mult);

            std::cout << "Результат: (" << result.x << ", " << result.y << ")\n";
        } else if (operation == FAQ[4].operation) {
            math_vector a;
            double result;
            
            // ввод одного вектора и расчет его длины
            cin_math_vector(a);
            result = length(a);

            std::cout << "Результат: " << result << "\n";
        } else if (operation == FAQ[5].operation) {
            math_vector a, result;
            
            // ввод одного вектора и его нормализация
            cin_math_vector(a);
            if (length(a) > 0.0) {
                result = normalize(a);
                std::cout << "Результат: (" << result.x << ", " << result.y << ")\n";
            } else
                std::cout << "Нормализация невозможна, так как длина вектора равна нулю!\n";
        } else if (operation == FAQ[6].operation) {
            std::cout << "Работа с заданием завершена!\n";
        } else {
            std::cout << "Такая операция отсутствует!\n";
        }
    } while (operation != FAQ[6].operation);
}
#endif

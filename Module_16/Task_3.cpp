#ifdef __MODULE_16__
/* Задание 3. Калькулятор
 *  Что нужно сделать
 *  Создайте небольшую программу для вычисления простых действий с числами. При запуске программа
 *  ожидает пользовательского ввода во временную переменную строку. После ввода строки она
 *  распарсивается на отдельные члены. Строка записывается в форме “<число-1><действие><число-2>”
 *  (без пробелов). Оба числа — это значения с плавающей точкой, повышенной точности (double).
 *  Действие может быть одним из: +, −, /, *. Результат действия выводится в стандартный вывод cout.
 *  
 *  Рекомендации:
 *  Чтобы разделить полученную строку на отдельные элементы — числа и оператор, воспользуйтесь
 *  строковым потоком. Для этого создайте пустую строку std::string buffer и дайте пользователю
 *  возможность при помощи std::cin ввести в неё команду. Затем оберните полученную строку так:
 *  std::stringstream buffer_stream(buffer); Это позволит вам  получить каждый из трёх компонентов
 *  команды: buffer_stream >> a >> operation >> b; */

#include <iostream>
#include <sstream>
#include "Module_16.hpp"

enum class operations {
    plus = '+',
    minus = '-',
    mult = '*',
    div = '/'
};

void Task_16_3() {
    std::cout << equals << string_tasks[2] << equals;

    std::string buffer;
    std::cout << "Введите команду: ";
    std::cin >> buffer;

    std::stringstream buffer_stream(buffer);
    long long number_1, number_2;
    char op;
    buffer_stream >> number_1 >> op >> number_2;

    switch (op) {
        case char(operations::plus):
            std::cout << "Результат вычисления: " << number_1 + number_2;
            break;
        case char(operations::minus):
            std::cout << "Результат вычисления: " << number_1 - number_2;
            break;
        case char(operations::mult):
            std::cout << "Результат вычисления: " << number_1 * number_2;
            break;
        case char(operations::div):
            std::cout << "Результат вычисления: " << number_1 / number_2;
            break;
        default: std::cout << "Неизвестная операция!";
    }
    std::cout << "\n";
}
#endif

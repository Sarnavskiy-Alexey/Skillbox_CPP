#ifdef __MODULE_16__
/* Задание 2. Сшиватель дробных чисел
 *  Что нужно сделать
 *  Напишите небольшую программу. Из целой и дробной частей числа, которые в отдельности вводит
 *  пользователь, составьте новое число с плавающей точкой (типа double) и выведите это число
 *  обратно в консоль для проверки. Целая часть — это часть числа, которая находится до точки
 *  (запятой), дробная — после.
 *  Рекомендации:
 *  Вам потребуется функция StringToDouble — std::stod. Она принимает на вход строку, содержащую в
 *  себе число. */

#include <iostream>
#include <string>
#include "Module_16.hpp"

void Task_16_2() {
    std::cout << equals << string_tasks[1] << equals;

    int int_part, fract_part;
    std::cout << "Введите целую часть числа: ";
    std::cin >> int_part;
    std::cout << "Введите дробную часть числа: ";
    std::cin >> fract_part;

    std::string fraction_str;
    fraction_str = std::to_string(int_part) + "," + std::to_string(fract_part);
    std::cout << "Полученное число: " << std::stod(fraction_str) << "\n";
}
#endif

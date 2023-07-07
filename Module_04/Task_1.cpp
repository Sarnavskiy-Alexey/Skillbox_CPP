/* Задание 1. Минимум из двух чисел
 *  Напишите программу, которая ищет минимальное значение из двух чисел. */

#include <iostream>
#include "Module_04.hpp"

void Task_04_1() {
    std::cout << equals << string_tasks[0] << equals;
    
    int a, b;
    
    std::cout << "Введите число a: ";
    std::cin >> a;
    std::cout << "Введите число b: ";
    std::cin >> b;
    
    std::cout << "\n----------------Проверка----------------\n\n";
    
    
    if (a < b)
        std::cout << "Минимальное значение: " << a << ".\n";
    else if (a > b)
        std::cout << "Минимальное значение: " << b << ".\n";
    else
        std::cout << "Числа равны!\n";
}
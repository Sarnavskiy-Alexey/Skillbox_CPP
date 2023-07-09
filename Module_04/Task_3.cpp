#ifdef __MODULE_04__
/* Задание 3. Проверка на чётное число
 *  Напишите программу, которая проверяет, чётное ли число ввел пользователь.
 *  Пример: int remainder = x % 2 (вычисляет остаток от деления `x` на 2). */

#include <iostream>
#include "Module_04.hpp"

void Task_04_3() {
    std::cout << equals << string_tasks[2] << equals;

    int userNumber;
    std::cout << "Введите целое число: ";
    std::cin >> userNumber;

    std::cout << "\n----------------Проверка----------------\n\n";
    
    if (userNumber % 2)
        std::cout << "Число " << userNumber << " - нечетное\n";
    else
        std::cout << "Число " << userNumber << " - четное\n";
}
#endif

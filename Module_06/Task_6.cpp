/* Задание 6. Вклады
 *  Вклад в банке составляет X рублей. Ежегодно он увеличивается на P процентов, после чего дробная
 *  часть копеек отбрасывается. Определите, через сколько лет вклад составит не менее Y рублей.
 *  Напишите программу, которая по данным числам X, Y, P определяет, сколько лет пройдёт, прежде
 *  чем сумма достигнет значения Y. */

#include <iostream>
#include "Module_06.hpp"

void Task_06_6() {
    std::cout << equals << string_tasks[5] << equals;

    int depositSum, percent, targetSum, years = 0;
    std::cout << "Введите размер изначального вклада: ";
    std::cin >> depositSum;
    std::cout << "Введите процент годовых вклада: ";
    std::cin >> percent;
    std::cout << "Введите желаемую к накоплению сумму: ";
    std::cin >> targetSum;
    
    std::cout << "\n----------------Вычисление----------------\n\n";

    while (depositSum <= targetSum) {
        depositSum += (depositSum * percent) / 100;
        ++years;
    }

    int yearsMod100 = years % 100;
    if (yearsMod100 % 10 == 1 && yearsMod100 != 11)
        std::cout << years << " год\n";
    else if (yearsMod100 % 10 >= 2 && yearsMod100 % 10 <= 4 &&
             (yearsMod100 < 12 || yearsMod100 > 14))
        std::cout << years << " года\n";
    else
        std::cout << years << " лет\n";
}
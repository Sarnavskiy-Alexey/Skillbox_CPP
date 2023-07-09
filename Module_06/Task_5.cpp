#ifdef __MODULE_06__
/* Задание 5. Числа Фибоначчи
 *  Числами Фибоначчи называется следующая последовательность чисел: 1, 1, 2, 3, 5, 8, 13 и так
 *  далее (первое число равно 1, второе число равно 1, а каждое следующее равно сумме двух
 *  предыдущих). Напишите программу, которая по данному номеру N выводит N-е число этой
 *  последовательности (если оно не превосходит 2 147 483 647, конечно же). Обеспечьте контроль
 *  ввода. */

#include <iostream>
#include "Module_06.hpp"

void Task_06_5() {
    std::cout << equals << string_tasks[4] << equals;
    
    int preLast = 0, last = 1, current = 1, sourceNumber, i = 2;
    std::cout << "Какое число Фибоначчи вас интересует? ";
    std::cin >> sourceNumber;

    std::cout << "\n----------------Выполняем рассчет----------------\n\n";

    if (sourceNumber >= 0 && sourceNumber <= 46) {
        if (sourceNumber == 0)
            std::cout << preLast;
        else if (sourceNumber == 1)
            std::cout << last;
        else {
            while (i != sourceNumber) {
                preLast = last;
                last = current;
                current = preLast + last;
                i++;
            }
            std::cout << sourceNumber << "-ое число Фибоначчи: " << current << "\n";
        }
    }
    else
        std::cout << "Такое число Фибоначчи мы высчитать не в силах!\n";
}
#endif

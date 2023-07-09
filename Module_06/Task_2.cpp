#ifdef __MODULE_06__
/* Задание 2. Слишком большие числа
 *  У неудачливого бухгалтера всё опять идёт наперекосяк: ему приносят такие большие счета, что
 *  числа не помещаются на бумаге. Напишите программу, которая считала бы для него, сколько цифр
 *  (знаков) во вводимом числе. */

#include <iostream>
#include "Module_06.hpp"

void Task_06_2() {
    std::cout << equals << string_tasks[1] << equals;

    int veryBigNumber, result = 0;
    std::cout << "Введите число: ";
    std::cin >> veryBigNumber;

    while (veryBigNumber != 0) {
        result++;
        veryBigNumber /= 10;
    }

    std::cout << "Количество цифр в заданном числе: " << result << "\n";
}
#endif

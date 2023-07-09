#ifdef __MODULE_06__
/* Задание 4. Счастливый билетик
 *  В старину, когда даже в столице билеты в общественном транспорте выдавали контролёры,
 *  существовало поверье: если на билете сумма первых трёх цифр в номере билета равна сумме трёх
 *  последних, то это к удаче. Напишите программу, которая получала бы на вход шестизначный номер
 *  билета и выводила, счастливый это билет или нет. К примеру, билеты 666 666 и 252 135 —
 *  счастливые, а 123 456 — нет. */

#include <iostream>
#include "Module_06.hpp"

void Task_06_4() {
    std::cout << equals << string_tasks[3] << equals;

    int ticketNumber;
    std::cout << "Введите номер билета: ";
    std::cin >> ticketNumber;

    if (ticketNumber < 100000 || ticketNumber >= 1000000)
        std::cout << "Номер билета не шестизначный!\n";
    else {
        int left = 0, right = 0;
        bool change = false;
        while (ticketNumber) {
            if (change)
                right += ticketNumber % 10;
            else
                left += ticketNumber % 10;
            ticketNumber /= 10;
            if (ticketNumber < 1000)
                change = true;
        }
        if (left == right)
            std::cout << "Счастливый билетик найден!\n";
        else
            std::cout << "В этот раз несчастливый билетик!\n";
    }
}
#endif

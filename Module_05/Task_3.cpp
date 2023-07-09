#ifdef __MODULE_05__
/* Задание 3. Майские!
 *  Напишите программу-календарь для мая. Она должна проверять введённый номер дня и сообщать,
 *  выходной этот день или рабочий. Выходными считаются все субботы и воскресенья, а также даты
 *  с 1 по 5 и с 8 по 10 мая включительно. Наш месяц всегда начинается с понедельника. */

#include <iostream>
#include "Module_05.hpp"

void Task_05_3() {
    std::cout << equals << string_tasks[2] << equals;

    int mayDay;

    std::cout << "Введите номер дня в мае: ";
    std::cin >> mayDay;

    mayDay--;
    std::cout << "\n----------------Проверка----------------\n\n";
    
    if (mayDay >= 0 && mayDay <= 30)
        if (mayDay % 7 == 5 || mayDay % 7 == 6 ||
            (mayDay >= 0 && mayDay <= 4) ||
            (mayDay >= 7 && mayDay <= 9))
            std::cout << mayDay + 1 << " мая - " << "выходной день!\n";
        else
            std::cout << mayDay + 1 << " мая - " << "рабочий день!\n";
    else
        std::cout << "Такого дня в мае не существует!\n";
}
#endif

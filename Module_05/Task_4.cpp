#ifdef __MODULE_05__
/* Задание 4. Майские — усложнение
 *  Добавьте возможность начать месяц с любого дня недели. Для этого вводится число — номер дня
 *  недели, с которого начинается месяц. Убедитесь, что введённое число корректно. */

#include <iostream>
#include "Module_05.hpp"

void Task_05_4() {
    std::cout << equals << string_tasks[3] << equals;
    
    int mayDay, may1WeekDay;

    std::cout << "С какого дня недели начинается май? ";
    std::cin >> may1WeekDay;
    std::cout << "Введите номер дня в мае: ";
    std::cin >> mayDay;

    mayDay--;
    may1WeekDay--;
    std::cout << "\n----------------Проверка----------------\n\n";
    
    if (mayDay >= 0 && mayDay <= 30 &&
        may1WeekDay >= 0 && may1WeekDay <= 6)
        if (mayDay % 7 == (12 - may1WeekDay) % 7 || mayDay % 7 == (13 - may1WeekDay) % 7 ||
            (mayDay >= 0 && mayDay <= 4) ||
            (mayDay >= 7 && mayDay <= 9))
            std::cout << mayDay + 1 << " мая - " << "выходной день!\n";
        else
            std::cout << mayDay + 1 << " мая - " << "рабочий день!\n";
    else
        std::cout << "Ошибка при вводе данных!\n";
}
#endif

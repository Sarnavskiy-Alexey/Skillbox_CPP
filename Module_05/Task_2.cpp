#ifdef __MODULE_05__
/* Задание 2. Полёт нормальный!
 *  Напишите программу для аэропорта, проверяющую, правильным ли эшелоном летит самолёт. Его
 *  скорость должна быть в диапазоне от 750 до 850 км/ч, а высота — в диапазоне от 9000 до 9500
 *  метров. */

#include <iostream>
#include "Module_05.hpp"

void Task_05_2() {
    std::cout << equals << string_tasks[1] << equals;

    int aircraftVelocity, aircraftHeight;

    std::cout << "Введите скорость самолета (км/ч): ";
    std::cin >> aircraftVelocity;
    std::cout << "Введите высоту (м): ";
    std::cin >> aircraftHeight;

    std::cout << "\n----------------Проверка----------------\n\n";
    
    if (aircraftVelocity >= 750 && aircraftVelocity <= 850 &&
        aircraftHeight >= 9000 && aircraftHeight <= 9500)
        std::cout << "Самолет летит правильным эшелоном!\n";
    else
        std::cout << "Самолету необходимо скорректировать движение!\n";
}
#endif

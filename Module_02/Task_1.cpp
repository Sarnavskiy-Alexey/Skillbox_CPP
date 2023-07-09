#ifdef __MODULE_02__
/* Задание 1. Улучшаем гонщика
 *  Исправьте код программы так, чтобы значение скорости рассчитывалось автоматически. Скорость -
 *  это сумма показателей двигателя, колёс и руля минус показатели дождя и ветра. */

#include <iostream>
#include "Module_02.hpp"

void Task_02_1() {
    std::cout << equals << string_tasks[0] << equals;
    int lap = 4;
    int engine = 254;
    int wheels = 93;
    int steerinWheel = 49;
    int wind = 21;
    int rain = 17;
    int speed = engine + wheels + steerinWheel - wind - rain;
    std::cout << "===================\n";
    std::cout << "Супер гонки. Круг " << lap << "\n";
    std::cout << "===================\n";
    std::cout << "Шумахер (" << speed << ")\n";
    std::cout << "===================\n";
    std::cout << "Водитель: Шумахер\n";
    std::cout << "Скорость: " << speed << "\n";
    std::cout << "-------------------\n";
    std::cout << "Оснащение\n";
    std::cout << "Двигатель: +" << engine << "\n";
    std::cout << "Колеса: +" << wheels << "\n";
    std::cout << "Руль: +" << steerinWheel << "\n";
    std::cout << "-------------------\n";
    std::cout << "Действия плохой погоды\n";
    std::cout << "Ветер: -" << wind << "\n";
    std::cout << "Дождь: -" << rain << "\n";
}
#endif

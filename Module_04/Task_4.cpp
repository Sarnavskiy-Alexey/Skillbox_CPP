#ifdef __MODULE_04__
/* Задание 4. Калькулятор опыта
 *  Напишите программу, которая определяет уровень персонажа в компьютерной игре. Пользователь
 *  вводит число «очков опыта», а программа вычисляет уровень. Новый уровень даётся при достижении
 *  1000, 2500 и 5000 «очков опыта». Начальный уровень равен 1. */

#include <iostream>
#include "Module_04.hpp"

void Task_04_4() {
    std::cout << equals << string_tasks[3] << equals;

    int userXP;
    int sourceLevel = 1;
    std::cout << "Введите количество очков опыта: ";
    std::cin >> userXP;

    std::cout << "\n--------------Ведется подсчет--------------\n\n";
    
    if (userXP >= 1000)
        sourceLevel++;
    if (userXP >= 2500)
        sourceLevel++;
    if (userXP >= 5000)
        sourceLevel++;
    std::cout << "Ваш уровень: " << sourceLevel << "\n";
}
#endif

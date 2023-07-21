// #ifdef __MODULE_15__
#include <iostream>
#include "Module_15.hpp"

void Module_15()
{
    std::cout << "\n\t\t\t\tМодуль 15.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-4 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_15_1(); break;
        case 2: Task_15_2(); break;
        case 3: Task_15_3(); break;
        case 4: Task_15_4(); break;
        default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}
// #endif

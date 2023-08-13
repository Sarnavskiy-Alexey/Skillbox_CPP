// #ifdef __MODULE_21__
#include <iostream>
#include "Module_21.hpp"

void Module_21()
{
    std::cout << "\n\t\t\t\tМодуль 21.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-4 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_21_1(); break;
        case 2: Task_21_2(); break;
        case 3: Task_21_3(); break;
        case 4: Task_21_4(); break;
        default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}
// #endif

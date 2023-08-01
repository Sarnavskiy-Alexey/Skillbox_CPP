// #ifdef __MODULE_17__
#include <iostream>
#include "Module_17.hpp"

void Module_17()
{
    std::cout << "\n\t\t\t\tМодуль 17.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-3 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_17_1(); break;
        case 2: Task_17_2(); break;
        case 3: Task_17_3(); break;
        default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}
// #endif

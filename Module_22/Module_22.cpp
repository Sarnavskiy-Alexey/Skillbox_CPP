#ifdef __MODULE_22__
#include <iostream>
#include "Module_22.hpp"

void Module_22()
{
    std::cout << "\n\t\t\t\tМодуль 22.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-3 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_22_1(); break;
        case 2: Task_22_2(); break;
        case 3: Task_22_3(); break;
        default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}
#endif

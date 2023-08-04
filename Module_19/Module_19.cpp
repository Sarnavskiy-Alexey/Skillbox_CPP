// #ifdef __MODULE_19__
#include <iostream>
#include "Module_19.hpp"

void Module_19()
{
    std::cout << "\n\t\t\t\tМодуль 19.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-5 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_19_1(); break;
        case 2: Task_19_2(); break;
        case 3: Task_19_3(); break;
        case 4: Task_19_4(); break;
        case 5: Task_19_5(); break;
        default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}
// #endif

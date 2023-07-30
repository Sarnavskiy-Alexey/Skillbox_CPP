#ifdef __MODULE_16__
#include <iostream>
#include "Module_16.hpp"

void Module_16()
{
    std::cout << "\n\t\t\t\tМодуль 16.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-5 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_16_1(); break;
        case 2: Task_16_2(); break;
        case 3: Task_16_3(); break;
        case 4: Task_16_4(); break;
        case 5: Task_16_5(); break;
        default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}
#endif

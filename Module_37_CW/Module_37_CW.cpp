#ifdef __MODULE_37__
#include <iostream>
#include "Module_37_CW.hpp"

void Module_37_CW(int argc, char **argv)
{
    std::cout << "\n\t\t\t\tМодуль 37 CW.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-1 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_37_1_CW(argc, argv); break;
        // case 2: Task_37_2_CW(argc, argv); break;
        default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}
#endif

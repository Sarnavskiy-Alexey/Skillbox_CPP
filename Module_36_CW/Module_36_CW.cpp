#ifdef __MODULE_36__
#include <iostream>
#include "Module_36_CW.hpp"

void Module_36_CW(int argc, char **argv)
{
    std::cout << "\n\t\t\t\tМодуль 36 CW.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-4 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_36_1_CW(argc, argv); break;
        case 2: Task_36_2_CW(argc, argv); break;
        case 3: Task_36_3_CW(argc, argv); break;
        case 4: Task_36_4_CW(argc, argv); break;
        default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}
#endif

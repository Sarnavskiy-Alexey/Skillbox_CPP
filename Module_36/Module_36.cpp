#ifdef __MODULE_36__
#include <iostream>
#include "Module_36.hpp"

void Module_36(int argc, char **argv)
{
    std::cout << "\n\t\t\t\tМодуль 36.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-1 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_36_1(argc, argv); break;
        default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}
#endif

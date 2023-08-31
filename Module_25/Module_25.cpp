#ifdef __MODULE_25__
#include <iostream>
#include "Module_25.hpp"

void Module_25()
{
    std::cout << "\n\t\t\t\tМодуль 25.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-2 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_25_1(); break;
        case 2: Task_25_2(); break;
        default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}
#endif

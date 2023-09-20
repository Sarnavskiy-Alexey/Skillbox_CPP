#ifdef __MODULE_29__
#include <iostream>
#include "Module_29.hpp"

void Module_29()
{
    std::cout << "\n\t\t\t\tМодуль 29.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-2 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_29_1(); break;
        case 2: Task_29_2(); break;
        default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}
#endif

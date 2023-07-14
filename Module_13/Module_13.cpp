#ifdef __MODULE_13__
#include <iostream>
#include "Module_13.hpp"

void Module_13()
{
    std::cout << "\n\t\t\t\tМодуль 13.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-3 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_13_1(); break;
        case 2: Task_13_2(); break;
        case 3: Task_13_3(); break;
        default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}
#endif

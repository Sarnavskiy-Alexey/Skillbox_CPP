#ifdef __MODULE_18__
#include <iostream>
#include "Module_18.hpp"

void Module_18()
{
    std::cout << "\n\t\t\t\tМодуль 18.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-3 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_18_1(); break;
        case 2: Task_18_2(); break;
        case 3: Task_18_3(); break;
        default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}
#endif

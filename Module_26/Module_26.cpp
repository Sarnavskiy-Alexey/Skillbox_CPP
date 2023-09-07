#ifdef __MODULE_26__
#include <iostream>
#include "Module_26.hpp"

void Module_26()
{
    std::cout << "\n\t\t\t\tМодуль 26.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-3 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_26_1(); break;
        case 2: Task_26_2(); break;
        case 3: Task_26_3(); break;
        default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}
#endif

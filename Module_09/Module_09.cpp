#ifdef __MODULE_09__
#include <iostream>
#include "Module_09.hpp"

void Module_09()
{
    std::cout << "\n\t\t\t\tМодуль 9.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-5 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_09_1(); break;
        case 2: Task_09_2(); break;
        case 3: Task_09_3(); break;
        case 4: Task_09_4(); break;
        case 5: Task_09_5(); break;
        default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}
#endif

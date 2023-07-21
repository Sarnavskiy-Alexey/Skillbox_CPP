#ifdef __MODULE_14__
#include <iostream>
#include "Module_14.hpp"

void Module_14()
{
    std::cout << "\n\t\t\t\tМодуль 14.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-8 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_14_1(); break;
        case 2: Task_14_2(); break;
        case 3: Task_14_3(); break;
        case 4: Task_14_4(); break;
        case 5: Task_14_5(); break;
        case 6: Task_14_6(); break;
        case 7: Task_14_7(); break;
        case 8: Task_14_8(); break;
        default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}
#endif

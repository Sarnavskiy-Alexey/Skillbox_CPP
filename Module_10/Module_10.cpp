#include <iostream>
#include "Module_10.hpp"

void Module_10()
{
    std::cout << "\n\t\t\t\tМодуль 10.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-1 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_10_1(); break;
        default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}

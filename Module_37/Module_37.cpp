#ifdef __MODULE_37__
#include <iostream>
#include "Module_37.hpp"

void Module_37(int argc, char **argv)
{
    std::wcout << L"\n\t\t\t\tМодуль 37.\n";
    unsigned short userAnswer;

    do {
        std::wcout << L"\tВведите номер задания 1-3 или 0 для выхода: ";
        std::cin >> userAnswer;

        switch (userAnswer) {
        case 0: break;
        case 1: Task_37_1(argc, argv); break;
        case 2: Task_37_2(argc, argv); break;
        case 3: Task_37_3(argc, argv); break;
        default: std::wcout << L"\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }

        std::cout << equals;

    } while (userAnswer != 0);
}
#endif

#include <iostream>
#include "Module_06.hpp"

void Module_06()
{
    std::cout << "\n\t\t\t\tМодуль 6.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-8 или 0 для выхода: ";
        std::cin >> userAnswer;
        
        switch(userAnswer) {
            case 0: break;
            case 1: Task_06_1(); break;
            case 2: Task_06_2(); break;
            case 3: Task_06_3(); break;
            case 4: Task_06_4(); break;
            case 5: Task_06_5(); break;
            case 6: Task_06_6(); break;
            case 7: Task_06_7(); break;
            case 8: Task_06_8(); break;
            default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }
        
        std::cout << equals;
        
    } while (userAnswer != 0);
}

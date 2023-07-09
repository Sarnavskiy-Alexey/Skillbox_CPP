#ifdef __MODULE_07__
#include <iostream>
#include "Module_07.hpp"

void Module_07()
{
    std::cout << "\n\t\t\t\tМодуль 7.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-8 или 0 для выхода: ";
        std::cin >> userAnswer;
        
        switch(userAnswer) {
            case 0: break;
            case 1: Task_07_1(); break;
            case 2: Task_07_2(); break;
            case 3: Task_07_3(); break;
            case 4: Task_07_4(); break;
            case 5: Task_07_5(); break;
            case 6: Task_07_6(); break;
            case 7: Task_07_7(); break;
            case 8: Task_07_8(); break;
            default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }
        
        std::cout << equals;
        
    } while (userAnswer != 0);
}
#endif

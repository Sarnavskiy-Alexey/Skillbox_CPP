#ifdef __MODULE_04__
#include <iostream>
#include "Module_04.hpp"

void Module_04()
{
    std::cout << "\n\t\t\t\tМодуль 4.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-9 или 0 для выхода: ";
        std::cin >> userAnswer;
        
        switch(userAnswer) {
            case 0: break;
            case 1: Task_04_1(); break;
            case 2: Task_04_2(); break;
            case 3: Task_04_3(); break;
            case 4: Task_04_4(); break;
            case 5: Task_04_5(); break;
            case 6: Task_04_6(); break;
            case 7: Task_04_7(); break;
            case 8: Task_04_8(); break;
            case 9: Task_04_9(); break;
            default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }
        
        std::cout << equals;
        
    } while (userAnswer != 0);
}
#endif

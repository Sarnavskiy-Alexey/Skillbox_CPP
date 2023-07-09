#ifdef __MODULE_05__
#include <iostream>
#include "Module_05.hpp"

void Module_05()
{
    std::cout << "\n\t\t\t\tМодуль 5.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-9 или 0 для выхода: ";
        std::cin >> userAnswer;
        
        switch(userAnswer) {
            case 0: break;
            case 1: Task_05_1(); break;
            case 2: Task_05_2(); break;
            case 3: Task_05_3(); break;
            case 4: Task_05_4(); break;
            case 5: Task_05_5(); break;
            case 6: Task_05_6(); break;
            case 7: Task_05_7(); break;
            case 8: Task_05_8(); break;
            case 9: Task_05_9(); break;
            default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }
        
        std::cout << equals;
        
    } while (userAnswer != 0);
}
#endif

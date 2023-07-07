#include <iostream>
#include "Module_08.hpp"

void Module_08()
{
    std::cout << "\n\t\t\t\tМодуль 8.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-10 или 0 для выхода: ";
        std::cin >> userAnswer;
        
        switch(userAnswer) {
            case 0: break;
            case 1: Task_08_1(); break;
            case 2: Task_08_2(); break;
            case 3: Task_08_3(); break;
            case 4: Task_08_4(); break;
            case 5: Task_08_5(); break;
            case 6: Task_08_6(); break;
            case 7: Task_08_7(); break;
            case 8: Task_08_8(); break;
            case 9: Task_08_9(); break;
            case 10: Task_08_10(); break;
            default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }
        
        std::cout << equals;
        
    } while (userAnswer != 0);
}

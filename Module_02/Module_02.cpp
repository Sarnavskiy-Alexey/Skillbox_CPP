#include <iostream>
#include "Module_02.hpp"

void Module_02() {
    std::cout << "\n\t\t\t\tМодуль 2.\n";
    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер задания 1-4 или 0 для выхода: ";
        std::cin >> userAnswer;
        
        switch(userAnswer) {
            case 0: break;
            case 1: Task_02_1(); break;
            case 2: Task_02_2(); break;
            case 3: Task_02_3(); break;
            case 4: Task_02_4(); break;
            default: std::cout << "\tЗадание в ДЗ отсутствует. Выберите другое задание!\n";
        }
        
        std::cout << equals;
        
    } while (userAnswer != 0);
}

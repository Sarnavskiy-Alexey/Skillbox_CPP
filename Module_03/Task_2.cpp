#ifdef __MODULE_03__
/* Задача 2. Обмен местами
 *  Есть код программы с двумя переменными типа int и выводом этих переменных на экран. Напишите
 *  программу, которая меняет значения переменных местами, то есть нужно добиться того, чтобы в
 *  переменной a лежит значение b, а в b — значение a. */

#include <iostream>
#include "Module_03.hpp"

void Task_03_2() {
    std::cout << equals << string_tasks[1] << equals;

    int a = 5;
    int b = 10;

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    std::cout << "\n-----------Магия-----------\n\n";
    
    int tmp = a;
    a = b;
    b = tmp;

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
}
#endif

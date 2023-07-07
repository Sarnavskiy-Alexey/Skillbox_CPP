/* Задание 5. Кратность числа
 *  Напишите программу, которая проверяет, делится ли одно число на другое без остатка.*/

#include <iostream>
#include "Module_04.hpp"

void Task_04_5() {
    std::cout << equals << string_tasks[4] << equals;

    int userA, userB;

    std::cout << "Введите первое число: ";
    std::cin >> userA;
    std::cout << "Введите второе число: ";
    std::cin >> userB;
    
    std::cout << "\n----------------Проверка----------------\n\n";

    if (userB == 0)
        std::cout << "Ошибка! Делитель равен нулю!\n";
    if (!(userA % userB))
        std::cout << "Число " << userA << " делится на число " << userB << " без остатка\n";
    else
        std::cout << "Число " << userA << " не делится на число " << userB << " без остатка\n";
}
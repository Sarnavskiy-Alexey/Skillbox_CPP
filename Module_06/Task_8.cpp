/* Задание 8. Угадай число* (дополнительное задание)
 *  Напишите программу, которая угадывает число, задуманное пользователем. Число загадывается в
 *  диапазоне от 0 до 63. Программа задаёт вопросы вида «Ваше число больше такого-то?» и на основе
 *  ответов пользователя («да» или «нет») угадывает число. */

#include <iostream>
#include "Module_06.hpp"

void Task_06_8() {
    std::cout << equals << string_tasks[7] << equals;

    int left = 0, right = 63, mid = (left + right) / 2;
    std::string userAnswer;
    
    std::cout << "\n----------------Проверка----------------\n\n";

    while (left != right) {
        std::cout << left << " " << mid << " " << right << "\n";
        std::cout << "Ваше число больше " << mid << "? (y/n)";
        std::cin >> userAnswer;
        if (userAnswer == "да" || userAnswer == "Да" || userAnswer == "ДА" || userAnswer == "дА")
            left = mid + 1;
        else
            right = mid;
        mid = (left + right) / 2;
    }
    std::cout << "Вы загадали: " << mid << "\n";
}
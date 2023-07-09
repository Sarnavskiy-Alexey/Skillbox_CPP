#ifdef __MODULE_09__
/* Задание 3. Подсчёт количества слов
 *  Напишите программу, которая считает количество слов в тексте, введённом пользователем. Словом
 *  считается любая последовательность символов (не обязательно букв) без пробелов.
 *  Пользователь вводит строку, состоящую из произвольных символов и пробелов. Программа должна
 *  вывести одно число — количество слов во введённой строке. */

#include <iostream>
#include <string>
#include <limits>
#include "Module_09.hpp"

void Task_09_3() {
    std::cout << equals << string_tasks[2] << equals;

    // очистка буфера ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Введите произвольную строку: ";
    std::string str;
    std::getline(std::cin, str);

    int lastSpace = 1, counterWord;
    unsigned int i;
    for (i = 0, counterWord = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            if (!lastSpace) {
                counterWord++;
                lastSpace = 1;
            }
        } else {
            lastSpace = 0;
        }
    }
    if (str[str.length() - 1] != ' ')
        counterWord++;

    std::cout << "Слов в строке: " << counterWord << "\n";
}
#endif

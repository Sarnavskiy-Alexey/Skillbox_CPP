/* Задание 5. Склонение русских слов
 *  Напишите программу для магазина, которая по заданной цене товара дописывает к нему слово «рубли»
 *  в правильном падеже. Например, если вводится число 2000, то ответ должен быть «2000 рублей»,
 *  если 22 — то «22 рубля», если 51 — то «51 рубль». */

#include <iostream>
#include "Module_05.hpp"

void Task_05_5() {
    std::cout << equals << string_tasks[4] << equals;

    int roubles;
    std::cout << "Введите количество рублей: ";
    std::cin >> roubles;
    
    std::cout << "\n--------------Ведется склонение--------------\n\n";

    if (roubles >= 0) {
        int roublesMod100 = roubles % 100;
        if (roublesMod100 % 10 == 1 && roublesMod100 != 11)
            std::cout << roubles << " рубль\n";
        else if (roublesMod100 % 10 >= 2 && roublesMod100 % 10 <= 4 &&
                 (roublesMod100 < 12 || roublesMod100 > 14))
            std::cout << roubles << " рубля\n";
        else
            std::cout << roubles << " рублей\n";
    }
    else
        std::cout << "Отрицательное количество рублей невозможно!\n";
}
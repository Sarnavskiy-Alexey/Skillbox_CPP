// #ifdef __MODULE_15__
/* Задача 2
 *  Что нужно сделать:
 *  Вам даётся массив целых чисел и одно число — результат. Необходимо найти в массиве два числа,
 *  сумма которых будет давать результат, и вывести их на экран. Гарантируется, что только одна пара
 *  чисел в массиве даёт в сумме результат.
 *  
 *  Пример:
 *  
 *  a = {2, 7, 11, 15}. Результат = 9
 *  
 *  2 + 7 = 9, так что надо вывести числа 2 и 7
 *  Советы и рекомендации
 *  - Как только найдена первая удовлетворяющая условиям пара, можно заканчивать поиск. */

#include <iostream>
#include "Module_15.hpp"

void Task_15_2() {
    std::cout << equals << string_tasks[1] << equals;

    const int size = 4;
    int mas[size], first = 0, second = 0, find;
    bool found = false;

    std::cout << "Введите число: ";
    std::cin >> find;

    std::cout << "Введите числа в количестве " << size << ": ";
    for (int i = 0; i < size; i++)
        std::cin >> mas[i];

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (mas[i] + mas[j] == find) {
                first = i;
                second = j;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (found)
        std::cout << "Пара чисел, дающая " << find << ": " << mas[first] << " и " << mas[second] << "\n";
    else
        std::cout << "Пары не найдено!\n";
}
// #endif

// #ifdef __MODULE_15__
/* Задача 1
 *  Что нужно сделать:
 *  Вам даётся массив целых чисел. Необходимо найти такие два индекса i и j в этом массиве, что
 *  сумма a[i], a[i+1], a[i+2], … a[j] будет максимально возможной и вывести их.
 *  
 *  a = {-2,1,-3,4,-1,2,1,-5,4}
 *  
 *  Тогда наибольшая сумма последовательных элементов находится между индексами 3 и 6: {4,-1,2,1},
 *  сумма = 6. Необходимо вывести 3 и 6. */

#include <iostream>
#include "Module_15.hpp"

void Task_15_1() {
    std::cout << equals << string_tasks[0] << equals;

    const int size = 9;
    int max, mas[size], left = 0, right = size - 1;

    std::cout << "Введите все числа массива в количестве " << size << ": ";
    for (int i = 0; i < size; i++)
        std::cin >> mas[i];

    max = mas[0];
    for (int i = 0; i < size - 1; i++) {
        int sum = mas[i];
        for (int j = i + 1; j < size; j++) {
            sum += mas[j];
            if (sum > max) {
                max = sum;
                left = i;
                right = j;
            }
        }
    }

    std::cout << "Наибольшая сумма последовательных элементов между " << left << " и " << right
              << ", сумма: " << max << ".\n";
}
// #endif

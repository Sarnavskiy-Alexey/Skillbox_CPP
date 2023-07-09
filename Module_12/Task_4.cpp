#ifdef __MODULE_12__
/* Задание 4. Ряд чисел* (дополнительное задание)
 *  В программе инициализирован массив из 15 целых положительных чисел. Эти числа являются
 *  множеством из 14 последовательных чисел, начиная с Х (Х может быть любым), а одно число из ряда
 *  повторяется. Необходимо найти повторяющееся число и вывести его в консоль. По возможности
 *  используйте минимум дополнительной памяти и проходов по массиву. */

#include <iostream>
#include "Module_12.hpp"

void Task_12_4() {
    std::cout << equals << string_tasks[3] << equals;

    const int size = 15;
    int X, numbers[size], sortMas[size] = { 0 };
    for (int i = 0; i < size; i++) {
        std::cout << "Введите " << i + 1 << "-е число: ";
        std::cin >> numbers[i];
        if (i == 0) X = numbers[i];
        else
            if (X > numbers[i]) X = numbers[i];
    }

    for (int i = 0; i < size; i++) {
        sortMas[numbers[i] - X]++;
        if (sortMas[numbers[i] - X] > 1) {
            std::cout << "Повторяющееся число: " << numbers[i] << "\n";
            break;
        }
    }
}
#endif

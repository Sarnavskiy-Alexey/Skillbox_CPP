#ifdef __MODULE_15__
/* Задача 4
 *  Что нужно сделать:
 *  Вам даётся массив целых чисел, отсортированных по возрастанию. Необходимо вывести его на экран
 *  отсортированным в порядке возрастания модуля чисел.
 *  
 *  Пример:
 *  
 *  Массив {-100,-50, -5, 1, 10, 15}
 *  
 *  Вывод: 1, -5, 10, 15, -50, -100
 *  
 *  Советы и рекомендации
 *  - Положительные числа уже отсортированы в порядке возрастания модулей. */

#include <iostream>
#include <vector>
#include "Module_15.hpp"

void Task_15_4() {
    std::cout << equals << string_tasks[3] << equals;

    unsigned int size, lastNegIdx = 0, posIdx;
    std::cout << "Введите количество элементов для добавления в вектор: ";
    std::cin >> size;
    std::vector<int> vec(size);
    std::vector<int> res(size, 0);

    for (unsigned int i = 0; i < size; i++) {
        std::cout << "Введите число для добавления в вектор: ";
        std::cin >> vec[i];
    }

    while (vec[lastNegIdx] < 0 && lastNegIdx < size)
        lastNegIdx++;
    posIdx = lastNegIdx;
    lastNegIdx--;

    int neg = 0, pos = 0;
    for (unsigned int i = 0; i < res.size(); i++) {
        if (lastNegIdx < vec.size()) neg = vec[lastNegIdx];
        if (posIdx < res.size()) pos = vec[posIdx];
        if (lastNegIdx >= 0 && posIdx < res.size()) {
            if (abs(neg) < pos) {
                res[i] = neg;
                lastNegIdx--;
            } else {
                res[i] = pos;
                posIdx++;
            }
        } else if (lastNegIdx >= 0) {
            res[i] = neg;
            lastNegIdx--;
        } else {
            res[i] = pos;
            posIdx++;
        }
    }

    for (unsigned int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    std::cout << "\n";
}
#endif

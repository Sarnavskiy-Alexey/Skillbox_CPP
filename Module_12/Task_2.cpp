#ifdef __MODULE_12__
/* Задание 2. Сортировка
 *  Пользователь вводит в консоль 15 дробных чисел. Необходимо прочитать их и вывести в консоль в
 *  порядке от большего к меньшему. По возможности используйте минимум дополнительной памяти и
 *  проходов по массиву. */

#include <iostream>
#include "Module_12.hpp"

void Task_12_2() {
    std::cout << equals << string_tasks[1] << equals;
    
    const int size = 15;
    float numbers[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Введите " << i + 1 << "-е вещественное число: ";
        std::cin >> numbers[i];
    }

    int tmp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (numbers[i] < numbers[j]) {
                tmp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tmp;
            }
        }
    }

    std::cout << "Отсортированный по убыванию массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";
}
#endif

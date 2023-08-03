#ifdef __MODULE_17__
/* Задача 2.
 *  Что нужно сделать:
 *  Написать функцию, которая принимает указатель на тип int, по которому размещены 10 переменных
 *  типа int. Функция ничего не возвращает, но по тому же указателю элементы должны лежать в
 *  обратном порядке.
 *  
 *  Чек-лист для проверки задачи
 *  - Функция принимает корректные типы данных, тип возвращаемого значения --  void
 *  - Функция не использует библиотек кроме <iostream>
 *  - По переданному указателю лежат переменные в обратном порядке. */

#include <iostream>
#include "Module_17.hpp"

static void swap(int* const a, int* const b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void reverse(int* const arr, const int size) {
    int left = 0, right = size - 1;
    while (left < right) {
        swap(arr + left, arr + right);
        left++;
        right--;
    }
}

static void print_mas(const int* const arr, const int size) {
    for (int i = 0; i < size; i++)
        std:: cout << arr[i] << " ";
    std::cout << "\n";
}

void Task_17_2() {
    std::cout << equals << string_tasks[1] << equals;

    const int size = 10;
    int mas[size];

    for (int i = 0; i < size; i++) {
        std::cout << "Введите " << i + 1 << "-е число: ";
        std::cin >> mas[i];
    }

    std::cout << "Массив до изменения:\n";
    print_mas(mas, size);

    reverse(mas, size);

    std::cout << "Массив после изменения:\n";
    print_mas(mas, size);
}
#endif

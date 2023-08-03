#ifdef __MODULE_17__
/* Задача 1.
 *  Что нужно сделать:
 *  Написать функцию, принимающую два указателя на int и меняет местами содержимое данных указателей.
 *  Пример:
 *  
 *  int a = 10;
 *  int b = 20;
 *  swap(&a, &b);
 *  std::cout << a << “ “ << b;
 *  // 20 10
 *  
 *  Чек-лист для проверки задачи
 *  - Функция принимает корректные типы данных, тип возвращаемого значения -- void
 *  - Функция не использует библиотек кроме <iostream>
 *  - Функция меняет значения по указателям. */

#include <iostream>
#include "Module_17.hpp"

static void swap(int* const a, int* const b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Task_17_1() {
    std::cout << equals << string_tasks[0] << equals;

    int a, b;
    std::cout << "Введите два числа: ";
    std::cin >> a >> b;

    std::cout << "&a = " << &a << "\t&b = " << &b << "\n";
    std::cout << "a = " << a << "\tb = " << b << "\n";
    swap(&a, &b);
    std::cout << "&a = " << &a << "\t&b = " << &b << "\n";
    std::cout << "a = " << a << "\tb = " << b << "\n";
}
#endif

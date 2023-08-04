#ifdef __MODULE_18__
/* Задача 1
 *  Что нужно сделать
 *  Напишите функцию swapvec, принимающую std::vector<int> и указатель на массив переменных типа int
 *  (одного размера) и обменивающую значения этих массивов.
 *  Пример:
 *    std::vector<int> a = {1,2,3,4};
 *    int b[] = {2,4,6,8};
 *    swapvec(a,b);
 *    for(int i = 0; i < 4; ++i)
 *       std::cout << a[i];
 *    std::cout << std::endl;
 *    for(int i = 0; i < 4; ++i)
 *       std::cout << b[i];
 *  
 *  Вывод:
 *    2468
 *    1234 */

#include <iostream>
#include <vector>
#include "Module_18.hpp"

static void swap(int* const a, int* const b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void swapvec(std::vector<int>& vec, int* mas) {
    for (unsigned int i = 0; i < vec.size(); i++)
        swap(&vec[i], mas + i);
}

static void print_vec_mas(const std::vector<int>& vec, const int* const mas) {
    std::cout << "Вектор:\n";
    for (unsigned int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << "\nМассив:\n";
    for (unsigned int i = 0; i < vec.size(); i++)
        std::cout << mas[i] << " ";
    std::cout << "\n";
}

void Task_18_1() {
    std::cout << equals << string_tasks[0] << equals;

    std::vector<int> a = {1,2,3,4};
    int b[] = {2,4,6,8};

    print_vec_mas(a, b);
    swapvec(a, b);
    print_vec_mas(a, b);
}
#endif

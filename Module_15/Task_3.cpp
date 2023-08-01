#ifdef __MODULE_15__
/* Задача 3
 *  Что нужно сделать:
 *  С клавиатуры вводятся числа. Когда пользователь вводит «-1»,  необходимо выводить на экран пятое
 *  по возрастанию число среди введённых. Когда пользователь вводит «-2», программа завершает работу.
 *  
 *  Пример:
 *  
 *  ввод: 7 5 3 1 2 4 6 -1
 *  вывод: 5 (в отсортированном виде массив выглядит так: {1,2,3,4,5,6,7})
 *  ввод: 1 1 1 -1
 *  вывод: 2 (в отсортированном виде массив выглядит так: {1,1,1,1,2,3,4,5,6,7})
 *  ввод -2
 *  завершение программы
 *  
 *  Советы и рекомендации
 *  - Нужно удостовериться, что можно вывести требуемое число (может быть меньше пяти чисел). */

#include <iostream>
#include <vector>
#include <cassert>
#include "Module_15.hpp"

void add_new_element(std::vector<int>& vect, unsigned int& real_size, int new_el) {
    assert(real_size <= 5);

    // если реальное количество добавленных элементов не равно 5 - добавляем элемент на нужное место
    if (real_size != 5) {
        unsigned int idx = 0;
        while (idx < real_size) {
            if (vect[idx] > new_el) idx++;
            else break;
        }

        while (idx < real_size) {
            int tmp = vect[idx];
            vect[idx] = new_el;
            new_el = tmp;
            idx++;
        }
        vect[idx] = new_el;

        real_size++;
    } else {
    // иначе вместо нулевого элемента вставляем новое значение на нужное место, если новое меньше
        int idx = 0;
        if (vect[0] > new_el) {
            vect[0] = new_el;
            while ((idx < 4) && (vect[idx] < vect[idx + 1])) {
                int tmp = vect[idx + 1];
                vect[idx + 1] = vect[idx];
                vect[idx] = tmp;
                idx++;
            }
        }
    }
}

void Task_15_3() {
    std::cout << equals << string_tasks[2] << equals;
    
    std::vector<int> vec(5);
    unsigned int real_size = 0;
    int number;
    do {
        std::cout << "Введите число: ";
        std::cin >> number;
        switch (number) {
            case -1: {
                if (real_size == 5)
                    std::cout << vec[4] << "\n";
                break;
            }
            case -2: break;
            default: add_new_element(vec, real_size, number);
        }
        std::cout << "\n";
        for (int el : vec)
            std::cout << el << " ";
        std::cout << "\n";
    } while (number != -2);
}
#endif

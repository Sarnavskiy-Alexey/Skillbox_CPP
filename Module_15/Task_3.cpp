// #ifdef __MODULE_15__
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

// функция нахождения пятого по возрастанию числа
static int find_5_asc_num(std::vector<int> vect) {
    assert(vect.size() >= 5);

    for (unsigned int i = 0; (i < vect.size() - 1) && (i < 5); i++) {
        int min_idx = i;
        for (unsigned int j = i + 1; j < vect.size(); j++) {
            if (vect[min_idx] > vect[j]) {
                min_idx = j;
            }
        }
        int tmp = vect[i];
        vect[i] = vect[min_idx];
        vect[min_idx] = tmp;

        // в случае дохождения индекса i до пятого элемента, возвращаем его
        if (i == 4)
            return vect[4];
    }

    return vect[4];
}

void Task_15_3() {
    std::cout << equals << string_tasks[2] << equals;

    std::vector<int> vec;
    int number;
    do {
        std::cout << "Введите число: ";
        std::cin >> number;
        switch (number) {
            case -1: {
                if (vec.size() >= 5)
                    std::cout << find_5_asc_num(vec) << "\n";
                break;
            }
            case -2: break;
            default: vec.push_back(number);
        }
    } while (number != -2);
}
// #endif

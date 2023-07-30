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

static unsigned int find_max_id(int five_nums[5]) {
    unsigned int max_id = 0;
    for (unsigned int i = 1; i < 5; i++) {
        if (five_nums[i] > five_nums[max_id])
            max_id = i;
    }
    return max_id;
}

// функция нахождения пятого по возрастанию числа
static int find_5_asc_num(std::vector<int> vect) {
    assert(vect.size() >= 5);

    int five_nums[5] = { 0 };
    // копируем первые пять чисел в новый массив и находим максимальное из них
    for (int i = 0; i < 5; i++) {
        five_nums[i] = vect[i];
    }
    unsigned int max_id = find_max_id(five_nums);

    // заменяем максимальный из пяти элемент на элемент из вектора, меньший максимального
    for (unsigned int i = 5; i < vect.size(); i++) {
        if (five_nums[max_id] > vect[i]) {
            five_nums[max_id] = vect[i];
            max_id = find_max_id(five_nums);
        }
    }
    return five_nums[max_id];
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
#endif

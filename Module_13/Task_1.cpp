#ifdef __MODULE_13__
/* Задача 1
 *  Необходимо из заданного пользователем вектора удалить число X.
 *  Как работает программа
 *  1. Пользователь вводит с клавиатуры число n — размер вектора, который надо заполнять.
 *  2. Пользователь вводит n целых чисел, которые заполняют вектор.
 *  3. Пользователь вводит значение — X. X — удаляемое из вектора значение. Необходимо удалить из
 *     вектора все элементы, которые равны заданному значению.
 *  4. В конце программы необходимо вывести итоговое состояние вектора. */

#include <iostream>
#include <vector>
#include <cassert>
#include "Module_13.hpp"

// функция удаления всех элементов вектора, равных X
static void delete_num_from_vector(std::vector<int> &vect, int X) {
    unsigned int i = 0;
    int tmp;
    while (i < vect.size()) {
        if (vect[i] == X) {
            // перестановка рассматриваемого элемента вектора в конец
            for (unsigned int j = i + 1; j < vect.size(); j++) {
                tmp = vect[j - 1];
                vect[j - 1] = vect[j];
                vect[j] = tmp;
            }

            // по заданию требуется использовать метод pop_back, удаляющую последний элемент вектора,
            // хотя можно было упростить удалением элемента из середины с помощью метода erase
            vect.pop_back();
        } else
            i++;
    }
}

// функция вывода на экран вектора
static void print_vector(std::vector<int> vect) {
    if (vect.size() > 0){
        for (int n : vect)
            std::cout << n << " ";
        std::cout << "\n";
    } else
        std::cout << "Вектор пуст!\n";
}

// функция получения size значений, заносимых в возвращаемый впоследствии вектор
static std::vector<int> get_vector(int size) {
    // в режиме дебага проверим, что размер вектора передается корректный
    assert(size > 0);

    std::vector<int> vect(size);

    for (int i = 0; i < size; i++) {
        std::cout << "Введите " << i << "-е число вектора: ";
        std::cin >> vect[i];
    }

    return vect;
}

void Task_13_1() {
    std::cout << equals << string_tasks[0] << equals;
    
    int size;
    std::vector<int> vect;
    std::cout << "Введите размер вектора: ";
    std::cin >> size;

    if (size > 0) {
        vect = get_vector(size);
        
        int X;
        std::cout << "Введите число для полного удаления из вектора: ";
        std::cin >> X;

        std::cout << "Вектор до удаления: \n";
        print_vector(vect);

        delete_num_from_vector(vect, X);
        std::cout << "Вектор после удаления: \n";
        print_vector(vect);
    } else
        std::cout << "Создание вектора невозможно!\n";
}
#endif

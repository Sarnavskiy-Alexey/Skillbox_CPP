#ifdef __MODULE_35__
/* Задание 2 (урок 3)
 *  Цель задания:
 *  Поработать с новыми структурами данных.
 *  
 *  Что нужно сделать:
 *  Так как std::unordered_set позволяет нам быстро определять, есть ли указанный ключ в контейнере,
 *  мы можем использовать его для фильтрации уникальных чисел.
 *  Создайте лямбда-выражение, принимающее на вход std::vector<int>, в котором содержатся числа,
 *  которые могут повторяться. Внутри лямбды создайте unordered_set и при помощи него определяйте,
 *  сколько раз текущее число вам встречалось раньше. В результате верните
 *  std::unique_ptr<std::vector<int>>, содержащий числа без повторов. При проходе по контейнеру
 *  используйте новый формат цикла for и ключевое слово auto.  */

#include <iostream>
#include <unordered_set>
#include <vector>
#include <memory>
#include <algorithm>
#include "Module_35.hpp"

static auto my_unique = [](std::vector<int>& V) {
    std::unordered_set<int> us;
    std::unordered_set<int> anti_us;
    std::vector<int> res;

    for (auto &n : V) {
        if (us.count(n)) {
            anti_us.insert(n);
        }
        us.insert(n);
    }

    for (auto &n: us) {
        if (!anti_us.count(n)) {
            res.push_back(n);
        }
    }

    return std::make_unique<std::vector<int>>(res);
};

void Task_35_2() {
    std::cout << equals << string_tasks[1] << equals;

    std::vector<int> v = {1,2,3,4,4,6,6,6,7,8};
    auto unique_numbers = my_unique(v);
    for (auto it = unique_numbers->begin(); it != unique_numbers->end(); it++) {
        std::cout << *it << " ";
    }

    std::cout << "\n";
}
#endif

#ifdef __MODULE_35__
/* Задание 1 (к уроку 2)
 *  Цель задания:
 *  Закрепить работу с нововведениями в базовых конструкциях языка.
 *  
 *  Что нужно сделать:
 *  Вспомните пример с range-based циклом по закрытию файлов:
 *  
 *      for(auto &tFile : files)
 *          currentFile.close();
 *  
 *  По аналогии распечатайте числа от 1 до 5, используя auto и initializer_list. */

#include <iostream>
#include <vector>
#include "Module_35.hpp"

template<typename T>
class Task35_1_class {
private:
    std::vector<T> numbers;
public:
    Task35_1_class(std::initializer_list<T> _numbers) : numbers(_numbers) {}

    void print() {
        if (numbers.size()) {
            for (auto &num : numbers) {
                std::cout << num << " ";
            }
            std::cout << "\n";
        } else {
            std::cout << "Ни одного числа не добавлено в вектор!\n";
        }
    }
};

void Task_35_1() {
    std::cout << equals << string_tasks[0] << equals;

    auto tsk35_1_cl = Task35_1_class<int>{ 1, 2, 3, 4, 5 };
    tsk35_1_cl.print();
}
#endif

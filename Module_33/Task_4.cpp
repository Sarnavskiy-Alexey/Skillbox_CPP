#ifdef __MODULE_33__
/* Задание 4. Среднее арифметическое число в массиве
 *  Что нужно сделать:
 *  Реализуйте шаблонную функцию подсчёта среднего арифметического числа в массиве скалярных чисел
 *  произвольного типа. Это может быть int, double, float и так далее.
 *  Ввод данных массива и вывод результата производится через стандартную консоль.
 *  
 *  Рекомендации:
 *  Для простоты можете реализовать подсчёт в массиве фиксированной длины.
 *  Функцию ввода данных массива тоже рекомендуется реализовать как шаблонную.
 *  Обе функции имеют похожую сигнатуру вида: 
 *  template < typename T >
 *  void input(T array[8])
 *  {
 *      std::cout << "Fill the array (8):";
 *      for (int i = 0; i < 8; ++i)
 *      {
 *  \\*ввод отдельных элементов*\/    
 *      }
 *  }
 *  
 *  Что оценивается:
 *  Корректность работы программы при различных пользовательских данных и различных типах
 *  используемых данных массива. */

#include <iostream>
#include <vector>
#include <exception>
#include "Module_33.hpp"
#include "Module_33_Exceptions.hpp"

template<typename T>
static double average_value(const std::vector<T>& v) {
    if (v.size() == 0) {
        throw VectorSizeIsZeroException();
    }
    double result = 0.0;
    for (const T& n : v) {
        result += (double)n;
    }
    return result / v.size();
}

void Task_33_4() {
    std::cout << equals << string_tasks[3] << equals;

    std::vector<int> v = {4, 2, 6, 8, 3};
    std::cout << average_value(v) << "\n";
}
#endif

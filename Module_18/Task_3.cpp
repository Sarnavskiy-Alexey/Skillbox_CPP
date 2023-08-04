#ifdef __MODULE_18__
/* Задача 3
 *  Что нужно сделать
 *  Напишите рекурсивную функцию, которая принимает большое число n типа long long и переменную ans,
 *  а возвращает void. После завершения работы функции в переменной ans должно оказаться количество
 *  чётных цифр в записи числа n.
 *  Пример:
 *    int ans;
 *    evendigits(9 223 372 036 854 775 806, ans);
 *    //ans == 10
 *  Пояснение: 9 223 372 036 854 775 806 */

#include <iostream>
#include "Module_18.hpp"

void evendigits(long long n, int& ans) {
    static int level = 0;
    static int k = 0;
    if (n != 0) {
        level++;
        if (n % 2 == 0)
            k++;
        evendigits(n / 10, ans);
        if (n % 2 == 0)
            k--;
        level--;
    } else
        ans = k;
}

void Task_18_3() {
    std::cout << equals << string_tasks[2] << equals;

    int ans;
    long long number;
    std::cout << "Введите число для проверки количества четных цифр: ";
    std::cin >> number;
    evendigits(number, ans);
    std::cout << "Количество четных цифр: " << ans << "\n";
}
#endif

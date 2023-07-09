#ifdef __MODULE_09__
/* Задание 2. Длинное вещественное число
 *  Вы решили разработать программу - калькулятор, которая складывает числа сколько угодно большой
 *  длины.Для этого вы планируете работать с ними как со строками.Первая проблема, с которой вы
 *  столкнулись, — по данной строке нужно понять, является она корректной записью вещественного
 *  числа или нет.
 *  Корректной считается запись, удовлетворяющая следующим условиям:
 *  - Первым символом должна быть либо цифра, либо точка, либо знак минус.
 *  - После этого может идти ещё несколько цифр(возможно, ни одной).
 *  - Затем может идти точка, отделяющая целую часть от дробной. До точки может и не быть цифр. В
 *    таком случае считается, что до точки стоит 0.
 *  - После точки идёт ещё несколько цифр(возможно, ни одной). Хотя бы одна цифра в записи числа
 *    должна присутствовать. (Чтобы не усложнять задачу, в этом задании мы не будем рассматривать
 *    числа в экспоненциальной записи, такие как 1.2e-3.)
 *  Напишите программу, которая получает от пользователя строку и выводит ответ Yes, если эта
 *  строка корректно задаёт вещественное число, в противном случае выводит No. */

#include <iostream>
#include "Module_09.hpp"

void Task_09_2() {
    std::cout << equals << string_tasks[1] << equals;

    std::cout << "Введите вещественное число в виде строки: ";
    std::string numberStr;
    std::cin >> numberStr;

    int points = 0;
    int rightNumber = 0;
    for (unsigned int i = (numberStr[0] == '-'); i < numberStr.length(); i++) {
        if (numberStr[i] >= '0' && numberStr[i] <= '9')
            rightNumber = 1;
        else if (!points && numberStr[i] == '.')
            points++;
        else {
            rightNumber = 0;
            break;
        }
    }

    std::cout << (rightNumber ? "Yes" : "No");
    std::cout << "\n";
}
#endif

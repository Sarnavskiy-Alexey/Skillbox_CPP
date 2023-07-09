#ifdef __MODULE_09__
/* Задание 5. Из обычных чисел — в римские (дополнительное задание)
 *  Напишите программу, которая переводит данное пользователем число в римскую запись. Например,
 *  19 в римской записи — XIX.
 *  Римскую запись числа можно получить, если следовать правилам:
 *  - Сначала в ней идут буквы, обозначающие количество тысяч в числе.
 *  - Затем идут буквы, обозначающие количество сотен, затем буквы, обозначающие количество
 *  десятков, и в конце — буквы, обозначающие количество единиц.
 *  - Для записи используются следующие буквы : 1 — I, 5 — V, 10 — X, 50 — L, 100 — C, 500 — D и
 *  1000 — M.
 *  - Число получается как сумма значений использованных в нём букв, за тем исключением, что если
 *  буква с меньшим значением идёт перед буквой с большим значением, то её значение вычитается из
 *  значения числа.
 *  - Вычитание используется, только когда надо передать цифру 4 или 9, в остальных случаях
 *  используется сложение. Например, 9 обозначается как IX, 40 — как XL.
 *  - В числе запрещено писать более трёх одинаковых букв подряд.Таким образом, максимальное
 *  число, которое можно записать по этим правилам, — 3999.
 *  Программе на вход даётся целое число из диапазона от 1 до 3999. Вы можете считывать его как
 *  число или как строку, если так удобнее.
 *  Программа должна вывести римскую запись данного числа. */

#include <iostream>
#include "Module_09.hpp"

void Task_09_5() {
    std::cout << equals << string_tasks[4] << equals;

    int number, remainedNumber, digit, counter = 0;
    std::string numberRoman;
    
    // безопасный ввод числа
    do {
        std::cout << "Введите число для перевода в римскую запись: ";
        std::cin >> number;
        if (number < 1 || number > 3999)
            std::cout << "ОШИБКА! Перевод этого числа в римскую запись невозможен!\n";
    } while (number < 1 || number > 3999);
    remainedNumber = number;

    while (remainedNumber != 0)
    {
        digit = remainedNumber % 10;
        remainedNumber /= 10;
        switch (digit) {
            case 3: numberRoman = (counter == 0 ? "I"
                                                : (counter == 1 ? "X"
                                                                : (counter == 2 ? "C" : "M")))
                                  + numberRoman;
            case 2: numberRoman = (counter == 0 ? "I"
                                                : (counter == 1 ? "X"
                                                                : (counter == 2 ? "C" : "M")))
                                  + numberRoman;
            case 1: numberRoman = (counter == 0 ? "I"
                                                : (counter == 1 ? "X"
                                                                : (counter == 2 ? "C" : "M")))
                                  + numberRoman;
                break;
            case 8: numberRoman = (counter == 0 ? "I" : (counter == 1 ? "X" : "C")) + numberRoman;
            case 7: numberRoman = (counter == 0 ? "I" : (counter == 1 ? "X" : "C")) + numberRoman;
            case 6: numberRoman = (counter == 0 ? "I" : (counter == 1 ? "X" : "C")) + numberRoman;
            case 5: numberRoman = (counter == 0 ? "V" : (counter == 1 ? "L" : "D")) + numberRoman;
                break;
            case 4: numberRoman = (counter == 0 ? "IV" : (counter == 1 ? "XL" : "CD"))
                                  + numberRoman;
                break;
            case 9: numberRoman = (counter == 0 ? "IX" : (counter == 1 ? "XC" : "CM"))
                                  + numberRoman;
                break;
        }

        counter++;
    }

    std::cout << "Загаданное число " << number << " в римской записи: " << numberRoman << "\n";
}
#endif

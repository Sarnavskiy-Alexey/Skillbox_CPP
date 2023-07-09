#ifdef __MODULE_06__
/* Задание 7. Сокращение дроби* (дополнительное задание)
 *  Пользователь вводит числа M и N. Напишите программу, которая преобразует дробь M/N к
 *  несократимому виду и выдаёт получившийся результат. Обеспечьте контроль ввода. */

#include <iostream>
#include "Module_06.hpp"

void Task_06_7() {
    std::cout << equals << string_tasks[6] << equals;

    int M, N;
    std::cout << "Введите числитель: ";
    std::cin >> M;
    std::cout << "Введите знаменатель: ";
    std::cin >> N;
    
    std::cout << "\n----------------Сокращение дроби----------------\n\n";

    if (N == 0)
        std::cout << "Ошибка! На ноль делить нельзя!\n";
    else {
        int GCD, GCD_M = M, GCD_N = N; // GCD - greatest common divisor

        // алгоритм Евклида
        while (GCD_M != GCD_N) {
            if (GCD_M > GCD_N)
                GCD_M -= GCD_N;
            else
                GCD_N -= GCD_M;
        }
        GCD = GCD_M;

        M /= GCD;
        N /= GCD;

        if (N < 0) {
            N *= (-1);
            M *= (-1);
        }

        std::cout << "Сокращенная дробь: " << M << "/" << N << "\n";
    }
}
#endif

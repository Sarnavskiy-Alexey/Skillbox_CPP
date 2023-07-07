/* Задание 6. Усложнение задачи про кирпич
 *  На видео мы с вами писали программу для проверки, удастся ли засунуть кирпич определённых
 *  размеров в определённое прямоугольное отверстие. Теперь представьте, что у вас имеется коробка
 *  размером AxBxC и другая коробка размером MxNxK. Напишите программу, которая по шести данным
 *  числам A, B, C, M, N, K проверяет, можно ли первую коробку положить внутрь второй. Разумеется,
 *  коробки можно как угодно переворачивать, но одна коробка должна помещаться в другую целиком.
 *  Как обычно, постарайтесь сделать свою программу по возможности лаконичнее. */

#include <iostream>
#include "Module_05.hpp"

void Task_05_6() {
    std::cout << equals << string_tasks[5] << equals;

    int A, B, C, M, N, K;
    std::cout << "Введите размеры первой коробки: ";
    std::cin >> A >> B >> C;
    std::cout << "Введите размеры второй коробки: ";
    std::cin >> M >> N >> K;
    
    std::cout << "\n----------------Проверка----------------\n\n";

    /* для решения задачи понадобится два действия:
    1) упорядочить в порядке возрастания введенные значения первой коробки;
    2) упорядочить в порядке возрастания введенные значения второй коробки;
    3) сравнить по порядку A, B, C с M, N, K соответственно */
    
    /* 1.1) переместим максимальное из трех значений в A */
    if (A > B && A > C) {
        /* ничего не меняем */
    }
    else if (B > A && B > C) {
        int tmp = A; A = B; B = tmp;
    }
    else {
        int tmp = A; A = C; C = tmp;
    }
    /* 1.2) при необходимости поменяем B и C */
    if (B < C) {
        int tmp = B; B = C; C = tmp;
    }
    
    /* 2.1) переместим максимальное из трех значений в M */
    if (M > N && M > K) {
        /* ничего не меняем */
    }
    else if (N > M && N > K) {
        int tmp = M; M = N; N = tmp;
    }
    else {
        int tmp = M; M = K; K = tmp;
    }
    /* 2.2) при необходимости поменяем N и K */
    if (N < K) {
        int tmp = N; N = K; K = tmp;
    }

    /* 3) проверяем условие вхождения первой коробки во вторую */
    if (A <= M && B <= N && C <= K)
        std::cout << "Условия вхождения первой коробки во вторую выполнены!\n";
    else
        std::cout << "Условия вхождения первой коробки во вторую не выполнены!\n";
}
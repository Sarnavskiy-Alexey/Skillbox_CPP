#ifdef __MODULE_07__
/* Задание 8. Ёлочка* (дополнительное задание)
 *  Напишите программу, которая выводит на экран равнобедренный треугольник, заполненный символами
 *  решётки «#». Пусть высота треугольника вводится пользователем. Обеспечьте контроль ввода. */

#include <iostream>
#include "Module_07.hpp"

void Task_07_8() {
    std::cout << equals << string_tasks[7] << equals;

    int heightFir;
    do {
        std::cout << "Введите высоту дерева: ";
        std::cin >> heightFir;
        if (heightFir <= 0) std::cout << "Дерево не растет вглубь! Высота должна быть положительной!\n";
    } while (heightFir <= 0);
    
    for (int i = 0; i < heightFir; i++) {
        for (int j = 0; j < heightFir - i - 1; j++)
            std::cout << " ";
        for (int j = 0; j < i * 2 + 1; j++)
            std::cout << "#";
        std::cout << "\n";
    }
    std::cout << "\n";
}
#endif

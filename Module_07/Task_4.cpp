/* Задание 4. Рамка
 *  Напишите программу, которая рисует с помощью символьной графики прямоугольную рамку. Для
 *  вертикальных линий используйте символ вертикального штриха «|», а для горизонтальных — дефис
 *  «-». Пусть пользователь вводит ширину и высоту рамки. */

#include <iostream>
#include "Module_07.hpp"

void Task_07_4() {
    std::cout << equals << string_tasks[3] << equals;

    int lengthFrame, widthFrame;
    std::cout << "Введите длину и ширину рамки: ";
    std::cin >> lengthFrame >> widthFrame;

    for (int i = 0; i < lengthFrame; i++) {
        for (int j = 0; j < widthFrame; j++) {
            if (j == 0 || j == widthFrame - 1) std::cout << "|";
            else if (i == 0 || i == lengthFrame - 1) std::cout << "-";
            else std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
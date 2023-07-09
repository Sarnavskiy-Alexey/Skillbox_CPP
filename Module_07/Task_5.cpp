#ifdef __MODULE_07__
/* Задание 5. Координатные оси
 *  Модифицируйте пример с координатными осями так, чтобы в точке их пересечения рисовался знак
 *  «+», на верхнем конце вертикальной оси была стрелка вверх «^», а на правом конце горизонтальной
 *  оси — стрелка вправо «>». Это сделает рисунок более красивым и точным. */

#include <iostream>
#include "Module_07.hpp"

void Task_07_5() {
    std::cout << equals << string_tasks[4] << equals;

    const int maxRow = 20, maxCol = 50;
    for (int row = 0; row < maxRow; row++) {
        for (int col = 0; col < maxCol; col++) {
            if (row == 0 && col == maxCol / 2) std::cout << "^";
            else if (row == maxRow / 2 && col == maxCol - 1) std::cout << ">";
            else if (row == maxRow / 2 && col == maxCol / 2) std::cout << "+";
            else if (row == maxRow / 2) std::cout << "-";
            else if (col == maxCol / 2) std::cout << "|";
            else std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
#endif

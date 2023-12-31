#ifdef __MODULE_08__
/* Задание 3. Игрушечная история
 *  Вы решили открыть бизнес по производству игровых деревянных кубиков для детей. Вы узнали, что
 *  лучше всего продаются кубики со стороной 5 см в наборах по несколько штук, причём кубиков в
 *  наборе должно быть достаточно, чтобы сложить из них один большой куб. Для изготовления кубиков
 *  к вам в мастерскую поступают деревянные бруски в форме прямоугольных параллелепипедов любых
 *  размеров.
 *  Для оптимизации бизнес-процессов напишите программу, которая по заданным размерам исходного
 *  бруска определяет, сколько кубиков из него можно изготовить, можно ли из них составить набор
 *  для продажи и если можно, то максимальное число кубиков в этом наборе. Все кубики должны быть
 *  из цельного дерева без использования клея. Размеры бруска — вещественные числа. Обеспечьте
 *  контроль ввода.
 *  Например:
 *  Из бруска 20x35x5 можно изготовить 28 кубиков.
 *  Из 28 кубиков можно собрать набор из 27 кубиков. */

#include <iostream>
#include <cmath>
#include "Module_08.hpp"

void Task_08_3() {
    std::cout << equals << string_tasks[2] << equals;

    float lengthBlock, widthBlock, heightBlock;

    // ввод длины бруска
    do {
        std::cout << "Введите длину бруска: ";
        std::cin >> lengthBlock;
        if (lengthBlock <= 0.0f)
            std::cout << "ОШИБКА! Длина бруска должна быть положительной!\n";
    } while (lengthBlock <= 0.0f);

    // ввод ширины бруска
    do {
        std::cout << "Введите ширину бруска: ";
        std::cin >> widthBlock;
        if (widthBlock <= 0.0f)
            std::cout << "ОШИБКА! Ширина бруска должна быть положительной!\n";
    } while (widthBlock <= 0.0f);

    // ввод длины бруска
    do {
        std::cout << "Введите высоту бруска: ";
        std::cin >> heightBlock;
        if (heightBlock <= 0.0f)
            std::cout << "ОШИБКА! Высота бруска должна быть положительной!\n";
    } while (heightBlock <= 0.0f);

    // проверка на невозможность составления кубиков из цельного дерева
    if (lengthBlock < 5.0f || widthBlock < 5.0f || heightBlock < 5.0f)
        std::cout << "Построение кубиков из цельного дерева невозможно!\n";
    // если размеры бруска позволяют, то считаем возможное количество кубиков
    else {
        int countCubes = (int)lengthBlock / 5;
        countCubes *= (int)widthBlock / 5;
        countCubes *= (int)heightBlock / 5;

        std::cout << "Из бруска " << lengthBlock << "x" << widthBlock << "x" << heightBlock
                  << " можно изготовить " << countCubes << " куб.\n";

        if (std::cbrt((float)countCubes) >= 2)
            std::cout << "Из " << countCubes << "куб. можно собрать набор из "
                      << std::pow((int)(std::cbrt((float)countCubes)), 3) << " куб.\n";
        else
            std::cout << "Набор составить нельзя!\n";
    }
}
#endif

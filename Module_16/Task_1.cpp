#ifdef __MODULE_16__
/* Задание 1. Спидометр
 *  Что нужно сделать
 *  Реализуйте цифровой спидометр автомобиля. Сама модель автомобиля, которую нужно будет
 *  воссоздать, весьма проста. Начальная скорость — 0 км/ч. Пользователь вводит в стандартный ввод
 *  разницу (дельту) в скорости, и результирующая скорость показывается на спидометре в стандартный
 *  вывод. Так происходит до той поры, пока машина снова не остановится, то есть пока скорость не
 *  станет меньше или равна нулю (сравнение должно происходить с дельтой в 0,01). Диапазон возможных
 *  значений скорости машины от 0 до 150 км/ч. Сам показатель спидометра вместе с единицами
 *  измерения требуется записывать в отдельную строку-буфер, которая потом и будет показываться на
 *  экране. Точность отображения скорости — до 0,1 км/ч.
 *  
 *  Пример работы программы:
 *  Speed delta:30
 *  Speed: 30.0
 *  Speed delta:20.2
 *  Speed: 50.2
 *  Speed delta:100
 *  Speed: 150.0
 *  Speed delta:-22.24
 *  Speed: 127.8
 *  
 *  Рекомендации:
 *  Используйте цикл do … while для организации постоянного опроса пользователя. Для отображения
 *  числа с нужной точностью воспользуйтесь функцией std::sprintf(speed_str, "%.1f", speed_value);
 *  где speed_str — строка, в которую функция sprintf «печатает» значение скорости (speed_value) с
 *  одним знаком после десятичной точки (%.1f).  */

#include <iostream>
#include <cstdio>
#include "Module_16.hpp"

void Task_16_1() {
    std::cout << equals << string_tasks[0] << equals;

    float speed = 0.0f;
    float add_speed;
    char buffer[50];

    do {
        std::cout << "Разница в скоростях: ";
        std::cin >> add_speed;
        speed += add_speed;
        std::sprintf(buffer, "Скорость: %.1f\n", speed);
        std::cout << buffer;
    } while (speed > 0.01);
}
#endif

/* Задание 1. Космический симулятор
 *  Вы пишете симулятор космических полётов. Ваш звездолёт массой m килограмм включает двигатель с
 *  силой тяги F ньютонов на t секунд. Напишите программу, которая по заданным F, m и t покажет, на
 *  каком расстоянии от первоначального положения окажется космический корабль через t секунд.
 *  Обеспечьте контроль ввода.
 *  Примечание: космический корабль находится в открытом космосе.
 *  Напоминаем, что расстояние можно рассчитать по формуле:
 *  a * t ^ 2 / 2, где a = F / m */

#include <iostream>
#include <cmath>
#include "Module_08.hpp"

void Task_08_1() {
    std::cout << equals << string_tasks[0] << equals;

    float m, F, t;

    // безопасный ввод массы шатла
    do {
        std::cout << "Введите массу шатла (кг): ";
        std::cin >> m;
        if (m <= 0.0f)
            std::cout << "ОШИБКА! Масса звездолета должна быть положительной!\n";
    } while (m <= 0.0f);

    // ввод тяги двигателя (может быть отрицательным: включение реверса)
    std::cout << "Введите силу тяги двигателя (Н): ";
    std::cin >> F;

    // безопасный ввод 
    do {
        std::cout << "Введите количество секунд работы двигателя звездолета (сек): ";
        std::cin >> t;
        if (t <= 0.0f)
            std::cout << "ОШИБКА! Количество секунд работы двигателя звездолета должно быть положительным!\n";
    } while (t <= 0.0f);

    // расчет пройденной дистанции
    float distance = std::fabs(F) / m * t * t / 2 / 1000;
    std::cout << "Звездолет пройдет (км): " << distance << "\n";
}
#ifdef __MODULE_04__
/* Задание 6. Улучшим барберов
 *  Помните задачу про барберов из видео 4.3? Кстати, именно оператор % мог помочь нам с барберами.
 *  Перепишите программу про них с его использованием для проверки на проблему с целочисленным
 *  делением.
 *  Напишите программу, которая отвечает на вопрос хватает ли барберов в данном городе если задано
 *  число людей и число барберов, а так же указано, что один барбер работает 8 часов в день, на
 *  одного клиента тратит 1 час а каждый клиент приходит раз в месяц. Воспользуйтесь для решения
 *  проблемы целочисленного деления оператором % */

#include <iostream>
#include "Module_04.hpp"

void Task_04_6() {
    std::cout << equals << string_tasks[5] << equals;

    int mansCount, barbersCount, mansPerBarber, mansPerBarberPerMonth,
    requiredBarbersCount;
    
    std::cout << "Введите количество мужчин в городе: ";
    std::cin >> mansCount;
    std::cout << "Введите количество нанятых барберов: ";
    std::cin >> barbersCount;
    std::cout << "Введите количество обслуживаемых одним барбером за день мужчин: ";
    std::cin >> mansPerBarber;
    mansPerBarberPerMonth = mansPerBarber * 30;
    std::cout << "В месяц обслуживается одним барбером: " << mansPerBarberPerMonth << " муж.\n";

    requiredBarbersCount = mansCount / mansPerBarberPerMonth;
    if (mansCount % mansPerBarberPerMonth)
        requiredBarbersCount++;
    std::cout << "Необходимое количество барберов: " << requiredBarbersCount << "\n";

    if (requiredBarbersCount > barbersCount)
        std::cout << "Нужно больше барберов!\n";
    else
        std::cout << "Барберов хватает!\n";
}
#endif

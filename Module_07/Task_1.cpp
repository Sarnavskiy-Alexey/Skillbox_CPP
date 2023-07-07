/* Задание 1. Запасы продовольствия
 *  Ваш космический корабль потерпел крушение на пустынной планете. Еда здесь не растёт, но вы
 * спасли из-под обломков 100-килограммовый мешок гречки. Из прошлого опыта вы знаете, что если
 * будете экономно питаться, то у вас будет уходить по четыре килограмма гречки в месяц. Чтобы
 * прикинуть гречневый бюджет, вы решили написать программу, которая выведет информацию о том,
 * сколько килограммов гречки у вас должно быть в запасе через месяц, два и так далее, пока она не
 * закончится. */

#include <iostream>
#include "Module_07.hpp"

void Task_07_1() {
    std::cout << equals << string_tasks[0] << equals;
    
    int buckwheatSaved = 100;
    int buckwheatSpends = 4;
    int buckwheatRemained, month;

    std::cout << "Всего гречки было на начало подсчёта: " << buckwheatSaved << " кг\n";
    
    for (buckwheatRemained = buckwheatSaved - buckwheatSpends, month = 1;
         buckwheatRemained > 0;
         buckwheatRemained -= buckwheatSpends, month++) {
        std::cout << "После " << month << "-го месяца у вас в запасе останется "
                  << buckwheatRemained << " кг гречки.\n";
    }
    std::cout << "После " << month << "-го месяца гречка закончится... :_(\n";
}
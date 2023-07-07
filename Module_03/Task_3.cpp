/* Задача 3. Злостные вредители
 *  На бамбуковой плантации завелись гусеницы. Они спят днём и едят бамбук ночью. Бамбук генно-
 *  модифицированный, растёт только при свете дня, зато очень быстро — по 50 сантиметров ежедневно!
 *  Гусеницы съедают 20 сантиметров бамбука каждую ночь. Бамбуковые саженцы при посадке утром имеют
 *  высоту один метр.
 *  Напишите программу, которая считает, какой высоты будет бамбук в середине третьего дня.
 *  Усложнение — посчитайте это не за несколько подходов, а одной формулой. */

#include <iostream>
#include "Module_03.hpp"

void Task_03_3() {
    std::cout << equals << string_tasks[2] << equals;

    unsigned beginHeight = 100;
    unsigned dailyGrowth = 50;
    unsigned nightFade = 20;
    unsigned result;
    double days = 2.5;
    double nights = 2.0;

    std::cout << "     Высота при посадке: " << beginHeight << " см\n";
    std::cout << "       В день растет на: " << dailyGrowth << " см\n";
    std::cout << "Гусеницы съедают в ночь: " << nightFade << " см\n";
    std::cout << "            Прошло дней: " << days << "\n";
    std::cout << "           Прошло ночей: " << nights << "\n";
    
    result = beginHeight + dailyGrowth * days - nightFade * nights;

    std::cout << "Высота бамбука: " << result << " см\n";
}
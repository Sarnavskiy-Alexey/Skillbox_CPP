#ifdef __MODULE_02__
/* Задание 4. Непонятная квитанция
 *  Управляющая компания рассылает странные квитанции: в них указана только полная стоимость
 *  ремонта многоквартирного дома, а сколько должна платить конкретная квартира — непонятно.
 *  Напишите программу, с помощью которой жители квартир смогут посчитать, какую сумму им надо
 *  заплатить. Сумма делится на все квартиры вне зависимости от площади, количества жильцов и
 *  комнат. Все значения сохраните в переменные и выводите в нужных местах, имитируя ввод данных.
 */

#include <iostream>
#include "Module_02.hpp"

void Task_02_4() {
    std::cout << equals << string_tasks[3] << equals;
    int flatAmount = 160;
    double repairPrice = 400000.0;
    double repairPriceForOneFlat = repairPrice / flatAmount;

    std::cout << "         Введите количество квартир: " << flatAmount << " кв.\n";
    std::cout << "     Введите стоимость кап. ремонта: " << repairPrice << " руб.\n";
    std::cout << "Каждая квартира должна заплатить по: " << repairPriceForOneFlat << " руб.\n";
}
#endif

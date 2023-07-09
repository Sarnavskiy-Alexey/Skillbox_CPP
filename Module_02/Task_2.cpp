#ifdef __MODULE_02__
/* Задание 2. Калькулятор стоимости товара
 *  Напишите калькулятор для расчёта полной стоимости товара. Она рассчитывается так: стоимость
 *  товара  + стоимость доставки – скидка. Все значения сохраните в переменные и выводите в нужных
 *  местах, имитируя ввод данных (речь про cout). */

#include <iostream>
#include "Module_02.hpp"

void Task_02_2() {
    std::cout << equals << string_tasks[1] << equals;
    double price = 40000.0;
    double delivery_price = 500.0;
    double sale = 1000.0;
    double full_price = price + delivery_price - sale;

    std::cout << "  Стоимость товара: " << price << " руб.\n";
    std::cout << "Стоимость доставки: " << delivery_price << " руб.\n";
    std::cout << "     Размер скидки: " << sale << " руб.\n";
    std::cout << "             Итого: " << full_price << " руб.\n";
}
#endif

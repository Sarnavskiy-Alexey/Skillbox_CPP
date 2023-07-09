#ifdef __MODULE_02__
#pragma once

const std::string string_tasks[] = {
    "\t\t\tЗадание 1. Улучшаем гонщика\n  Исправьте код программы так, чтобы значение скорости рассчитывалось автоматически. Скорость — это сумма показателей двигателя, колёс и руля минус показатели дождя и ветра.\n",
    "\t\t\tЗадание 2. Калькулятор стоимости товара\n  Напишите калькулятор для расчёта полной стоимости товара. Она рассчитывается так: стоимость товара  + стоимость доставки – скидка. Все значения сохраните в переменные и выводите в нужных местах, имитируя ввод данных (речь про cout).\n",
    "\t\t\tЗадание 3. Время, время!\n  Напишите программу для ресторана быстрого питания «Крылышки и ножки». Компания хочет знать, какое количество клиентов успеет обслужить один кассир за рабочую смену. Время на обслуживание складывается из времени, за которое клиент делает заказ, и времени, за которое кассир собирает заказ и выдаёт его клиенту. Все расчёты проводите в минутах. Все значения сохраните в переменные и выводите в нужных местах, имитируя ввод данных.\n",
    "\t\t\tЗадание 4. Непонятная квитанция\n  Управляющая компания рассылает странные квитанции: в них указана только полная стоимость ремонта многоквартирного дома, а сколько должна платить конкретная квартира — непонятно. Напишите программу, с помощью которой жители квартир смогут посчитать, какую сумму им надо заплатить. Сумма делится на все квартиры вне зависимости от площади, количества жильцов и комнат. Все значения сохраните в переменные и выводите в нужных местах, имитируя ввод данных.\n"
};

extern const std::string equals;

void Task_02_1();
void Task_02_2();
void Task_02_3();
void Task_02_4();
#endif

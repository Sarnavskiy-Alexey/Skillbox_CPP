#ifdef __MODULE_02__
/* Задание 3. Время, время!
 *  Напишите программу для ресторана быстрого питания «Крылышки и ножки». Компания хочет знать,
 *  какое количество клиентов успеет обслужить один кассир за рабочую смену. Время на обслуживание
 *  складывается из времени, за которое клиент делает заказ, и времени, за которое кассир собирает
 *  заказ и выдаёт его клиенту. Все расчёты проводите в минутах. Все значения сохраните в
 *  переменные и выводите в нужных местах, имитируя ввод данных. */

#include <iostream>
#include "Module_02.hpp"

void Task_02_3() {
    std::cout << equals << string_tasks[2] << equals;
    int clientChooses = 2;
    int waiterReady = 11;
    int fullWaiting = clientChooses + waiterReady;
    int workShift = 60 * 4;
    int clientAmount = workShift / fullWaiting;

    std::cout << "Сколько минут клиент потратил на выбор? " << clientChooses << " мин.\n";
    std::cout << "Сколько времени официант собирал заказ? " << waiterReady << " мин.\n";
    std::cout << " Итого потрачено времени на один заказ: " << fullWaiting << " мин.\n";
    std::cout << "За одну смену официант может обслужить: " << clientAmount << " чел.\n";
}
#endif

/* Задача 1. Симулятор маршрутки
 *  Напишите программу, которая симулирует работу маршрутки. Она умеет объявлять остановки и
 *  узнавать у пользователя, сколько человек вышло и зашло на остановке. Пассажиры оплачивают
 *  проезд при входе.
 *  Маршрут состоит из четырёх остановок. Напишите программу так, чтобы в конце она выводила,
 *  сколько денег мы заработали при условии, что билет стоит 20 руб., а расходы следующие:
 *   - четверть — на зарплату водителю;
 *   - пятая часть — на топливо;
 *   - пятая часть — на налоги;
 *   - пятая часть — на ремонт машины. */


#include <iostream>
#include "Module_03.hpp"

void Task_03_1() {
    std::cout << equals << string_tasks[0] << equals;

    const unsigned ticket_price = 20;
    unsigned passengersOut;
    unsigned passengersIn;
    unsigned passengersInBus = 0;
    unsigned recievedMoney = 0;
    std::string bus_stop;

    /* Первая остановка */
    bus_stop = "Улица программистов";
    std::cout << "Прибываем на остановку: \"" << bus_stop << "\"\n";
    passengersOut = 0;
    std::cout << "Пассажиров вышло на остановке: " << passengersOut << "\n";
    passengersIn = 5;
    std::cout << "Пассажиров зашло на остановке: " << passengersIn << "\n";
    passengersInBus += passengersIn - passengersOut;
    std::cout << "Отправление автобуса. Всего пассажиров в салоне: " << passengersInBus << "\n";
    recievedMoney += passengersIn * ticket_price;
    bus_stop = "Аллея массивов";
    std::cout << "Следующая остановка: \"" << bus_stop << "\"\n";
    
    std::cout << "\n-------------Едем-------------\n\n";
    
    /* Вторая остановка */
    std::cout << "Прибываем на остановку: \"" << bus_stop << "\"\n";
    passengersOut = 3;
    std::cout << "Пассажиров вышло на остановке: " << passengersOut << "\n";
    passengersIn = 4;
    std::cout << "Пассажиров зашло на остановке: " << passengersIn << "\n";
    passengersInBus += passengersIn - passengersOut;
    std::cout << "Отправление автобуса. Всего пассажиров в салоне: " << passengersInBus << "\n";
    recievedMoney += passengersIn * ticket_price;
    bus_stop = "Университет им. Тьюринга";
    std::cout << "Следующая остановка: \"" << bus_stop << "\"\n";
    
    std::cout << "\n-------------Едем-------------\n\n";
    
    /* Третья остановка */
    std::cout << "Прибываем на остановку: " << bus_stop << "\n";
    passengersOut = 5;
    std::cout << "Пассажиров вышло на остановке: " << passengersOut << "\n";
    passengersIn = 4;
    std::cout << "Пассажиров зашло на остановке: " << passengersIn << "\n";
    passengersInBus += passengersIn - passengersOut;
    std::cout << "Отправление автобуса. Всего пассажиров в салоне: " << passengersInBus << "\n";
    recievedMoney += passengersIn * ticket_price;
    bus_stop = "Проспект алгоритмов";
    std::cout << "Следующая остановка: \"" << bus_stop << "\"\n";
    
    std::cout << "\n-------------Едем-------------\n\n";

    /* Код для вставки промежуточной остановки:
    std::cout << "Прибываем на остановку: " << bus_stop << "\n";
    passengersOut = <ввести количество пассажиров>;
    std::cout << "Пассажиров вышло на остановке: " << passengersOut << "\n";
    passengersIn = <ввести количество пассажиров>;
    std::cout << "Пассажиров зашло на остановке: " << passengersIn << "\n";
    passengersInBus += passengersIn - passengersOut;
    std::cout << "Отправление автобуса. Всего пассажиров в салоне: " << passengersInBus << "\n";
    recievedMoney += passengersIn * ticket_price;
    bus_stop = "<ввести название следующей остановки>";
    std::cout << "Следующая остановка: " << bus_stop << "\n";
    
    std::cout << "\n-------------Едем-------------\n\n";
    
    */
    
    /* Четвертая (конечная) остановка */
    std::cout << "Прибываем на остановку: " << bus_stop << "\n";
    passengersOut = 5;
    std::cout << "Пассажиров вышло на остановке: " << passengersOut << "\n";
    passengersIn = 0;
    std::cout << "Пассажиров зашло на остановке: " << passengersIn << "\n";
    passengersInBus += passengersIn - passengersOut;
    std::cout << "Конечная. Автобус дальше не идет. Просьба выйти из салона.\nЗа нахождение пассажиров в автобусе, следующем в автостоянку по завершении маршрута, предусмотрена административная ответственность в виде штрафа в размере 5000 руб.\n";
    std::cout << "В салоне осталось пассажиров: " << passengersInBus << "\n";
    recievedMoney += passengersIn * ticket_price;

    /* Подсчет прибыли */
    std::cout << "Всего получено денег за один рейс: " << recievedMoney << " руб.\n";
    
    double driver = recievedMoney / 4.0;
    double fuel = recievedMoney / 5.0;
    double taxes = recievedMoney / 5.0;
    double busRepair = recievedMoney / 5.0;
    double income = recievedMoney - (driver + fuel + taxes + busRepair);

    std::cout << "       Зарплата водителя: " << driver << " руб.\n";
    std::cout << "      Расходы на топливо: " << fuel << " руб.\n";
    std::cout << "                  Налоги: " << taxes << " руб.\n";
    std::cout << "Расходы на ремонт машины: " << busRepair << " руб.\n";
    std::cout << "             Итого доход: " << income << " руб.\n";
}

/*
Маршрут состоит из четырёх остановок. Напишите программу так, чтобы в конце она выводила, сколько денег мы заработали при условии, что билет стоит 20 руб., а расходы следующие:

четверть — на зарплату водителю;
пятая часть — на топливо;
пятая часть — на налоги;
пятая часть — на ремонт машины.
Формат вывода (после прибытия на последнюю остановку):

Всего заработали: 100 руб.

Зарплата водителя: 25 руб.

Расходы на топливо: 20 руб.

Налоги: 20 руб.

Расходы на ремонт машины: 20 руб.

Итого доход: 15 руб.
*/
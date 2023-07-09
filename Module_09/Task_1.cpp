#ifdef __MODULE_09__
/* Задание 1. Время в пути
 *  Поезд отправляется в AA часов BB минут и прибывает в пункт назначения в CC часов DD минут.
 *  Сколько часов и минут он находится в пути?
 *  Напишите программу, которая принимает от пользователя две строки — время отправления и время
 *  прибытия поезда.Время задаётся строкой из пяти символов в формате HH:MM.Обеспечьте контроль
 *  ввода, убедитесь также, что время корректно.
 *  Программа должна ответить, сколько часов и минут поезд находится в пути.Если время отправления
 *  больше времени прибытия, считайте, что поезд прибывает в пункт назначения на следующий день. */

#include <iostream>
#include "Module_09.hpp"

void Task_09_1() {
    std::cout << equals << string_tasks[0] << equals;

    std::string departureTime, arrivalTime;
    int hours, minutes;

    // безопасный ввод времени отправления поезда
    while (true) {
        std::cout << "Введите время отправления поезда в формате HH:MM: ";
        std::cin >> departureTime;
        if (departureTime.length() != 5 ||
            departureTime[0] < '0' || departureTime[0] > '2' ||
            departureTime[1] < '0' || departureTime[1] > '9' ||
            (departureTime[0] == '2' && departureTime[1] > '3') ||
            departureTime[2] != ':' ||
            departureTime[3] < '0' || departureTime[3] > '5' ||
            departureTime[4] < '0' || departureTime[4] > '9') {
            std::cout << "ОШИБКА! Время отправления заполнено некорректно! Попробуйте снова!\n";
        }
        else
            break;
    }

    // безопасный ввод времени прибытия поезда
    while (true) {
        std::cout << "Введите время прибытия поезда в формате HH:MM: ";
        std::cin >> arrivalTime;
        if (arrivalTime.length() != 5 ||
            arrivalTime[0] < '0' || arrivalTime[0] > '2' ||
            arrivalTime[1] < '0' || arrivalTime[1] > '9' ||
            (arrivalTime[0] == '2' && arrivalTime[1] > '3') ||
            arrivalTime[2] != ':' ||
            arrivalTime[3] < '0' || arrivalTime[3] > '5' ||
            arrivalTime[4] < '0' || arrivalTime[4] > '9') {
            std::cout << "ОШИБКА! Время отправления заполнено некорректно! Попробуйте снова!\n";
        }
        else
            break;
    }

    // расчет времени поездки
    hours = (10 * (arrivalTime[0] - '0') + (arrivalTime[1] - '0')) -
        (10 * (departureTime[0] - '0') + (departureTime[1] - '0'));
    if (hours < 0)
        hours += 24;
    minutes = (10 * (arrivalTime[3] - '0') + (arrivalTime[4] - '0')) -
        (10 * (departureTime[3] - '0') + (departureTime[4] - '0'));
    if (minutes < 0) {
        minutes += 60;
        hours--;
    }

    std::cout << "Поездка составляет: " << hours << " ч. " << minutes << " мин.\n";
}
#endif

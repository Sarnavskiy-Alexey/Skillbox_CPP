#ifdef __MODULE_28__
/* Задание 2. Симуляция работы вокзала
 *  Что нужно сделать
 *  С помощью многопоточности реализуйте простую модель железнодорожного вокзала.
 *  С трёх точек отправления в разное время отбывают три разных поезда с условными обозначениями A,
 *  B, C. Все они идут на один и тот же вокзал и могут дойти до него в разное время.
 *  На этом целевом вокзале единовременно может находиться только один поезд. Остальные поезда
 *  должны ждать, пока уже занятое место освободится.
 *  В начале программы пользователь последовательно вводит для каждого поезда время в пути до
 *  вокзала (в секундах). После этого поезда начинают своё движение за заданное количество времени.
 *  Как только поезд прибыл на вокзал, он ожидает от пользователя команды depart, которая
 *  сигнализирует о его отбытии с вокзала.
 *  По всем событиям (прибытие на вокзал, ожидание свободного места, отбытие с вокзала) вместе с
 *  условным обозначением поезда выводятся сообщения в консоль.
 *  Программа завершается, когда на вокзале побывают все три поезда.
 *  
 *  Советы и рекомендации:
 *  Используйте для вокзала отдельный мьютекс и симулируйте ожидание с помощью него. */

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include "Module_28.hpp"

#define SIZE 3U

struct Train {
    std::string name = "A";
    double time_to_station = 0.0;
};

static std::mutex trainStationBusy_mutex;
static std::mutex cout_mutex;

static double safe_enter(std::string invite_str, std::string error_str) {
    double X;
    do {
        std::cout << invite_str;
        std::cin >> X;
        if (X <= 0)
            std::cout << error_str;
    } while (X <= 0);
    
    return X;
}

static void initialization(Train* trains) {
    for (unsigned int i = 0; i < SIZE; i++) {
        trains[i].name[0] += i;
        trains[i].time_to_station = safe_enter("Введите время поезда " + trains[i].name + " до станции в сек.: ",
                                               "Значение времени должно быть больше нуля!\n");
    }
}

static void train_go(Train* train) {
    std::string command;
    double seconds = 0.0;

    // ожидание прибытия
    while (train->time_to_station > seconds) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        seconds += 1.0;
    }
    
    // обработка события "прибытие на станцию"
    if (!trainStationBusy_mutex.try_lock()) {
        cout_mutex.lock();
        std::cout << "Поезд " << train->name << " ожидает разрешения на въезд на станцию!\n";
        cout_mutex.unlock();
        while (!trainStationBusy_mutex.try_lock()) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    cout_mutex.lock();
    std::cout << "Поезд " << train->name << " на станции и ожидает отправки!\n";
    
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    
    // отправка поезда
    std::cout << "Введите \"depart\" для освобождения станции!\n";
    cout_mutex.unlock();
    do {
        std::cin >> command;
    } while (command != "depart");
    cout_mutex.lock();
    std::cout << "Поезд " << train->name << " отправляется от станции!\n";
    cout_mutex.unlock();
    trainStationBusy_mutex.unlock();
}

void Task_28_2() {
    std::cout << equals << string_tasks[1] << equals;

    Train trains[SIZE];
    std::thread train_threads[SIZE];

    initialization(trains);
    for (unsigned int i = 0; i < SIZE; i++) {
        train_threads[i] = std::thread(train_go, &trains[i]);
    }

    for (unsigned int i = 0; i < SIZE; i++) {
        train_threads[i].join();
    }
}
#endif

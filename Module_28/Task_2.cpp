// #ifdef __MODULE_28__
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

enum class TrainState {
    ON_THE_WAY,
    WAITING,
    ON_THE_STATION,
    OUT_OF_THE_STATION
};

enum class StationState {
    EMPTY,
    TRAIN_DEPARTS,
    FULL
};

static StationState trainStationBusy = StationState::EMPTY;
static std::mutex trainStationBusy_mutex;
static unsigned int departedTrains = 0;
static std::mutex departedTrains_mutex;

struct Train {
    char name;
    double time_to_station;
    TrainState state;
};

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
        trains[i].name = 'A' + i;
        trains[i].time_to_station = safe_enter("Введите время поезда " + std::string(&trains[i].name) + " до станции в сек.: ",
                                               "Значение времени должно быть больше нуля!\n");
        trains[i].state = TrainState::ON_THE_WAY;
    }
}

static void train_go(Train* train) {
    double seconds = 0.0;
    bool end = false;
    
    // цикл ожидания прибытия поезда к станции
    while (seconds < train->time_to_station) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        seconds += 1.0;
    }
    
    // поезд подъехал к станции, переводим его в режим ожидания свободного пути
    train->state = TrainState::WAITING;
    
    end = false;
    // цикл проверки свободного пути и перевод поезда в режим "на станции"
    while (true) {
        trainStationBusy_mutex.lock();
        if (trainStationBusy == StationState::EMPTY) {
            trainStationBusy = StationState::FULL;
            train->state = TrainState::ON_THE_STATION;
            std::cout << "Поезд " << train->name << " прибыл на станцию!\n";
            end = true;
        }
        trainStationBusy_mutex.unlock();
        if (end) {
            break;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    end = false;
    // цикл ожидания команды depart и отъезд со станции
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        trainStationBusy_mutex.lock();
        if (trainStationBusy == StationState::TRAIN_DEPARTS) {
            end = true;
            trainStationBusy = StationState::EMPTY;
        }
        trainStationBusy_mutex.unlock();
        if (end) {
            std::cout << "Поезд " << train->name << " отошел от станции!\n";
            departedTrains_mutex.lock();
            departedTrains++;
            departedTrains_mutex.unlock();
            break;
        }
    }
}

static void station_scheduler() {
    bool end = false;           // признак окончания бесконечного цикла
    bool need_command = false;  // признак необходимости ввода команды
    std::string command;        // команда, вводимая пользователем
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        end = false;
        need_command = false;

        // проверка того, что все поезда прошли через станцию и ушли с нее
        departedTrains_mutex.lock();
        if (departedTrains >= SIZE) {
            end = true;
        }
        departedTrains_mutex.unlock();
        if (end) {
            break;
        }

        // узнаем необходимость запроса от пользователя команды
        trainStationBusy_mutex.lock();
        if (trainStationBusy == StationState::FULL) {
            need_command = true;
        }
        trainStationBusy_mutex.unlock();
        if (need_command) {
            std::cin >> command;
            if (command == "depart") {
                trainStationBusy_mutex.lock();
                trainStationBusy = StationState::TRAIN_DEPARTS;
                trainStationBusy_mutex.unlock();
            }
        }
    }
}

void Task_28_2() {
    std::cout << equals << string_tasks[1] << equals;

    Train trains[SIZE];
    std::thread train_threads[SIZE];
    std::thread station_thread;

    initialization(trains);
    for (unsigned int i = 0; i < SIZE; i++) {
        train_threads[i] = std::thread(train_go, &trains[i]);
    }
    station_thread = std::thread(station_scheduler);

    trainStationBusy = StationState::EMPTY;
    departedTrains = 0;

    for (unsigned int i = 0; i < SIZE; i++) {
        train_threads[i].join();
    }
    station_thread.join();
}
// #endif

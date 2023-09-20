#ifdef __MODULE_28__
/* Задание 1. Заплыв на 100 метров
 *  Что нужно сделать
 *  Реализуйте симуляцию состязаний по заплыву на 100 метров.
 *  Всего шесть дорожек и шесть пловцов. Имена пловцов указываются вначале из стандартного ввода.
 *  Каждый из них плывёт с разной скоростью, которая также задаётся пользователем при старте, через
 *  стандартный ввод в метрах в секунду.
 *  Каждую секунду в стандартный вывод выдаётся информация о том, сколько проплыл тот или иной
 *  пловец.
 *  Как только все пловцы коснулись 100-метровой отметки, заплыв заканчивается и выводится таблица с
 *  итоговыми результатами, отсортированная по возрастанию итогового времени заплыва.
 *  
 *  Советы и рекомендации:
 *  Используйте нити для реализации движения каждого пловца в отдельности. */

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <ctime>
#include "Module_28.hpp"

#define SIZE 6U
#define DIST 100.0

std::mutex cout_mutex;

struct Swimmer {
    std::string name;
    double speed_MS;
    double seconds;
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

static void swim(Swimmer* swimmer) {
    double distance = 0.0;
    std::string dist, sec;

    while (distance < DIST) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        swimmer->seconds += 1.0;
        distance += swimmer->speed_MS;
        dist = std::to_string(distance);
        sec = std::to_string(swimmer->seconds);

        cout_mutex.lock();
        std::cout << (distance < DIST ?
                     "Пловец " + swimmer->name + " на дистанции " + dist.substr(0, dist.find(',')) + " м\n" :
                     "    ПЛОВЕЦ " + swimmer->name + " ПРИПЛЫЛ ЗА " + sec.substr(0, sec.find(',')) + " сек.\n");
        cout_mutex.unlock();
    }
}

static void initialization(Swimmer* swimmers) {
    for (unsigned int i = 0; i < SIZE; i++) {
        std::cout << "Введите имя пловца на дорожке №" << i + 1 << ": ";
        std::cin >> swimmers[i].name;
        swimmers[i].speed_MS = safe_enter("Введите скорость пловца " + swimmers[i].name + " в м/с: ",
                                          "Значение скорости должно быть больше нуля!\n");
        swimmers[i].seconds = 0.0;
    }
}

void Task_28_1() {
    std::cout << equals << string_tasks[0] << equals;

    Swimmer swimmers[SIZE];
    std::thread swim_threads[SIZE];

    initialization(swimmers);
    for (unsigned int i = 0; i < SIZE; i++) {
        swim_threads[i] = std::thread(swim, &swimmers[i]);
    }
    for (unsigned int i = 0; i < SIZE; i++) {
        swim_threads[i].join();
    }
}
#endif

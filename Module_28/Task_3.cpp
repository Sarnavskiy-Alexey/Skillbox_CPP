// #ifdef __MODULE_28__
/* Задание 3. Симуляция работы кухни онлайн-ресторана
 *  Что нужно сделать
 *  Требуется реализовать упрощённую модель работы кухни ресторана, работающего в режиме
 *  онлайн-доставки.
 *  Онлайн-заказ поступает каждые 5–10 секунд. Это случайное блюдо из пяти: пицца, суп, стейк,
 *  салат, суши. Официант, принявший заказ онлайн, оставляет его у кухни. Если кухня свободна, она
 *  принимает заказ и спустя 5–15 секунд возвращает уже готовое блюдо на выдачу. Время определяется
 *  случайным образом с помощью функции std::rand() в указанных диапазонах.
 *  Курьер приезжает каждые 30 секунд, забирает готовые блюда на выдаче и развозит их по заказчикам.
 *  Программа завершается после 10 успешных доставок. На каждом из этапов, будь то заказ, или
 *  готовка, или доставка заказа, выводятся соответствующие сообщения в консоль.
 *  
 *  Советы и рекомендации:
 *  Для симуляции готовки, используйте отдельный мьютекс и запускайте отдельную нить ожидания с
 *  вызовом detach для неё. */

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include "Module_28.hpp"

#define COURIER_TRIPS 2

enum class Food {
    Pizza,
    Soup,
    Steak,
    Salad,
    Sushi,
    size
};

std::vector<Food> waiting_dishes;
std::vector<Food> ready_dishes;
static bool end_of_task = false;
std::mutex waiting_dishes_mutex;
std::mutex ready_dishes_mutex;
std::mutex end_of_task_mutex;

// функция работы доставщика
static void delivery() {
    unsigned int delivery_count = 0;
    while (delivery_count < COURIER_TRIPS) {
        std::this_thread::sleep_for(std::chrono::seconds(30));

        ready_dishes_mutex.lock();
        std::cout << "Курьер забрал " << ready_dishes.size() << " готовых блюд!\n";
        ready_dishes.clear();
        ready_dishes_mutex.unlock();

        delivery_count++;
    }
    end_of_task_mutex.lock();
    end_of_task = true;
    end_of_task_mutex.unlock();
}

// функция добавления заказа клиента
static void client() {
    std::srand(std::time(nullptr));
    while (true) {
        // проверка на окончание выполнения задания
        end_of_task_mutex.lock();
        if (end_of_task) {
            break;
        }
        end_of_task_mutex.unlock();

        // основное тело добавления заказа клиентом
        std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 6 + 5));
        waiting_dishes_mutex.lock();
        waiting_dishes.push_back((Food)(std::rand() % (int)(Food::size)));
        std::cout << "Пришел новый заказ от клиента: "
                  << (int)waiting_dishes[waiting_dishes.size() - 1] << "\n";
        waiting_dishes_mutex.unlock();
    }
}

// функция работы кухни
static void kitchen() {
    std::srand(std::time(nullptr));
    bool busy = false;
    while (true) {
        // проверка на окончание выполнения задания
        end_of_task_mutex.lock();
        if (end_of_task) {
            break;
        }
        end_of_task_mutex.unlock();

        // основное тело выполнения заказа кухней
        waiting_dishes_mutex.lock();
        busy = (waiting_dishes.size() > 0);
        waiting_dishes_mutex.unlock();
        if (!busy) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        } else {
            int time = std::rand() % 11 + 5;
            
            waiting_dishes_mutex.lock();
            Food food = waiting_dishes[0];
            std::cout << "На кухне в течение " << time << " сек. готовится: " << (int)food << "\n";
            waiting_dishes.erase(waiting_dishes.begin());
            waiting_dishes_mutex.unlock();

            std::this_thread::sleep_for(std::chrono::seconds(time));

            ready_dishes_mutex.lock();
            std::cout << "На кухне приготовлено блюдо: " << (int)food << "\n";
            ready_dishes.push_back(food);
            ready_dishes_mutex.unlock();
        }
    }
}

void Task_28_3() {
    std::cout << equals << string_tasks[2] << equals;

    end_of_task = false;
    std::thread kitchen_thread(kitchen);
    std::thread client_thread(client);

    kitchen_thread.detach();
    client_thread.detach();

    delivery();
    ready_dishes_mutex.lock();
    std::cout << "Работа программы завершится через 16 сек!\n";
    ready_dishes_mutex.unlock();
    std::this_thread::sleep_for(std::chrono::seconds(16));
    std::cout << "Работа программы завершена!\n";
}
// #endif

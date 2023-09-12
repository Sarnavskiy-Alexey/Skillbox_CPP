#ifdef __MODULE_27__
/* Определение класса Director */

#include <iostream>
#include "Director.hpp"

void Director::set_teams(unsigned int quantity) {
    std::string name;
    unsigned int amount;
    for (unsigned int i = 0; i < quantity; i++) {
        std::cout << "Введите имя менеджера группы №" << i + 1 << ": ";
        std::cin >> name;
        std::cout << "Введите количество работников в группе №" << i + 1 << ": ";
        std::cin >> amount;

        teams.push_back(Manager(i + 1, name));
        teams[i].set_workers(amount);
    }
}

void Director::set_tasks() {
    int task;

    while (!check_busy()) {
        std::cout << "Введите задачу: ";
        std::cin >> task;

        for (Manager& manager : teams) {
            manager.set_task(task);
        }
    }
}

bool Director::check_busy() const {
    bool busy = true;
    for (const Manager& manager : teams) {
        if (!manager.check_busy()) {
            busy = false;
            break;
        }
    }
    return busy;
}

#endif

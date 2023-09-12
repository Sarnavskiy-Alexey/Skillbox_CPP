#ifdef __MODULE_27__
/* Определение класса Director */

#include <iostream>
#include "Manager.hpp"

void Manager::set_workers(unsigned int amount) {
    workers.resize(amount);
    std::string name;
    for (unsigned int i = 0; i < amount; i++) {
        std::cout << "Введите имя работника #" << i + 1 << ": ";
        std::cin >> name;
        
        workers[i].set_name(name);
    }
}

void Manager::set_task(int task) {
    if (!check_busy()) {
        std::cout << "На команду менеджера " << name << " назначена задача номер " << task << "\n";
        std::srand(task + teamNumber);
        int task_parts = std::rand() % workers.size() + 1;
        std::cout << "Этой команде необходимо выполнить заданий: " << task_parts << "\n";
        for (unsigned int i = 0; i < workers.size() && task_parts != 0; i++) {
            if (!workers[i].get_busy()) {
                workers[i].set_task(task, std::rand() % 3 + 65);
                task_parts--;
            }
        }
    }
}

bool Manager::check_busy() const {
    bool busy = true;
    for (const Worker& worker : workers) {
        if (!worker.get_busy()) {
            busy = false;
            break;
        }
    }

    return busy;
}

#endif

#ifdef __MODULE_24__
/* Задание 1. Реализация программы учёта времени
 *  Что нужно сделать
 *  Используя функцию получения текущего времени std::time, реализуйте простейший менеджер учёта
 *  времени.
 *  Пользователь взаимодействует с программой с помощью команд:
 *  - Команда begin начинает отслеживание новой задачи. После ввода этой команды пользователь должен
 *    ввести название задачи, над которой он планирует сейчас работать. Если уже была начата
 *    какая-то другая задача, предыдущая должна быть автоматически завершена и начата новая.
 *  - Команда end заканчивает отслеживание текущей задачи. Если текущей начатой задачи нет, то
 *    команда ничего не делает.
 *  - Команда status выводит на экран информацию о всех законченных задачах и времени, которое было
 *    на них потрачено. Также выводится название текущей выполняемой задачи, если таковая имеется.
 *  - Команда exit выходит из программы.
 *  
 *  Советы и рекомендации:
 *  Тип std::time_t принимайте за секунды и с помощью него рассчитывайте время в часах, которое было
 *  затрачено. */

#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <vector>
#include "Module_24.hpp"

struct Task {
    std::string name;
    std::time_t start;
    std::time_t finish;
};

// перечисление для удобного сравнения с введенными командами
enum E_Commands {
    e_begin, e_end, e_status, e_exit
};

// массив возможных команд
const std::string commands[] = { "begin", "end", "status", "exit" };

// объявление функции end
static void end(std::vector<Task>& TM);


// функция, обрабатывающая введенную команду begin
static void begin(std::vector<Task>& TM) {
    end(TM);
    Task task;
    task.start = std::time(nullptr);

    // finish задается меньше start
    task.finish = task.start - 1;
    std::cout << "Введите название задачи: ";
    std::cin >> task.name;

    TM.push_back(task);
}

// функция, обрабатывающая введенную команду end
static void end(std::vector<Task>& TM) {
    unsigned int TM_size = TM.size();
    if (TM_size) {
        Task& task = TM[TM_size - 1];
        if (task.start > task.finish) {
            task.finish = std::time(nullptr);
        }
    }
}

// функция, обрабатывающая введенную команду status
static void status(const std::vector<Task>& TM) {
    if (TM.size()) {
        std::cout << "В журнале учета времени находятся следующие записи:\n";
    } else {
        std::cout << "В журнале учета времени нет ни одной записи!\n";
    }

    for (const Task& task : TM) {
        std::cout << "\tЗадача \"" << task.name << "\": ";
        if (task.start <= task.finish) {
            std::cout << "завершена за " << task.finish - task.start << " сек.\n";
        } else {
            std::cout << "не завершена\n";
        }
    }
}

void Task_24_1() {
    std::cout << equals << string_tasks[0] << equals;
    
    std::vector<Task> timeManager;
    std::string command;
    do {
        std::cout << "Введите команду: ";
        std::cin >> command;
        if (command == commands[e_begin]) {
            begin(timeManager);
        } else if (command == commands[e_end]) {
            end(timeManager);
        } else if (command == commands[e_status]) {
            status(timeManager);
        } else if (command == commands[e_exit]) {
            std::cout << "Работа с программой учета времени завершена!\n";
        } else {
            std::cout << "Ошибка ввода команды!\n";
        }
    } while (command != commands[e_exit]);

    std::cout << "\n";
}
#endif

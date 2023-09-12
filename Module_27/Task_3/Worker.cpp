#ifdef __MODULE_27__
/* Определение класса Director */

#include <iostream>
#include "Worker.hpp"

void Worker::set_task(int task, char taskLevel) {
    if (!busy) {
        this->task = task;
        this->taskLevel = taskLevel;
        busy = true;
        std::cout << "Рабочему " << name << " дано задание номер " << task  << "(" 
                  << this->taskLevel << ")" << "\n";
    }
}

#endif

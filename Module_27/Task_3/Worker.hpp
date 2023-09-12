#ifdef __MODULE_27__
/* Объявление класса Worker */
#pragma once

#include <vector>
#include "Common.hpp"

class Worker : public Common {
private:
    bool busy = false;
    int task;
    char taskLevel;
public:
    Worker(std::string name = "") { this->name = name; }

    bool get_busy() const { return busy; }
    void set_task(int task, char taskLevel);
};

#endif

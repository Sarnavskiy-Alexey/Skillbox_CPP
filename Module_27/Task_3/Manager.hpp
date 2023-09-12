#ifdef __MODULE_27__
/* Объявление класса Manager */
#pragma once

#include <vector>
#include "Common.hpp"
#include "Worker.hpp"

class Manager : public Common {
private:
    int teamNumber;
    std::vector<Worker> workers;
public:
    Manager(int tn, std::string name = "") : teamNumber(tn) { this->name = name; }

    void set_workers(unsigned int amount);
    void set_task(int task);
    bool check_busy() const;
};

#endif

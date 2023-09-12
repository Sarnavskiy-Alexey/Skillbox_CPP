#ifdef __MODULE_27__
/* Объявление класса Director */
#pragma once

#include <vector>
#include "Common.hpp"
#include "Manager.hpp"

class Director : public Common {
private:
    std::vector<Manager> teams;
public:
    Director(std::string name = "") { this->name = name; }
    void set_teams(unsigned int quantity);
    void set_tasks();
    bool check_busy() const;
};

#endif

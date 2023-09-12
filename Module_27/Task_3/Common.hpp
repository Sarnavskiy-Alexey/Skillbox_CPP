#ifdef __MODULE_27__
/* Объявление класса Common */
#pragma once

#include <string>

class Common {
protected:
    std::string name;
public:
    void set_name(std::string name) { this->name = name; }
    std::string get_name() const { return name; }
};

#endif

// #ifdef __MODULE_26__
/* Объявление класса Phone */
#pragma once
#include <string>
#include "Phone_Book.hpp"
#include "Phone_Number.hpp"

class Phone {
private:
    Phone_Book m_phoneBook;

    void add(std::string part_command);
    void call(std::string part_command);
    void sms(std::string part_command);
    void help();
    void exit();
    Phone_Number stophn(std::string str);
public:
    Phone();

    // использование: do..while(!cmd(command));
    bool cmd(std::string command);
};

// #endif

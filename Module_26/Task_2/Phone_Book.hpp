// #ifdef __MODULE_26__
/* Объявление класса Phone_Book */
#pragma once
#include <string>
#include <map>
#include <vector>
#include "Phone_Number.hpp"

class Phone_Book {
private:
    std::map<std::string, std::vector<Phone_Number>> m_name_phones;
    std::map<Phone_Number, std::string> m_phone_name;
public:
    Phone_Book();

    bool add(std::string name, Phone_Number phoneNumber);
    std::vector<Phone_Number> find_by_name(std::string name);
    std::string find_by_phone(Phone_Number phoneNumber);
};

// #endif

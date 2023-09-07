#ifdef __MODULE_26__
/* Определение класса Phone_Book */

#include <iostream>
#include "Phone_Book.hpp"

Phone_Book::Phone_Book() {
    this->m_name_phones.clear();
    this->m_phone_name.clear();
}

bool Phone_Book::add(std::string name, Phone_Number phoneNumber) {
    std::map<Phone_Number, std::string>::const_iterator it_PhN =
                                                                this->m_phone_name.find(phoneNumber);
    if (it_PhN == this->m_phone_name.end()) {
        this->m_phone_name[phoneNumber] = name;
        
        std::map<std::string, std::vector<Phone_Number>>::const_iterator it_NPh = this->m_name_phones.find(name);
        if (it_NPh == this->m_name_phones.end()) {
            std::vector<Phone_Number> vec;
            this->m_name_phones[name] = vec;
        }
        this->m_name_phones[name].push_back(phoneNumber);
        return true;
    }
    return false;
}

std::vector<Phone_Number> Phone_Book::find_by_name(std::string name) {
    std::map<std::string, std::vector<Phone_Number>>::const_iterator it =
                                                                      this->m_name_phones.find(name);
    if (it != this->m_name_phones.end()) {
        return this->m_name_phones[name];
    } else {
        return std::vector<Phone_Number>();
    }
}

std::string Phone_Book::find_by_phone(Phone_Number phoneNumber) {
    std::map<Phone_Number, std::string>::const_iterator it = this->m_phone_name.find(phoneNumber);
    if (it != this->m_phone_name.end()) {
        return this->m_phone_name[phoneNumber];
    } else {
        return "";
    }
}

#endif

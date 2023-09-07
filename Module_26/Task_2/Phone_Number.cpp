// #ifdef __MODULE_26__
/* Определение класса Phone_Number */

#include <iostream>
#include "Phone_Number.hpp"

Phone_Number::Phone_Number(unsigned int city, unsigned int number) {
    this->m_city = city;
    this->m_number = number;
}

bool Phone_Number::check(unsigned int city, unsigned int number) const {
    return (city >= 100 && city <= 999 && number >= 1000000 && number <= 9999999);
}

unsigned int Phone_Number::get_city() const {
    return this->m_city;
}

unsigned int Phone_Number::get_number() const {
    return this->m_number;
}
// #endif

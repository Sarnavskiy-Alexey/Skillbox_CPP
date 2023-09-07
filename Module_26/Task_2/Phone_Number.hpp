// #ifdef __MODULE_26__
/* Объявление класса Phone_Number */
#pragma once

class Phone_Number {
private:
    int m_city;
    int m_number;
public:
    Phone_Number(unsigned int city, unsigned int number);
    Phone_Number(const Phone_Number& PhN): m_city(PhN.m_city), m_number(PhN.m_number) {};
    
    unsigned int get_city() const;
    unsigned int get_number() const;
    
    bool check(unsigned int city, unsigned int number) const;

    friend bool operator<(const Phone_Number& a, const Phone_Number& b) {
        return (std::to_string(a.m_city) + std::to_string(a.m_number)) <
               (std::to_string(b.m_city) + std::to_string(b.m_number));
    };
};

// #endif

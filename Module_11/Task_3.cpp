#ifdef __MODULE_11__
/* Задание 3. Валидация IP-адреса
 *  Проверьте, задаёт ли введённая пользователем строка корректный IP-адрес четвёртой версии (IPv4).
 *  IP-адрес должен представлять из себя четыре числа, разделённые точками без пробелов, причём
 *  каждое число должно быть в диапазоне от 0 до 255 включительно. Числа не должны содержать ведущих
 *  нулей. Других символов в строке, кроме вышеописанных, быть не должно.
 *  Пользователь вводит строку, задающую IP-адрес через стандартный ввод. В результате программа
 *  должна вывести слово Valid, если адрес корректен, и слово Invalid, если это не так. */

#include <iostream>
#include <string>
#include <limits>
#include "Module_11.hpp"

static unsigned int countSymbols(std::string str, char symbol) {
    unsigned int counter = 0, found = str.find('.');
    while (found < str.length()) {
        counter++;
        found = str.find('.', found + 1);
    }
    
    return counter;
}

static bool check_ip(std::string ip) {
    if (countSymbols(ip, '.') != 3)
        return false;

    unsigned int index = 0, lastIndex = 0;
    do {
        index = ip.find('.', index + 1);
        std::string ss = ip.substr(lastIndex, index - lastIndex);

        // проверка количества символов в промежутке между точками
        if (ss.length() > 0 && ss.length() <= 3) {
            // проверка на ненулевой первый символ
            if (ss[0] != '0' || (ss.length() == 1 && ss[0] == '0')) {
                // проверка на нахождение в промежутке между точками только цифр
                for (unsigned int i = 0; i < ss.length(); i++)
                    if (ss[i] < '0' || ss[i] > '9')
                        return false;
                
                // проверка на то, что число не больше 255
                int ss_int = std::stoi(ss);
                if (ss_int > 255)
                    return false;
            } else
                return false;
        } else
            return false;

        lastIndex = index + 1;
    } while (index < ip.length());

    return true;
}

void Task_11_3() {
    std::cout << equals << string_tasks[2] << equals;
    
    // очистка буфера ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string str;
    std::cout << "Введите ip для проверки: ";
    std::getline(std::cin, str);

    std::cout << (check_ip(str) ? "Valid" : "Invalid") << "\n";
}
#endif

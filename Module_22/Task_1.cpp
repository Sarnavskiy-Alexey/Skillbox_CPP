#ifdef __MODULE_22__
/* Задание 1. Телефонный справочник
 *  Что нужно сделать
 *  Напишите программу «Телефонный справочник».
 *  На вход программе поступают запросы трёх типов:
 *    69-70-30 Ivanov — добавить телефон и фамилию абонента в справочник
 *    69-70-30 — узнать фамилию абонента по номеру телефона
 *    Ivanov — узнать телефон абонента по фамилии
 *  
 *  Необходимо выводить в консоль ответ на запросы 2 и 3. Обратите внимание, что абоненты по разным
 *  номерам могут иметь одинаковые фамилии. В таком случае на запрос 3 необходимо выдать все номера
 *  через пробелы.
 *  
 *  Операции запросов должны работать за O(logn) или O(logn × количество номеров с этой фамилией). */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Module_22.hpp"
#include <limits>        // std::cin.ignore

enum class Task {
    add,
    find_by_phone,
    find_by_name,
    undefined
};

// структура телефонного справочника с поиском и по номеру, и по фамилии
struct Phonebook {
    std::map<std::string, std::string> phones;             // словарь с ключами - номерами
    std::map<std::string, std::vector<std::string>> names; // словарь с ключами - фамилиями
};

// функция добавления данных в телефонную книгу
static void add(Phonebook& phonebook, const std::string& phone, const std::string& name) {
    phonebook.phones[phone] = name;

    std::map<std::string, std::vector<std::string>>::iterator it;
    it = phonebook.names.find(name);
    if (it != phonebook.names.end()) {
        it->second.push_back(phone);
    } else {
        std::vector<std::string> vec;
        vec.push_back(phone);
        phonebook.names[name] = vec;
    }
}

// функция вывода на экран телефонной книги
static void print_phonebook(const Phonebook& phonebook,
                            const bool phone_or_name    // false - по телефонам, true - по именам
                           ) {
    if (phone_or_name) {
        for (std::map<std::string, std::vector<std::string>>::const_iterator it =
                                                                             phonebook.names.begin();
             it != phonebook.names.end(); it++) {
            std::cout << it->first << ": ";
            for (unsigned int i = 0; i < it->second.size(); i++) {
                std::cout << it->second[i];
                if (i != it->second.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "\n";
        }
    } else {
        for (std::map<std::string, std::string>::const_iterator it = phonebook.phones.begin();
             it != phonebook.phones.end(); it++) {
            std::cout << it->first << ": " << it->second << "\n";
        }
    }
}

// функция поиска по имени
static std::vector<std::string> find_by_name(const Phonebook& phonebook, const std::string& name) {
    std::map<std::string, std::vector<std::string>>::const_iterator it;
    it = phonebook.names.find(name);
    if (it != phonebook.names.end()) {
        return it->second;
    } else {
        return {};
    }
}

// функция поиска по телефону
static std::string find_by_phone(const Phonebook& phonebook, const std::string& phone) {
    std::map<std::string, std::string>::const_iterator it;
    it = phonebook.phones.find(phone);
    if (it != phonebook.phones.end()) {
        return it->second;
    } else {
        return "";
    }
}

// функция подсчета определенных символов
static unsigned int count_symbols(const std::string& str, const char symbol) {
    unsigned int counter = 0, found = str.find(symbol);
    while (found < str.length()) {
        counter++;
        found = str.find(symbol, found + 1);
    }
    
    return counter;
}

// функция проверки строки, является ли она числом
bool is_number(const std::string& num) {
    std::string::const_iterator it = num.begin();
    while (it != num.end() && std::isdigit(*it))
        it++;
    return !num.empty() && it == num.end();
}

// функция анализа телефонного номера
static bool phone_analysis(const std::string& phone) {
    return (count_symbols(phone, '-') == 2 &&
            is_number(phone.substr(0, phone.find('-'))) &&
            is_number(phone.substr(phone.find('-') + 1, phone.find('-', phone.find('-') + 1) - phone.find('-') - 1)) &&
            is_number(phone.substr(phone.find('-', phone.find('-') + 1) + 1)));
}

// функция анализа введенных данных
static Task analysis(const std::string& data) {
    if (count_symbols(data, ' ') == 1) {
        if (phone_analysis(data.substr(0, data.find(' ')))) {
            return Task::add;
        } else {
            return Task::undefined;
        }
    } else if (count_symbols(data, ' ') == 0) {
        if (phone_analysis(data)) {
            return Task::find_by_phone;
        } else {
            return Task::find_by_name;
        }
    } else {
        return Task::undefined;
    }
}

void Task_22_1() {
    std::cout << equals << string_tasks[0] << equals;

    Phonebook phonebook;
    std::string userAnswer, data, resultStr;
    std::vector<std::string> resultVec;
    do {    
        // очистка буфера ввода
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // получение данных от пользователя
        std::cout << "Введите ваш запрос: ";
        std::getline(std::cin, data);
        Task task = analysis(data);

        switch (task) {
            case Task::add: {
                add(phonebook, data.substr(0, data.find(' ')), data.substr(data.find(' ') + 1));
                break;
            }
            case Task::find_by_phone: {
                resultStr = find_by_phone(phonebook, data);
                if (resultStr != "") {
                    std::cout << "По вашему запросу найден владелец номера: " << resultStr << "\n";
                } else {
                    std::cout << "По вашему запросу не ничего не найдено!\n";
                }
                break;
            }
            case Task::find_by_name: {
                resultVec = find_by_name(phonebook, data);
                if (resultVec.size() != 0U) {
                    std::cout << "По вашему запросу найдены следующие номера: ";
                    for (unsigned int i = 0; i < resultVec.size(); i++) {
                        std::cout << resultVec[i];
                        if (i != resultVec.size() - 1) {
                            std::cout << ", ";
                        }
                    }
                    std::cout << "\n";
                } else {
                    std::cout << "По вашему запросу не ничего не найдено!\n";
                }
                break;
            }
            case Task::undefined: {
                std::cout << "Операция не распознана!\n";
                break;
            }
        }

        std::cout << "На данный момент в телефонной книге содержатся следующие данные:\n";
        std::cout << "По фамилиям:\n";
        print_phonebook(phonebook, true);
        std::cout << "\nПо номерам:\n";
        print_phonebook(phonebook, false);

        std::cout << "Хотите продолжить ввод данных? (Y/N)";
        std::cin >> userAnswer;
    } while (userAnswer == "Y" || userAnswer == "y");
}
#endif

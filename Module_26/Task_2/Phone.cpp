// #ifdef __MODULE_26__
#include <iostream>
#include <sstream>
#include "Phone.hpp"

Phone::Phone() {
    std::cout << "Телефон включен!\n";
}

Phone_Number Phone::stophn(std::string str) {
    bool str_is_number = true;
    for (const char& c : str) {
        if (c < '0' || c > '9') {
            str_is_number = false;
            break;
        }
    }
    if (str_is_number) {
        Phone_Number result(std::stoul(str.substr(0, 3)), std::stoul(str.substr(3)));
        return result;
    } else {
        Phone_Number result(0, 0);
        return result;
    }
}

void Phone::add(std::string part_command) {
    std::string name, number, err;
    std::stringstream buffer(part_command);
    buffer >> name >> number >> err;
    if (!name.length() || number.length() != 10 || err.length()) {
        std::cout << "Команда не распознана!\n";
    } else {
        Phone_Number phoneNumber = this->stophn(number);
        if (this->m_phoneBook.add(name, phoneNumber)) {
            std::cout << "Контакт успешно добавлен!\n";
        } else {
            std::cout << "Такой контакт уже существует!\n";
        }
    }
}

void Phone::call(std::string part_command) {
    std::string who, err;
    std::stringstream buffer(part_command);
    buffer >> who >> err;
    if (!who.length() || err.length()) {
        std::cout << "Команда не распознана!\n";
    } else {
        Phone_Number phoneNumber = this->stophn(who);
        std::string name = this->m_phoneBook.find_by_phone(phoneNumber);
        if (name.length()) {
            std::cout << "Вызван контакт из телефонной книги: \"" << name;
            std::cout << "\" по номеру: +7" << phoneNumber.get_city() << phoneNumber.get_number();
            std::cout << "\n";
        } else if (phoneNumber.get_city() != 0 && phoneNumber.get_number() != 0) {
            std::cout << "Вызван контакт не из телефонной книги: +7" << who << "\n";
        } else {
            std::vector<Phone_Number> vec = this->m_phoneBook.find_by_name(who);
            if (vec.size()) {
                std::cout << "Вызван контакт из телефонной книги: \"" << who;
                std::cout << "\" по первому номеру: +7" << vec[0].get_city() << vec[0].get_number();
                std::cout << "\n";
            } else {
                std::cout << "Номер набран неправильно!\n";
            }
        }
    }
}

void Phone::sms(std::string part_command) {
    std::string who, message = "";
    std::stringstream buffer(part_command);
    buffer >> who;
    if (part_command.length() > who.length() + 1) {
        message = buffer.str().substr(who.length() + 1);
    }
    if (!who.length() || !message.length()) {
        std::cout << "Команда не распознана!\n";
    } else {
        Phone_Number phoneNumber = this->stophn(who);
        std::string name = this->m_phoneBook.find_by_phone(phoneNumber);
        if (name.length()) {
            std::cout << "Сообщение отправлено контакту из телефонной книги: \"" << name;
            std::cout << "\" по номеру: +7" << phoneNumber.get_city() << phoneNumber.get_number();
            std::cout << "\n";
            std::cout << "Текст сообщения: " << message << "\n";
        } else if (phoneNumber.get_city() != 0 && phoneNumber.get_number() != 0) {
            std::cout << "Сообщение отправлено контакту не из телефонной книги: +7" << who << "\n";
            std::cout << "Текст сообщения: " << message << "\n";
        } else {
            std::vector<Phone_Number> vec = this->m_phoneBook.find_by_name(who);
            if (vec.size()) {
                std::cout << "Сообщение отправлено контакту из телефонной книги: \"" << who;
                std::cout << "\" по первому номеру: +7" << vec[0].get_city() << vec[0].get_number();
                std::cout << "\n";
                std::cout << "Текст сообщения: " << message << "\n";
            } else {
                std::cout << "Номер указан неправильно!\n";
            }
        }
    }
}

void Phone::help() {
    std::cout << "  add <имя> <номер>         - добавление в телефонную книгу пользователя, номер телефона вводится без +7 (только 10 цифр)\n";
    std::cout << "  call <имя>/<номер>        - звонок по имени или номеру телефона\n";
    std::cout << "  sms <имя>/<номер> <текст> - СМС по имени или номеру телефону\n";
    std::cout << "  help                      - вывод данного сообщения\n";
    std::cout << "  exit                      - выход\n";
} 

void Phone::exit() {
    std::cout << "Работа с телефоном завершена!\n";
} 

// использование: do..while(!cmd(command));
bool Phone::cmd(std::string command) {
    std::string operation;
    std::stringstream buffer(command);

    buffer >> operation;
    if (operation == "add" && (command.length() > operation.length() + 1)) {
        this->add(buffer.str().substr(operation.length() + 1));
    } else if (operation == "call" && (command.length() > operation.length() + 1)) {
        this->call(buffer.str().substr(operation.length() + 1));
    } else if (operation == "sms" && (command.length() > operation.length() + 1)) {
        this->sms(buffer.str().substr(operation.length() + 1));
    } else if (operation == "help") {
        this->help();
    } else if (operation == "exit") {
        this->exit();
        return true;
    } else {
        std::cout << "Команда не распознана! Введите \"help\" для помощи.\n";
    }

    return false;
}
// #endif

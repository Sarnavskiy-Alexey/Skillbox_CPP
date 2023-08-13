#ifdef __MODULE_20__
/* Задание 1. Реализация записи в ведомость учёта
 *  Что нужно сделать
 *  В одном из прошлых заданий мы уже создавали программу чтения и анализа ведомости выплат. Теперь
 *  требуется создать простую программу записи в эту ведомость.
 *  Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных средств, далее
 *  располагается дата выдачи в формате ДД.ММ.ГГГГ. Завершает запись сумма выплаты в рублях. Данные
 *  разделяются между собой пробелами. В конце каждой записи должен быть расположен перевод строки.
 *  При старте программы пользователь последовательно вводит данные для новой записи, которые
 *  записываются затем в файл в текстовом режиме. Программа должна добавлять новые записи в конец
 *  файла, не удаляя его текущее содержимое.
 *  
 *  Советы и рекомендации:
 *  - Введённые данные рекомендуется хотя бы минимально валидировать перед их записью. 
 *  - Для валидации даты в указанном формате можно использовать функции std::stoi и std::substr с
 *    корректно указанным диапазоном символов в дате. К примеру, вызов std::stoi(date.substr(3, 2))
 *    вычленит из строковой даты целочисленный месяц для последующего анализа. */

#include <iostream>
#include <fstream>
#include <string>
#include "Module_20.hpp"

// функция подсчета определенных символов
static unsigned int count_symbols(std::string str, char symbol) {
    unsigned int counter = 0, found = str.find('.');
    while (found < str.length()) {
        counter++;
        found = str.find('.', found + 1);
    }
    
    return counter;
}

// функция проверки даты по дню, месяцу и году
static bool check_date(unsigned int day, unsigned int month, int year) {
    bool leapYear = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    switch (month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return day >= 1 && day <= 31;
        case 4: case 6: case 9: case 11:
            return day >= 1 && day <= 30;
        case 2:
            return day >= 1 && day <= (leapYear ? 29 : 28);
        default: return false;
    }
}

// функция получения имени или фамилии получателя
static std::string get_name(std::string mes_name) {
    std::string result;
    std::cout << "Введите " << mes_name << " получателя: ";
    std::cin >> result;
    return result;
}

// функция получения даты выдачи
static std::string get_date() {
    std::string result;
    bool right;
    do {
        right = true;
        std::cout << "Введите дату выдачи: ";
        std::cin >> result;
        if (count_symbols(result, '.') == 2) {
            unsigned int day = std::stoi(result.substr(0, 2));
            unsigned int month = std::stoi(result.substr(3, 2));
            int year = std::stoi(result.substr(6));
            if (!check_date(day, month, year)) {
                right = false;
                std::cout << "Введена некорректная дата!\n";
            }
        } else {
            right = false;
            std::cout << "Вы ввели не дату!\n";
        }
    } while (!right);
    return result;
}

// функция получения даты выдачи
static unsigned int get_money() {
    unsigned int result;
    do {
        std::cout << "Введите сумму выплаты в рублях: ";
        std::cin >> result;
    } while (false);
    return result;
}

void Task_20_1() {
    std::cout << equals << string_tasks[0] << equals;

    std::ofstream file;
    file.open(CUR_DIR + DOCS_DIR + "sheet.txt");

    if (file.is_open()) {
        std::string answer, fn, ln, date;
        unsigned int money;
        do {
            fn = get_name("имя");
            ln = get_name("фамилию");
            date = get_date();
            money = get_money();

            file << fn << " " << ln << " " << date << " " << money << "\n";

            std::cout << "Хотите продолжить ввод данных? (Y/N)";
            std::cin >> answer;
        } while (answer == "Y" || answer == "y");
        
        file.close();
    } else {
        std::cout << "File is not open!\n";
    }
}
#endif

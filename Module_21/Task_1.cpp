#ifdef __MODULE_21__
/* Задание 1. Ведомость учёта
 *  Что нужно сделать
 *  Вы уже создавали программу чтения и записи ведомости. Теперь её нужно обобщить и дополнить
 *  использованием структур.
 *  Формат ведомости прежний: 
 *  - сначала — имя и фамилия получателя денег,
 *  - далее — дата выдачи в формате ДД.ММ.ГГГГ,
 *  - затем — сумма выплаты в рублях.
 *  Данные разделяются пробелами. В конце каждой записи должен быть перевод строки. Структура данных
 *  должна соответствовать этому формату.
 *  При старте программы пользователь отправляет команду: list или add. Команда list осуществляет
 *  чтение из файла ведомости, как и прежде, только уже в структуры данных, и отображает их на
 *  экране.
 *  Команда add добавляет новую запись в конец ведомости.
 *  
 *  Советы и рекомендации:
 *  - Чтобы определить, где заканчивается файл, используйте функцию file.eof(). 
 *  - Из-за завершающего переноса строки при чтении данных из файла стоит отдельно прочитать имя
 *    получателя денег. Если после чтения имени получателя денег признак file.eof() принял значение
 *    true, значит, файл закончился.
 *  - Используйте вектор структур. Для выбора команды потребуется подобная конструкция:
 *      if (command == "list")
 *      {
 *      ...
 *      } */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Module_21.hpp"

// структура одной записи в ведомости
struct sheet_record {
    std::string firstName; // имя получателя
    std::string lastName;  // фамилия получателя
    std::string date;      // дата выплаты
    unsigned int sumRub;   // сумма выплаты в рублях
};

// функция заполнения вектора данными ведомости
static void fill_sheet_vector(std::ifstream& sheet, std::vector<sheet_record>& records) {
    while (!sheet.eof()) {
        sheet_record tmp;
        sheet >> tmp.firstName;
        if (sheet.eof())
            break;
        sheet >> tmp.lastName >> tmp.date >> tmp.sumRub;
        records.push_back(tmp);
    }
    sheet.close();
}

// функция вывода на экран вектора данных ведомости
static void print_vector(std::vector<sheet_record>& records) {
    std::cout.width(15);
    std::cout << "First name" << " | ";
    std::cout.width(15);
    std::cout << "Last name" << " | ";
    std::cout.width(10);
    std::cout << "Date" << " | "
              << "Sum" << "\n";
    for (unsigned int i = 0; i < records.size(); i++) {
        std::cout.width(15);
        std::cout << records[i].firstName << " | ";
        std::cout.width(15);
        std::cout << records[i].lastName << " | ";
        std::cout.width(10);
        std::cout << records[i].date << " | ";
        std::cout << records[i].sumRub << "\n";
    }
}

// функция чтения данных из файла ведомости
static void list() {
    std::vector<sheet_record> records;
    std::ifstream sheet;

    sheet.open(CUR_DIR + DOCS_DIR + "sheet.txt");
    if (sheet.is_open()) {
        fill_sheet_vector(sheet, records);
        print_vector(records);
    } else {
        std::cout << "File is not open!\n";
    }
}

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

// функция добавления одной записи в вектор
static void add_record(std::vector<sheet_record>& records) {
    sheet_record tmp;
    tmp.firstName = get_name("имя");
    tmp.lastName = get_name("фамилию");
    tmp.date = get_date();
    tmp.sumRub = get_money();
    records.push_back(tmp);
}

// функция выдачи данных в файл
static void add_records_in_sheet(std::ofstream& sheet, std::vector<sheet_record>& records) {
    for (unsigned int i = 0; i < records.size(); i++) {
        sheet << records[i].firstName << " "
              << records[i].lastName << " "
              << records[i].date << " "
              << records[i].sumRub << "\n";
    }
}

// функция добавления данных в файл ведомости
static void add() {
    std::vector<sheet_record> records;
    std::ofstream sheet;

    std::string answer;
    do {
        add_record(records);
        std::cout << "Хотите продолжить ввод данных? (Y/N)";
        std::cin >> answer;
    } while (answer == "Y" || answer == "y");
    
    sheet.open(CUR_DIR + DOCS_DIR + "sheet.txt");
    if (sheet.is_open()) {
        add_records_in_sheet(sheet, records);
    } else {
        std::cout << "File is not open!\n";
    }
}

void Task_21_1() {
    std::cout << equals << string_tasks[0] << equals;

    std::string command;
    std::cout << "Введите команду (list или add): ";
    std::cin >> command;;
    if (command == "list") {
        list();
    } else if (command == "add") {
        add();
    } else {
        std::cout << "Команда не распознана!\n";
    }
}
#endif

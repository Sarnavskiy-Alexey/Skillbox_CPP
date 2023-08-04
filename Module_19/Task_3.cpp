#ifdef __MODULE_19__
/* Задание 3. Реализация программы чтения ведомости
 *  Что нужно сделать
 *  Реализуйте программу чтения информации из ведомости по учёту выплат. Сама ведомость представляет
 *  собой следующую таблицу:
 *  - имя и фамилия человека;
 *  - количество денег, которые были выплачены лицу;
 *  - дата выплаты в формате ДД.ММ.ГГГГ.
 *  
 *  На основе данных из ведомости следует подсчитать общее количество выплаченных средств и
 *  определить человека с максимальной суммой выплат.
 *  Пример данных ведомости
 *    Tom Hanks 35500 10.11.2020
 *    Rebecca Williams 85000 1.1.2021
 *    Sally Field 15600 15.8.2021
 *    Michael Humphreys 29400 23.5.2020
 *    Harold Herthum 74300 9.6.2019
 *    George Kelly 45000 12.3.2018
 *    Bob Penny 12500 13.5.2020
 *    John Randall 23400 2.10.2020
 *    Sam Anderson 6500 15.7.2020
 *    Margo Moorer 12350 24.2.2019 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Module_19.hpp"

static void read_sheet() {
    std::string first_name_max, last_name_max;
    int max_money = 0;
    std::string first_name, last_name, date;
    int money;
    std::ifstream file;

    file.open(CUR_DIR + DOCS_DIR + "sheet.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            file >> first_name >> last_name >> money >> date;
            if (money > max_money) {
                first_name_max = first_name;
                last_name_max = last_name;
                max_money = money;
            }
        }
        file.close();

        if (first_name.length() > 0) {
            std::cout << "Максимальная сумма выплат " << max_money << " у "
                      << first_name_max << " " << last_name_max << "\n";
        }
    } else
        std::cout << "File is not open!\n";
}

void Task_19_3() {
    std::cout << equals << string_tasks[2] << equals;

    read_sheet();
}
#endif

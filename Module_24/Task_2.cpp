#ifdef __MODULE_24__
/* Задание 2. Реализация программы напоминания о днях рождения
 *  Что нужно сделать
 *  Реализуйте простую программу по вычислению ближайшего дня рождения.
 *  В начале программы пользователь последовательно вводит данные о днях рождения своих друзей:
 *  вводит имя друга и саму дату рождения полностью, включая месяц и год, в формате год/месяц/день.
 *  Сигналом окончания ввода дней рождения является “end” введённое в качестве имени.
 *  После этого программа вычисляет ближайший день рождения по отношению к текущему времени и
 *  выводит его на экран вместе с именем в удобном, локальном формате - месяц/день. Если день
 *  рождения уже был в этом году, данные о пользователе пропускаются. Если у кого-то из друзей день
 *  рождения сегодня, то в консоль выводится специальное сообщение об этом. Учтите, что таких
 *  сообщений может быть несколько, ведь сразу несколько людей могут иметь дни рождения в один день.
 *  
 *  Советы и рекомендации:
 *  Для подсчёта ближайшего дня используйте данные из структуры даты std::tm. */

#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include "Module_24.hpp"

// структура друга
struct Friend {
    std::string name; // имя друга
    std::tm birthday; // день рождения друга
};

// функция для ввода данных пользователем
static void enter_friends(std::vector<Friend>& bd) {
    std::string command;
    std::time_t today = std::time(nullptr);
    do {
        std::cout << "Введите имя друга (или end для окончания): ";
        std::cin >> command;
        if (command != "end") {
            Friend f;
            f.name = command;
            std::cout << "Введите дату рождения друга: ";
            f.birthday = *std::localtime(&today);
            std::cin >> std::get_time(&f.birthday, "%Y/%m/%d");

            bd.push_back(f);
        }
    } while (command != "end");
}

// функция сортировки друзей по дням рождения
static void sort_birthdays(std::vector<Friend>& bd) {
    if (!bd.size())
        return;
    for (unsigned int i = 0; i < bd.size() - 1; i++) {
        for (unsigned int j = i + 1; j < bd.size(); j++) {
            if (bd[i].birthday.tm_mon > bd[j].birthday.tm_mon ||
                                      (bd[i].birthday.tm_mon == bd[j].birthday.tm_mon &&
                                      bd[i].birthday.tm_mday > bd[j].birthday.tm_mday)) {
                Friend f = bd[i];
                bd[i] = bd[j];
                bd[j] = f;
            }
        }
    }
}

// функция проверки дней рождения друзей
static void check_friends(const std::vector<Friend>& bd) {
    if (!bd.size())
        return;
    std::time_t today = std::time(nullptr);
    std::tm* local = std::localtime(&today);

    for (unsigned int i = 0; i < bd.size(); i++) {
        if (local->tm_mon == bd[i].birthday.tm_mon && local->tm_mday == bd[i].birthday.tm_mday) {
            std::cout << "С днем рождения, " << bd[i].name << "\n";
        } else if (local->tm_mon <= bd[i].birthday.tm_mon && local->tm_mday <= bd[i].birthday.tm_mday) {
            std::cout << "У " << bd[i].name << " ДР в этом году попозже: "
                      << std::put_time(&bd[i].birthday, "%m/%d") << "\n";
            
            // если у следующего друга др не в тот же день, что у текущего, то конец вывода друзей
            if (!((i + 1 < bd.size()) && bd[i].birthday.tm_mon == bd[i + 1].birthday.tm_mon &&
                                         bd[i].birthday.tm_mday == bd[i + 1].birthday.tm_mday)) {
                break;
            }
        }
    }
}

void Task_24_2() {
    std::cout << equals << string_tasks[1] << equals;

    std::vector<Friend> birthdays;
    enter_friends(birthdays);
    sort_birthdays(birthdays);
    check_friends(birthdays);
}
#endif

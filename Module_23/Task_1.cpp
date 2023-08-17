#ifdef __MODULE_23__
/* Задание 1. Реализация продвинутого ввода и вывода дней недели
 *  Что нужно сделать
 *  Используя макросы, реализуйте небольшую программу по вводу дня недели и выводу этого дня недели
 *  в текстовом виде в консоль.
 *  В начале программы пользователь вводит день недели в виде его порядкового номера. В результате в
 *  консоли появляется буквенное отображение этого дня недели.
 *  В этом упражнении запрещается использовать классические переменные, кроме как для хранения ввода
 *  пользователя. Использовать строковые литералы напрямую тоже нельзя. Всё должно быть реализовано
 *  исключительно на макросах.
 *  
 *  Советы и рекомендации:
 *  - Конкатенация двух фрагментов может породить токен, который в свою очередь является именем
 *    макроса, и этот макрос тоже раскроется. Используйте это свойство для перевода константы дня
 *    недели в строковый литерал.
 *  - Обязательно просмотрите итоговый код после препроцессинга из CLion с помощью Shift-Shift →
 *    Preprocess current TU. */

#include <iostream>
#include "Module_23.hpp"

#define DAY_1 1
#define DAY_2 2
#define DAY_3 3
#define DAY_4 4
#define DAY_5 5
#define DAY_6 6
#define DAY_7 7
#define MONDAY "MONDAY"
#define TUESDAY "TUESDAY"
#define WEDNESDAY "WEDNESDAY"
#define THURSDAY "THURSDAY"
#define FRIDAY "FRIDAY"
#define SATURDAY "SATURDAY"
#define SUNDAY "SUNDAY"

#define WHATS(day) day ## DAY
#define WHATS_THE_DAY_OF_WEEK(day) (day == DAY_1 ? WHATS(MON) : \
                                    day == DAY_2 ? WHATS(TUES) : \
                                    day == DAY_3 ? WHATS(WEDNES) : \
                                    day == DAY_4 ? WHATS(THURS) : \
                                    day == DAY_5 ? WHATS(FRI) : \
                                    day == DAY_6 ? WHATS(SATUR) : \
                                    day == DAY_7 ? WHATS(SUN) : "NO DAY OF WEEK")

void Task_23_1() {
    std::cout << equals << string_tasks[0] << equals;

    int day;
    std::cout << "Введите день недели: ";
    std::cin >> day;
    std::cout << WHATS_THE_DAY_OF_WEEK(day) << "\n";
}
#endif

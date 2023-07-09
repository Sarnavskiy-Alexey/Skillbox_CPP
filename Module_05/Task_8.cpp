#ifdef __MODULE_05__
/* Задание 8. Грустное совершеннолетие
 *  Посетитель пришёл в бар и попросил кружку пива. Напишите программу для бармена, который не
 *  умеет считать, чтобы по заданной дате рождения посетителя и текущей дате определить, можно ему
 *  продавать алкоголь или нет. Программа должна попросить ввести сегодняшнюю дату и дату рождения
 *  покупателя, после чего ответить: «можно» или «нельзя».
 *  Учтите, что в день 18-летия алкоголь продавать посетителю ещё нельзя, а вот на следующий день
 *  после этого — уже можно.
 *  Как обычно, постарайтесь сделать свою программу по возможности лаконичнее. */

#include <iostream>
#include "Module_05.hpp"

void Task_05_8() {
    std::cout << equals << string_tasks[7] << equals;

    int todayDay, todayMonth, todayYear;
    int clientDay, clientMonth, clientYear;
    int years, months, days;

    std::cout << "Введите сегодняшний день в формате: \"DD MM YYYY\" ";
    std::cin >> todayDay >> todayMonth >> todayYear;
    std::cout << "Введите день рождения клиента в формате: \"DD MM YYYY\" ";
    std::cin >> clientDay >> clientMonth >> clientYear;

    std::cout << "\n------------Проверка на совершеннолетие------------\n\n";

    years = todayYear - clientYear;
    if (todayMonth < clientMonth) {
        years--;
        months = (todayMonth + 12) - clientMonth;
    } else
        months = todayMonth - clientMonth;
    
    if (todayDay < clientDay) {
        months--;
        days = todayDay - clientDay + 31;
        if (months < 0) {
            years--;
            months += 12;
        }
    } else
        days = todayDay - clientDay;

    if (years > 18 || (years == 18 && (months > 0 || days > 0)))
        std::cout << "Клиент - совершеннолетний! Продажа алкоголя разрешена!\n";
    else
        std::cout << "Клиент - несовершеннолетний! Продажа алкоголя запрещена!\n";
}
#endif

#ifdef __MODULE_04__
/* Задание 7. Меню ресторана
 *  Напишите программу, которая выводит меню бизнес-ланча ресторана в зависимости от дня недели.
 *  В меню есть общая часть, а есть уникальная, которая зависит от дня недели. Пользователь должен
 *  ввести номер дня недели — от 1 (понедельник) до 7 (воскресенье), а программа должна вывести на
 *  экран день недели и меню этого дня. */

#include <iostream>
#include "Module_04.hpp"

void Task_04_7() {
    std::cout << equals << string_tasks[6] << equals;
    
    const std::string menuString = "Меня сегодня (";
    const std::string soupString = ")\n\tСуп: ";
    const std::string secondString = "\n\tВторое: ";
    const std::string saladString = "\n\tСалат: ";
    const std::string drinkString = "\n\tНапиток: ";

    int dayOfWeek;
    std::cout << "Введите номер дня недели (1-7): ";
    std::cin >> dayOfWeek;

    if (dayOfWeek == 1)
        std::cout << menuString << "понедельник"
                  << soupString << "куриный с лапшой"
                  << secondString << "котлета домашняя с макаронами-ракушками"
                  << saladString << "фантазия"
                  << drinkString << "компот сливовый" << "\n";
    else if (dayOfWeek == 2)
        std::cout << menuString << "вторник"
                  << soupString << "борщ"
                  << secondString << "котлета по-киевски с гречкой"
                  << saladString << "овощной с огурцами и помидорами"
                  << drinkString << "компот кизиловый" << "\n";
    else if (dayOfWeek == 3)
        std::cout << menuString << "среда"
                  << soupString << "рыбный"
                  << secondString << "рагу"
                  << saladString << "цезарь"
                  << drinkString << "компот яблочный" << "\n";
    else if (dayOfWeek == 4)
        std::cout << menuString << "четверг"
                  << soupString << "фасолевый"
                  << secondString << "жареные колбаски по-баварски с рисом"
                  << saladString << "баклажаны с чесноком"
                  << drinkString << "компот вишневый" << "\n";
    else if (dayOfWeek == 5)
        std::cout << menuString << "пятница"
                  << soupString << "щи"
                  << secondString << "шашлычок из свинины с булгуром"
                  << saladString << "оливье"
                  << drinkString << "компот абрикосовый" << "\n";
    else if (dayOfWeek == 6 || dayOfWeek == 7)
        std::cout << "Бизнес-ланч подается только по будням с 11 до 15 часов!";
    else
        std::cout << "Ошибка! Введенный день недели отсутствует!\n";
}
#endif

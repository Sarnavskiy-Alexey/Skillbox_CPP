#ifdef __MODULE_06__
/* Задание 1. Кукушка
 *  Напишите программу, которая имитировала бы часы с кукушкой. В начале работы она спрашивает,
 *  который час, а затем нужное количество раз пишет «Ку-ку!». При выполнении задания необходимо
 *  обеспечить контроль ввода (например, количество часов не может быть отрицательным). */

#include <iostream>
#include "Module_06.hpp"

void Task_06_1() {
    std::cout << equals << string_tasks[0] << equals;

    int countKuKu;
    std::cout << "Который час? ";
    std::cin >> countKuKu;

    if (countKuKu >= 1 && countKuKu <= 12) {
        int counter = 0;
        while (counter < countKuKu) {
            std::cout << "Ку-ку\n";
            ++counter;
        }
    }
    else
        std::cout << "Ввод часа некорректен!\n";
}
#endif

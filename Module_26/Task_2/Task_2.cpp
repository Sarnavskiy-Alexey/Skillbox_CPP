// #ifdef __MODULE_26__
/* Задание 2. Реализация программы симуляции мобильного телефона
 *  Что нужно сделать
 *  Реализуйте программу простой симуляции работы мобильного телефона.
 *  По мобильному телефону можно звонить и отправлять СМС. Также мобильный телефон содержит адресную
 *  книгу. Телефон и отдельные записи адресной книги должны быть реализованы с помощью классов. Все
 *  номера телефонов задаются в формате +7 <10 цифр>.
 *  Пользователь взаимодействует с программой с помощью команд:
 *  - Команда add добавляет в адресную книгу новый номер телефона и ассоциирует его с именем
 *    контакта. Оба эти параметра команда получает от пользователя через стандартный ввод.
 *  - Команда call запрашивает у пользователя имя контакта или номер телефона, на который требуется
 *    позвонить. Сам по себе звонок симулируется с помощью вывода в консоль сообщения CALL с номером
 *    телефона, на который осуществляется вызов.
 *  - Команда sms. Запрашивает у пользователя номер телефона (или имя контакта), на который
 *    требуется послать сообщение. Само сообщение также вводится через стандартный ввод.
 *  - Команда exit — выход из программы.
 *  
 *  Советы и рекомендации
 *  Сам по себе тип номера телефона вы тоже можете реализовать с помощью отдельного класса. */

#include <iostream>
#include <limits>
#include <string>
#include "../Module_26.hpp"
#include "Phone.hpp"

void Task_26_2() {
    std::cout << equals << string_tasks[1] << equals;

    // очистка буфера ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Phone phone;
    std::string command;
    do {
        std::cout << "Введите команду: ";
        std::getline(std::cin, command);
    } while(!phone.cmd(command));
}
// #endif

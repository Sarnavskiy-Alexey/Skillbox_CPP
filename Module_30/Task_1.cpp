#ifdef __MODULE_30__
/* Задание 1. Пользовательские запросы
 *  Что нужно сделать:
 *  Реализуйте программу по осуществлению различных типов HTTP-запросов к сервису httpbin.org.
 *  Пользователь взаимодействует с программой с помощью команд: “get”, “post”, “put”, “delete”,
 *  “patch”. В зависимости от команды к серверу httpbin.org осуществляется запрос того или иного
 *  типа. Содержимое ответа сервера выводится в стандартный вывод.
 *  Программа завершается, когда пользователь вводит команду “exit”.
 *  
 *  Рекомендации:
 *  Для каждого HTTP-запроса в CPR есть отдельный метод, например cpr::Get. */

#include <iostream>
#include <string>
#include <cpr/cpr.h>
#include "Module_30.hpp"

#define URL_HTTP_GET "http://httpbin.org/get"
#define URL_HTTP_POST "http://httpbin.org/post"
#define URL_HTTP_PUT "http://httpbin.org/put"
#define URL_HTTP_DELETE "http://httpbin.org/delete"
#define URL_HTTP_PATCH "http://httpbin.org/patch"

void Task_30_1() {
    std::cout << equals << string_tasks[0] << equals;
    
    std::string command;
    cpr::Response response;
    
    do {
        std::cout << "Введите команду: ";
        std::cin >> command;
        if (command == "exit") {
            std::cout << "Работа программы окончена!\n";
            break;
        } else if (command == "get") {
            response = cpr::Get(cpr::Url(URL_HTTP_GET));
            std::cout << response.text << "\n";
            std::cout << "Код ошибки: " << (int)response.error.code << " - всё хорошо!\n";
        } else if (command == "post") {
            response = cpr::Post(cpr::Url(URL_HTTP_POST));
            std::cout << response.text << "\n";
            std::cout << "Код ошибки: " << (int)response.error.code << " - всё хорошо!\n";
        } else if (command == "put") {
            response = cpr::Put(cpr::Url(URL_HTTP_PUT));
            std::cout << response.text << "\n";
            std::cout << "Код ошибки: " << (int)response.error.code << " - всё хорошо!\n";
        } else if (command == "delete") {
            response = cpr::Delete(cpr::Url(URL_HTTP_DELETE));
            std::cout << response.text << "\n";
            std::cout << "Код ошибки: " << (int)response.error.code << " - всё хорошо!\n";
        } else if (command == "patch") {
            response = cpr::Patch(cpr::Url(URL_HTTP_PATCH));
            std::cout << response.text << "\n";
            std::cout << "Код ошибки: " << (int)response.error.code << " - всё хорошо!\n";
        } else {
            std::cout << "Команда введена неверно!\n";
        }
    } while (true);
}
#endif

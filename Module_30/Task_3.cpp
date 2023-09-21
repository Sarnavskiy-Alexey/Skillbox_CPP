#ifdef __MODULE_30__
/* Задание 3. Запросы с аргументами
 *  Что нужно сделать:
 *  Сделайте запрос к сервису httpbin.org, отправив при этом несколько дополнительных аргументов с
 *  данными.
 *  Все названия аргументов и их значения строковые и принимаются от пользователя. Пользователь
 *  последовательно вводит их названия вместе со значениями, пока не встретится аргумент с названием
 *  “post” или “get”, что будет означать, что ввод аргументов закончен и требуется отправить их на
 *  сервер выбранным способом.
 *  Если пользователь выбрал “post”, то выполняется POST-запрос и аргументы отправляются
 *  POST-способом (как форма). Если “get”, то выполняется GET-запрос с GET-аргументами (прямо в URL).
 *  По результатам выполнения запроса выведите ответ сервера в стандартную консоль и обратите
 *  внимание на поля form или args, в зависимости от типа запроса в которых должны быть перечислены
 *  все введённые вами аргументы.
 *  
 *  Рекомендации:
 *  Чтобы создать экземпляр объекта cpr::Payload для POST-запроса, используйте конструктор, который
 *  принимает диапазон итераторов массива от begin() до end(), соответственно. При этом тип
 *  элементов массива должен быть cpr:Pair, а сам массив содержит в себе имена параметров вместе с
 *  их значениями. Каждый элемент можно инициализировать с помощью конструктора cpr::Pair
 *  ((std::string)key, (std::string)value). Обратите внимание на использование эксплицитного
 *  приведения к строкам. Это может понадобиться, если используется старая версия библиотеки cpr.
 *  Согласно HTTP-стандарту, аргументы в GET-запросах перечисляются прямо в URL запроса после
 *  вопросительного знака. Названия аргументов отделяются от их значений с помощью символа “=”, а
 *  сами аргументы разделены символами “&”. Пример аргументов, заданных в URL запроса: 
 *  
 *      ?foo=first&animal=cat&bar=third
 *  
 *  Для хранения названий параметров и их значений используйте словарь:
 *  
 *      std::map<std::string, std::string> arguments;
 *  
 *  В таких словарях могут содержаться данные вида {“height”, “185”}, {“weight”, “75”}. В случае с
 *  нашими запросами там будет что-то другое, но идея та же: название — значение.  Чтобы пройти по
 *  такому словарю, потребуется итератор вида std::map<std::string, std::string>::iterator it;
 *  Используйте его так:
 *      for (it = arguments.begin(); it != arguments.end(); it++)
 *      {
 *          it->first // даёт доступ к названию параметра
 *          it->second // даёт доступ к значению параметра
 *      } */

#include <iostream>
#include <string>
#include <vector>
#include <cpr/cpr.h>
#include "Module_30.hpp"

// функция подсчета определенных символов
static unsigned int count_symbols(const std::string& str, const char symbol) {
    unsigned int counter = 0, found = str.find(symbol);
    while (found < str.length()) {
        counter++;
        found = str.find(symbol, found + 1);
    }
    
    return counter;
}

void Task_30_3() {
    std::cout << equals << string_tasks[2] << equals;

    // очистка буфера ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string command;
    std::stringstream buf;
    std::vector<cpr::Pair> pairs;
    cpr::Response response;

    do {
        std::cout << "Введите команду \"post\" или \"get\" либо пару аргументов через пробел: ";
        std::getline(std::cin, command);
        if (command == "post" || command == "get") {
            break;
        } else {
            if (count_symbols(command, ' ') == 1) {
                pairs.push_back({command.substr(0, command.find(' ')),
                                 command.substr(command.find(' ') + 1)});
            } else {
                std::cout << "Пара введена некорректно!\n";
            }
        }
    } while (true);
    
    if (command == "get") {
        // для get-запроса формируем url
        std::string url = "http://httpbin.org/get";
        if (pairs.size()) {
            url += "?";
            for (auto it = pairs.begin(); it != pairs.end(); it++) {
                url.append(it->key + "=" + it->value);
                if (it + 1 != pairs.end()) {
                    url.append("&");
                }
            }
        }

        response = cpr::Get(cpr::Url(url.data()));
        std::cout << response.text << "\n";
    } else if (command == "post") {
        // для post-запроса передаем данные в payload по const_iterator
        std::vector<cpr::Pair>::const_iterator begin = pairs.begin();
        std::vector<cpr::Pair>::const_iterator end = pairs.end();

        response = cpr::Post(cpr::Url("http://httpbin.org/post"),
                             cpr::Payload(begin, end));
        std::cout << response.text << "\n";
    }
}
#endif

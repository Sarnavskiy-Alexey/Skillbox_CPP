#ifdef __MODULE_30__
/* Задание 2. Захват заголовка веб-страницы
 *  Что нужно сделать:
 *  Запросите с сервера HTML-страницу. Для этого изучите документацию о запросах, поддерживаемых
 *  сервисом httpbin.org/html. Найдите там запрос, который выдаёт именно HTML-страницу. Затем
 *  сделайте запрос, явным образом используя заголовок accept: text/html. В полученном ответе
 *  найдите заголовок статьи и выведите его в консоль.
 *  
 *  Рекомендации:
 *  Заголовок статьи размещается между HTML-тегами <h1></h1>.
 *  Для доступа к тексту ответа вам потребуется метод text класса cpr::Response. Для поиска по
 *  тексту нужных HTML-тегов лучше использовать метод find. */

#include <iostream>
#include <cpr/cpr.h>
#include "Module_30.hpp"

void Task_30_2() {
    std::cout << equals << string_tasks[1] << equals;

    std::string header;
    cpr::Response response = cpr::Get(cpr::Url("http://httpbin.org/html"),
                                      cpr::Header({{"accept", "text/html"}}));
    header = response.text.substr(response.text.find("<h1>") + 4, (response.text.find("</h1>") - 4) - response.text.find("<h1>"));

    std::cout << "Заголовок: \"" << header << "\"\n";
}
#endif

#ifdef __MODULE_30__
#pragma once

#include <string>
const std::string string_tasks[] = {
    "\t\t\tЗадание 1. Пользовательские запросы\n  Что нужно сделать:\n  Реализуйте программу по осуществлению различных типов HTTP-запросов к сервису httpbin.org.\n  Пользователь взаимодействует с программой с помощью команд: “get”, “post”, “put”, “delete”, “patch”. В зависимости от команды к серверу httpbin.org осуществляется запрос того или иного типа. Содержимое ответа сервера выводится в стандартный вывод.\n  Программа завершается, когда пользователь вводит команду “exit”.\n\n  Рекомендации:\n  Для каждого HTTP-запроса в CPR есть отдельный метод, например cpr::Get.\n",
    "\t\t\tЗадание 2. Захват заголовка веб-страницы\n  Что нужно сделать:\n  Запросите с сервера HTML-страницу. Для этого изучите документацию о запросах, поддерживаемых сервисом httpbin.org/html. Найдите там запрос, который выдаёт именно HTML-страницу. Затем сделайте запрос, явным образом используя заголовок accept: text/html. В полученном ответе найдите заголовок статьи и выведите его в консоль.\n\n  Рекомендации:\n  Заголовок статьи размещается между HTML-тегами <h1></h1>.\n  Для доступа к тексту ответа вам потребуется метод text класса cpr::Response. Для поиска по тексту нужных HTML-тегов лучше использовать метод find.\n",
    "\t\t\tЗадание 3. Запросы с аргументами\n  Что нужно сделать:\n  Сделайте запрос к сервису httpbin.org, отправив при этом несколько дополнительных аргументов с данными.\n  Все названия аргументов и их значения строковые и принимаются от пользователя. Пользователь последовательно вводит их названия вместе со значениями, пока не встретится аргумент с названием “post” или “get”, что будет означать, что ввод аргументов закончен и требуется отправить их на сервер выбранным способом.\n  Если пользователь выбрал “post”, то выполняется POST-запрос и аргументы отправляются POST-способом (как форма). Если “get”, то выполняется GET-запрос с GET-аргументами (прямо в URL).\n  По результатам выполнения запроса выведите ответ сервера в стандартную консоль и обратите внимание на поля form или args, в зависимости от типа запроса в которых должны быть перечислены все введённые вами аргументы.\n\n  Рекомендации:\n  Чтобы создать экземпляр объекта cpr::Payload для POST-запроса, используйте конструктор, который принимает диапазон итераторов массива от begin() до end(), соответственно. При этом тип элементов массива должен быть cpr:Pair, а сам массив содержит в себе имена параметров вместе с их значениями. Каждый элемент можно инициализировать с помощью конструктора cpr::Pair((std::string)key, (std::string)value). Обратите внимание на использование эксплицитного приведения к строкам. Это может понадобиться, если используется старая версия библиотеки cpr.\n  Согласно HTTP-стандарту, аргументы в GET-запросах перечисляются прямо в URL запроса после вопросительного знака. Названия аргументов отделяются от их значений с помощью символа “=”, а сами аргументы разделены символами “&”. Пример аргументов, заданных в URL запроса:\n  ?foo=first&animal=cat&bar=third\n  Для хранения названий параметров и их значений используйте словарь:\n  std::map<std::string, std::string> arguments;\n  В таких словарях могут содержаться данные вида {“height”, “185”}, {“weight”, “75”}. В случае с нашими запросами там будет что-то другое, но идея та же: название — значение.  Чтобы пройти по такому словарю, потребуется итератор вида std::map<std::string, std::string>::iterator it; Используйте его так:\n  for (it = arguments.begin(); it != arguments.end(); it++)\n  {\n      it->first // даёт доступ к названию параметра\n      it->second // даёт доступ к значению параметра\n  }\n"
};

extern const std::string equals;

void Task_30_1();
void Task_30_2();
void Task_30_3();
#endif

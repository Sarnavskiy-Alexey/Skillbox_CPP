// #ifdef __MODULE_23__
#pragma once

#include <string>
const std::string string_tasks[] = {
    "\t\t\tЗадание 1. Реализация продвинутого ввода и вывода дней недели\n  Что нужно сделать\n  Используя макросы, реализуйте небольшую программу по вводу дня недели и выводу этого дня недели в текстовом виде в консоль.\n  В начале программы пользователь вводит день недели в виде его порядкового номера. В результате в консоли появляется буквенное отображение этого дня недели.\n  В этом упражнении запрещается использовать классические переменные, кроме как для хранения ввода пользователя. Использовать строковые литералы напрямую тоже нельзя. Всё должно быть реализовано исключительно на макросах.\n\n  Советы и рекомендации:\n  Конкатенация двух фрагментов может породить токен, который в свою очередь является именем макроса, и этот макрос тоже раскроется. Используйте это свойство для перевода константы дня недели в строковый литерал.\n  Обязательно просмотрите итоговый код после препроцессинга из CLion с помощью Shift-Shift → Preprocess current TU.\n",
    "\t\t\tЗадание 2. Вывод времени года\n  Что нужно сделать\n  Используя макросы вместе с условными директивами прекомпиляции (#if / #endif), реализуйте простую программу по выводу названия времени года в консоль.\n  Пользователь программы, который будет иметь дело с вашим кодом, в этом случае тоже программист. С помощью определения одного из макросов (в самом коде): SPRING, SUMMER, AUTUMN или WINTER он задаёт сезон, название, которое хочет увидеть на экране. При компиляции и запуске программы на экране должно появиться название именно этого сезона и только его.\n\n  Советы и рекомендации:\n  Так как препроцессор работает до компиляции, то в #if/#endif-директивы вы можете обернуть всю функцию main сразу.\n  Обязательно просмотрите итоговый код после препроцессинга из CLion с помощью Shift-Shift → Preprocess current TU.\n",
    "\t\t\tЗадание 3. Анализ заполненности вагонов в поезде* (дополнительное задание)\n  Что нужно сделать\n  В поезде всего 10 вагонов. В каждом из этих вагонов может находиться до 20 пассажиров — это их оптимальное количество. Проанализируйте количество людей в каждом вагоне и сначала сообщите об излишне заполненных вагонах, далее о вагонах с пустыми пассажирскими местами. В заключение выведите общее количество пассажиров во всех вагонах.\n  При старте программы пользователь вводит количество пассажиров в каждом вагоне. Замечания о вагонах должны выводиться в стандартную консоль.\n  При выполнении задания пользоваться нельзя напрямую пользоваться for-циклами, только опосредованно, через макросы.\n\n  Советы и рекомендации:\n  С помощью макроса реализуйте модульный способ вызова функции над элементами массива. Сами функции реализуйте отдельно, в виде обычных классических функций (не макросов).\n  Модульный способ вызова функции печати текста через макрос:\n\n      #define CALL(func) { func(\"Hello, Skillbox!\"); }\n      void print(std::string str) {\n         std::cout << str << std::endl;\n      }\n      int main() {\n         CALL(print);\n         return 0;\n      }\n\n  Обязательно просмотрите итоговый код после препроцессинга из CLion с помощью Shift-Shift → Preprocess current TU.\n"
};

extern const std::string equals;

void Task_23_1();
void Task_23_2();
void Task_23_3();
// #endif

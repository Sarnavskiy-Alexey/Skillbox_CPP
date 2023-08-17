#ifdef __MODULE_22__
/* Задание 2. Регистратура
 *  Что нужно сделать
 *  Напишите программу «Регистратура».
 *  На вход программе приходят строки с фамилиями или строка Next. Пришедшие люди становятся в
 *  очередь, а по запросу Next необходимо вызвать в регистратуру человека с фамилией, идущей первой
 *  в лексикографическом порядке (по алфавиту), и вывести его фамилию на экран. Фамилии пациентов
 *  могут повторяться.
 *  Каждый запрос (на добавление и вывод) должен работать за O(logn).
 *  
 *  Пример:
 *  ← Sidorov
 *  ← Ivanov
 *  ← Ivanov
 *  ← Petrov
 *  ← Next
 *  → Ivanov
 *  ← Next
 *  → Ivanov
 *  ← Next
 *  → Petrov */

#include <iostream>
#include <string>
#include <map>
#include "Module_22.hpp"

void Task_22_2() {
    std::cout << equals << string_tasks[1] << equals;

    std::map<std::string, int> registry;
    std::string str;
    do {
        std::cout << "← ";
        std::cin >> str;
        if (str == "Next") {
            if (!registry.empty()) {
                std::cout << "→ " << registry.begin()->first << "\n";
                registry.begin()->second--;
                if (registry.begin()->second == 0) {
                    registry.erase(registry.begin());
                }
            }
        } else {
            if (registry.find(str) != registry.end()) {
                registry[str]++;
            } else {
                registry[str] = 1;
            }
        }
    } while(!registry.empty());
}
#endif

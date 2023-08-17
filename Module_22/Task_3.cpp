#ifdef __MODULE_22__
/* Задание 3. Анаграммы 
 *  Что нужно сделать
 *  Напишите функцию, которая принимает две строки и возвращает true, если первая строка является
 *  анаграммой второй (то есть можно получить первую строку из второй путём перестановки букв
 *  местами), и false иначе. Для достижения хорошей асимптотики решения рекомендуется использовать
 *  std::map.
 * 
 *  Пример анаграммы: лекарство — стекловар */

#include <iostream>
#include <string>
#include <map>
#include "Module_22.hpp"

// функция добавления символов в словарь
static void add_in_map(std::map<char, int>& map, const std::string& str, const int mult = 1) {
    for (unsigned int i = 0; i < str.length(); i++) {
        if (map.find(str[i]) == map.end()) {
            map[str[i]] = mult;
        } else {
            map[str[i]] += mult;
        }
        if (map[str[i]] == 0) {
            map.erase(str[i]);
        }
    }
}

// функция проверки на анаграмму
static bool is_anagram(const std::string& str1, const std::string& str2) {
    std::map<char, int> map;
    add_in_map(map, str1);
    add_in_map(map, str2, -1);
    return map.empty();
}

void Task_22_3() {
    std::cout << equals << string_tasks[2] << equals;

    std::string str1;
    std::string str2;

    std::cout << "Введите первое слово: ";
    std::cin >> str1;
    std::cout << "Введите второе слово: ";
    std::cin >> str2;

    std::cout << "Два слова" << (is_anagram(str1, str2) ? " " : " не ") << "являются анаграммами!\n";
}
#endif

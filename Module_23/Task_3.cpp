#ifdef __MODULE_23__
/* Задание 3. Анализ заполненности вагонов в поезде* (дополнительное задание)
 *  Что нужно сделать
 *  В поезде всего 10 вагонов. В каждом из этих вагонов может находиться до 20 пассажиров — это их
 *  оптимальное количество. Проанализируйте количество людей в каждом вагоне и сначала сообщите об
 *  излишне заполненных вагонах, далее о вагонах с пустыми пассажирскими местами. В заключение
 *  выведите общее количество пассажиров во всех вагонах.
 *  При старте программы пользователь вводит количество пассажиров в каждом вагоне. Замечания о
 *  вагонах должны выводиться в стандартную консоль.
 *  При выполнении задания пользоваться нельзя напрямую пользоваться for-циклами, только
 *  опосредованно, через макросы.
 *  
 *  Советы и рекомендации
 *  - С помощью макроса реализуйте модульный способ вызова функции над элементами массива. Сами
 *    функции реализуйте отдельно, в виде обычных классических функций (не макросов).
 *  - Модульный способ вызова функции печати текста через макрос:
 *        #define CALL(func) { func("Hello, Skillbox!"); }
 *        void print(std::string str) {
 *            std::cout << str << std::endl;
 *        }
 *        int main() {
 *           CALL(print);
 *           return 0;
 *        }
 *  - Обязательно просмотрите итоговый код после препроцессинга из CLion с помощью Shift-Shift →
 *    Preprocess current TU. */

#include <iostream>
#include "Module_23.hpp"

#define SIZE 10
#define MIN_LIMIT 0
#define MAX_LIMIT 20

#define CALL(func) func(vagons)

// функция ввода данных
static void cin_passengers(unsigned int vagons[SIZE]) {
    std::cout << "Введите данные о " << SIZE << " вагонах: ";
    for (int i = 0; i < SIZE; i++) {
        std::cin >> vagons[i];
    }
}

// функция проверки на переполненность вагонов
static void check_max_limit(unsigned int vagons[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (vagons[i] > MAX_LIMIT)
            std::cout << "Вагон #" << i << " переполнен!\n";
    }
}

// функция проверки на незаполненность вагонов
static void check_min_limit(unsigned int vagons[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (vagons[i] <= MIN_LIMIT)
            std::cout << "Вагон #" << i << " не заполнен!\n";
    }
}

// функция нахождения общего количества пассажиров в поезде
static unsigned int sum_pas(unsigned int vagons[SIZE]) {
    unsigned int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += vagons[i];
    }
    return sum;
}

void Task_23_3() {
    std::cout << equals << string_tasks[2] << equals;

    unsigned int vagons[SIZE];
    CALL(cin_passengers);
    CALL(check_max_limit);
    CALL(check_min_limit);
    std::cout << "Общее количество пассажиров: " << CALL(sum_pas) << "\n";
}
#endif

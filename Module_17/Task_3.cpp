#ifdef __MODULE_17__
/* Задача 3.
 *  Что нужно сделать:
 *  Написать функцию, которая принимает указатель на char, по которому лежит строка. 
 *  Функция должна возвращать true, если вторая строка является подстрокой первой. 
 *  Пример:
 *  
 *  const char* a = "Hello world";
 *  const char* b = "wor";
 *  const char* c = "banana";
 *  std::cout << substr(a,b) << " " << substr(a,c);
 *  // true false
 *  const-квалификатор
 *  
 *  const является квалификатором типа, применяемым к переменным, значения которых нельзя изменять.
 *  
 *  Например, если в коде написать:
 *  const int a = 2;
 *  то впоследствии значение переменной невозможно изменить, а запись вида
 *  a = 3;
 *  приведёт к ошибке компилятора.
 *  
 *  Чек-лист для проверки задачи
 *  - Функция принимает корректные типы данных, тип возвращаемого значения -- bool
 *  - Функция не использует библиотек кроме <iostream> и <cstring> или другую для работы со строками
 *  - Функция корректно определяет, является ли вторая строка подстрокой первой. */

#include <iostream>
#include "Module_17.hpp"

static int length(const char* str) {
    int size = 0;
    while (str[size] != '\0') size++;
    return size;
}

static bool substr(const char* a, const char* b) {
    int size_a = length(a);
    int size_b = length(b);
    int i = 0;
    while (size_a - size_b - i >= 0) {
        bool result = true;
        for (int j = 0; j < size_b; j++) {
            if (a[i + j] != b[j]) {
                result = false;
                break;
            }
        }
        if (result) return true;
        else        i++;
    }
    return false;
}

void Task_17_3() {
    std::cout << equals << string_tasks[2] << equals;

    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";

    if (substr(a, b))
        std::cout << "true:\n\t" << "\""<< a << "\" contains \"" << b << "\"\n";
    else
        std::cout << "false:\n\t" << "\""<< a << "\" doesn\'t contain \"" << b << "\"\n";
        
    if (substr(a, c))
        std::cout << "true:\n\t" << "\""<< a << "\" contains \"" << c << "\"\n";
    else
        std::cout << "false:\n\t" << "\""<< a << "\" doesn\'t contain \"" << c << "\"\n";
}
#endif

/* Задача 4 (дополнительная). Повышаем градус сложности*
 *  Вернитесь к задаче про обмен местами значений переменных и попробуйте решить её без
 *  использования третьей переменной (упс, спойлер, но ничего страшного!). Догадайтесь, в каких
 *  случаях новый способ может не работать и какие у него преимущества. */

#include <iostream>
#include "Module_03.hpp"

void Task_03_4() {
    std::cout << equals << string_tasks[3] << equals;

    int a = 5;
    int b = 10;

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    std::cout << "\n-----------Магия-----------\n\n";

    a += b;
    b = a - b;
    a -= b;

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
}
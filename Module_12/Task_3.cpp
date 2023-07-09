#ifdef __MODULE_12__
/* Задание 3. Использование assert
 *  Создайте в своей программе функцию float travelTime(float distance, float speed). Она будет
 *  находить время в пути и при этом использовать assert, чтобы отбросить нулевую и отрицательную
 *  скорость. Вызовите эту функцию в main. Убедитесь, что падение происходит за счёт assert. Не
 *  забудьте подключить заголовочный файл cassert. */

#include <iostream>
#include <cassert>
#include "Module_12.hpp"

// функция, использующая assert
static float travelTime(float distance, float speed) {
    assert(speed > 0.0f);
    return distance / speed;
}

void Task_12_3() {
    std::cout << equals << string_tasks[2] << equals;
    
    float distance, speed;
    std::cout << "Введите путь: ";
    std::cin >> distance;
    std::cout << "Введите скорость: ";
    std::cin >> speed;

    std::cout << travelTime(distance, speed) << "\n";
}
#endif

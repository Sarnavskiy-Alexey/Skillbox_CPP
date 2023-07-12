#ifdef __MODULE_12__
#pragma once

const std::string string_tasks[] = {
    "\t\t\tЗадание 1. Многоквартирный дом\n  На вход программе поступают десять фамилий в формате строк. Это фамилии жильцов квартир с первой по десятую. Необходимо прочитать эти фамилии и записать в одномерный массив. Далее пользователь вводит три номера квартир. Необходимо вывести в консоль фамилию жильца, проживающего в этой квартире. Если пользователь введёт некорректный номер квартиры, необходимо сообщить ему об этом.\n",
    "\t\t\tЗадание 2. Сортировка\n  Пользователь вводит в консоль 15 дробных чисел. Необходимо прочитать их и вывести в консоль в порядке от большего к меньшему. По возможности используйте минимум дополнительной памяти и проходов по массиву.\n",
    "\t\t\tЗадание 3. Использование assert\n  Создайте в своей программе функцию float travelTime(float distance, float speed). Она будет находить время в пути и при этом использовать assert, чтобы отбросить нулевую и отрицательную скорость. Вызовите эту функцию в main. Убедитесь, что падение происходит за счёт assert. Не забудьте подключить заголовочный файл cassert.\n",
    "\t\t\tЗадание 4. Ряд чисел* (дополнительное задание)\n  В программе инициализирован массив из 15 целых положительных чисел. Эти числа являются множеством из 14 последовательных чисел, начиная с Х (Х может быть любым), а одно число из ряда повторяется. Необходимо найти повторяющееся число и вывести его в консоль. По возможности используйте минимум дополнительной памяти и проходов по массиву.\n"
};

extern const std::string equals;

void Task_12_1();
void Task_12_2();
void Task_12_3();
void Task_12_4();
#endif
#ifdef __MODULE_05__
/* Задание 1. Военный фельдшер
 *  Напишите программу, проверяющую, достаточно ли снаряжения у фельдшера для выхода на работу с
 *  ранеными. Для этого ему нужно иметь при себе не менее 2000 мл медицинского спирта или не менее
 *  пяти наборов походных аптек. */

#include <iostream>
#include "Module_05.hpp"

void Task_05_1() {
    std::cout << equals << string_tasks[0] << equals;

    int medicalAlcoholVolume, firstAidKits;
    std::cout << "Введите объем имеющегося медицинского спирта (мл): ";
    std::cin >> medicalAlcoholVolume;
    std::cout << "Введите количество наборов походных аптечек: ";
    std::cin >> firstAidKits;

    std::cout << "\n----------------Проверка----------------\n\n";
    
    if (medicalAlcoholVolume >= 2000 || firstAidKits >= 5)
        std::cout << "Фельдшер может выйти на работу с раненными!\n";
    else
        std::cout << "Фельдшеру отказано в выходе на работу с раненными!\n";
}
#endif

/* Задание 8. Зарплата (дополнительное задание)
 *  В отделе маркетинга работают три сотрудника. Их зарплаты могут быть как разными, так и
 *  одинаковыми. Напишите программу, которая вычисляет разницу между самой высокой и самой низкой
 *  зарплатами сотрудников, а также среднее арифметическое зарплат всех сотрудников отдела. */

#include <iostream>
#include "Module_04.hpp"

void Task_04_8() {
    std::cout << equals << string_tasks[7] << equals;

    int salaryEmployee_1, salaryEmployee_2, salaryEmployee_3;
    int maxSalary, minSalary, differenceMaxMin;

    std::cout << "Введите зарплату первого сотрудника:  ";
    std::cin >> salaryEmployee_1;
    std::cout << "Введите зарплату второго сотрудника:  ";
    std::cin >> salaryEmployee_2;
    std::cout << "Введите зарплату третьего сотрудника: ";
    std::cin >> salaryEmployee_3;

    maxSalary = salaryEmployee_1;
    if (salaryEmployee_2 > maxSalary)
        maxSalary = salaryEmployee_2;
    if (salaryEmployee_3 > maxSalary)
        maxSalary = salaryEmployee_3;
    minSalary = salaryEmployee_1;
    if (salaryEmployee_2 < minSalary)
        minSalary = salaryEmployee_2;
    if (salaryEmployee_3 < minSalary)
        minSalary = salaryEmployee_3;

    differenceMaxMin = maxSalary - minSalary;
    if (differenceMaxMin) {
        std::cout << "Наибольшая зарплата: " << maxSalary << "\n";
        std::cout << "Наименьшая зарплата: " << minSalary << "\n";
        std::cout << "Разница между max и min: " << differenceMaxMin << "\n";
    }
    else
        std::cout << "Зарплаты всех сотрудников одинаковые!\n";
    double averageSalary = (salaryEmployee_1 + salaryEmployee_2 + salaryEmployee_3) / 3.0;
    std::cout << "Среднее арифметическое зарплат: "
              << averageSalary << "\n";
}
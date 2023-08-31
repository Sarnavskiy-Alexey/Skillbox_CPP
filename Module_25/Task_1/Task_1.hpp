#ifdef __MODULE_25__

/* Заголовочный файл Module_25/Task_1 */
#pragma once

#include <iostream>
#include <string>
#include "Task_1_coord.hpp"

// класс перечисления операций
enum class E_Operation {
    scalpel,
    hemostat,
    tweezers,
    suture,
    help,
    error
};

// структура любой операции
struct S_Operation {
    E_Operation operation_type;
    S_Coordinate coord1;
    S_Coordinate coord2;
};

// первая операция: скальпель
S_Operation scalpel_operation;

static void scalpel_func(S_Operation operation) {
    std::cout << "Выполнен разрез между точками ";
    print_coordinate(operation.coord1);
    std::cout << " и ";
    print_coordinate(operation.coord2);
    std::cout << ".\n";
}

static void hemostat_func(S_Operation operation) {
    std::cout << "Необходим зажим в точке ";
    print_coordinate(operation.coord1);
    std::cout << ".\n";
}

static void tweezers_func(S_Operation operation) {
    std::cout << "Пинцет применяется в точке ";
    print_coordinate(operation.coord1);
    std::cout << ".\n";
}

static void suture_func(S_Operation operation) {
    std::cout << "Делается шов между точками ";
    print_coordinate(operation.coord1);
    std::cout << " и ";
    print_coordinate(operation.coord2);
    std::cout << ".\n";
}

#endif

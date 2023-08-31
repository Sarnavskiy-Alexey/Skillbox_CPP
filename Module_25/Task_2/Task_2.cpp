#ifdef __MODULE_25__
/* Задание 2. Проект симулятора работы компьютера
 *  Что нужно сделать
 *  Реализуйте простую модель работы персонального компьютера в качестве многомодульного проекта. В
 *  компьютере несколько основных, условных компонент.
 *  Центральный процессор (cpu) — должен иметь функцию compute, которая складывает 8 чисел из буфера
 *  оперативной памяти (см. далее) и выводит результат в консоль.
 *  Оперативная память (ram) — содержит буфер на 8 целых чисел, которые можно заполнить функцией
 *  write и считать функцией read.
 *  Жёсткий диск (disk) — имеет в себе две функции, save и load. Функция save должна сохранить
 *  состояние 8 чисел из оперативной памяти на постоянный носитель в файл data.txt. Функция load —
 *  загрузить их с носителя в оперативную память.
 *  Графическая карта (gpu) — выводит в консоль 8 чисел из оперативной памяти.
 *  Клавиатура (kbd) — позволяет ввести 8 чисел и разместить их в оперативной памяти.
 *  Каждая компонента должна располагаться в отдельном модуле, с отдельным заголовочным файлом.
 *  Основной модуль программы (main.cpp) должен считывать пользовательский ввод команды, которая
 *  соответствует отдельным функциям устройств: sum (вычисление суммы), save (сохранить в файл),
 *  load (загрузить из файла), input (ввести с клавиатуры), display (вывести на экран). Команда
 *  exit — выходит из программы.
 *  
 *  Советы и рекомендации
 *  - Тщательно продумайте зависимости между модулями и теми файлами, которые должны быть включены в
 *    исходные файлы. Не забывайте про #pragma once в заголовочных файлах.
 *  - В заголовочных файлах модулей располагайте только объявления функций. Их определения должны
 *    быть уже в исходных файлах (CPP). */

#include <iostream>
#include <string>

#ifdef __CMAKELISTS__
// необходимо по условию и для корректной работы с CMake
#include "Module_25.hpp"
#else
// необходимо для удобной работы в vsc ()
#include "../Module_25.hpp"
#endif

#ifdef __CMAKELISTS__
// необходимо по условию и для корректной работы с CMake
#include "cpu.hpp"
#include "disk.hpp"
#include "gpu.hpp"
#include "kbd.hpp"
#include "ram.hpp"
#else
// необходимо для удобной работы в vsc ()
#include "inc/cpu.hpp"
#include "inc/disk.hpp"
#include "inc/gpu.hpp"
#include "inc/kbd.hpp"
#include "inc/ram.hpp"
#endif

enum class E_Operation {
    sum,
    save,
    load,
    input,
    display,
    exit,
    help,
    error
};

const std::string operations[] = {
    "sum",
    "save",
    "load",
    "input",
    "display",
    "exit",
    "help"
};

// исполняет роль main.cpp из условия задачи
void Task_25_2() {
    std::cout << equals << string_tasks[1] << equals;
    
    E_Operation op;
    std::string operation;
    do {
        std::cout << "Введите команду: ";
        std::cin >> operation;
        if (operation == operations[(unsigned int)E_Operation::sum]) {
            std::cout << "Сумма: " << compute() << "\n";
            op = E_Operation::sum;
        } else if (operation == operations[(unsigned int)E_Operation::save]) {
            save();
            op = E_Operation::save;
        } else if (operation == operations[(unsigned int)E_Operation::load]) {
            load();
            op = E_Operation::load;
        } else if (operation == operations[(unsigned int)E_Operation::input]) {
            kbd();
            op = E_Operation::input;
        } else if (operation == operations[(unsigned int)E_Operation::display]) {
            gpu();
            op = E_Operation::display;
        } else if (operation == operations[(unsigned int)E_Operation::exit]) {
            op = E_Operation::exit;
        } else if (operation == operations[(unsigned int)E_Operation::help]) {
            std::cout << "\t\"sum\"     - отображение суммы чисел буфера ram\n";
            std::cout << "\t\"save\"    - сохранение буфера ram в файл \"data.txt\"\n";
            std::cout << "\t\"load\"    - загрузка буфера ram из файла \"data.txt\"\n";
            std::cout << "\t\"input\"   - ввод буфера ram с клавиатуры\n";
            std::cout << "\t\"display\" - отображение на экране данных буфера ram\n";
            std::cout << "\t\"exit\"    - выход из задания\n";
            std::cout << "\t\"help\"    - вывод этого сообщения\n";
            op = E_Operation::help;
        } else {
            std::cout << "Ошибка в команде!\n";
            op = E_Operation::error;
        }
    } while (op != E_Operation::exit);
}

#endif

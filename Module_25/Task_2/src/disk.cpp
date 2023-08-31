/* МОДУЛЬ disk */

#ifdef __MODULE_25__

#include <iostream>
#include <fstream>

#ifdef __CMAKELISTS__
// необходимо по условию и для корректной работы с CMake
#include "disk.hpp"
#include "ram.hpp"
#include "Module_25.hpp"
#else
// необходимо для удобной работы в vsc ()
#include "../inc/disk.hpp"
#include "../inc/ram.hpp"
#include "../../Module_25.hpp"
#endif

// функция save модуля disk
void save() {
    unsigned int i = 0;
    int number;
    std::ofstream file;

    file.open(CUR_DIR + TASK2_DOCS_DIR + "data.txt", std::ios::binary);
    
    if (file.is_open()) {
        // считываем каждое число по нужному индексу
        while (i < 8) {
            number = read();
            file.write((char*)&(number), sizeof(number));
            i++;
        }
        file.close();
    } else {
        std::cout << "ERROR! WFile is not open!\n";
    }
}

// функция load модуля disk
void load() {
    unsigned int i = 0;
    int number;
    std::ifstream file;

    file.open(CUR_DIR + TASK2_DOCS_DIR + "data.txt", std::ios::binary);
    
    if (file.is_open()) {
        // считываем каждое число по нужному индексу
        while (i < 8 && !file.eof()) {
            file.read((char*)&(number), sizeof(number));
            write(number);
            i++;
        }
        file.close();

        // дозаполняем массив нулями, если i не достиг 8 (на случай ручной корректировки файла)
        while (i < 8) {
            write(0);
            i++;
        }
    } else {
        std::cout << "ERROR! RFile is not open!\n";
    }
}

#endif

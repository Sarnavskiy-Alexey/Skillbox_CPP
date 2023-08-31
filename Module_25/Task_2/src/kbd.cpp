/* МОДУЛЬ kbd */

#ifdef __MODULE_25__

#include <iostream>

#ifdef __CMAKELISTS__
// необходимо по условию и для корректной работы с CMake
#include "kbd.hpp"
#include "ram.hpp"
#else
// необходимо для удобной работы в vsc ()
#include "../inc/kbd.hpp"
#include "../inc/ram.hpp"
#endif

void kbd() {
    std::cout << "Введите 8 чисел: ";
    int number;
    unsigned int i = 0;
    while (i < 8) {
        std::cin >> number;
        write(number);
        i++;
    }
}

#endif

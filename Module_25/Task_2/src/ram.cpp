/* МОДУЛЬ ram */

#ifdef __MODULE_25__

#ifdef __CMAKELISTS__
// необходимо по условию и для корректной работы с CMake
#include "ram.hpp"
#else
// необходимо для удобной работы в vsc ()
#include "../inc/ram.hpp"
#endif

// глобальные переменные буфера и текущей позиции для записи значения
int buffer[8] = { 0 };
static unsigned int fill_index = 0;

// функция read модуля ram
int read() {
    int result = buffer[fill_index];
    fill_index = (fill_index + 1) % 8;
    return result;
}

// функция write модуля ram
void write(int number) {
    buffer[fill_index] = number;
    fill_index = (fill_index + 1) % 8;
}

#endif

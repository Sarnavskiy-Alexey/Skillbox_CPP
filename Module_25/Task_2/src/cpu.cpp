/* МОДУЛЬ cpu */

#ifdef __MODULE_25__

#ifdef __CMAKELISTS__
// необходимо по условию и для корректной работы с CMake
#include "cpu.hpp"
#include "ram.hpp"
#else
// необходимо для удобной работы в vsc ()
#include "../inc/cpu.hpp"
#include "../inc/ram.hpp"
#endif

int compute() {
    unsigned int i = 1;
    int result = read();
    while(i < 8) {
        result += read();
        i++;
    }
    return result;
}

#endif

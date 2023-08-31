/* МОДУЛЬ gpu */

#ifdef __MODULE_25__
#include <iostream>

#ifdef __CMAKELISTS__
// необходимо по условию и для корректной работы с CMake
#include "gpu.hpp"
#include "ram.hpp"
#else
// необходимо для удобной работы в vsc ()
#include "../inc/gpu.hpp"
#include "../inc/ram.hpp"
#endif

void gpu() {
    unsigned int i = 0;
    while (i < 8) {
        std::cout << read() << " ";
        i++;
    }
    std::cout << "\n";
}

#endif

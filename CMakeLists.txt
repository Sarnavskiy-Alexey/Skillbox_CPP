cmake_minimum_required(VERSION 3.17)
project("Skillbox Homework" VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

# add needable definitions to build needable SW
add_compile_definitions(__MODULE_25__)
add_compile_definitions(__CMAKELISTS__)

add_executable(
    Skillbox_HomeWorks

    main.cpp
    main.hpp

    Module_25/Module_25.cpp
    Module_25/Module_25.hpp

    Module_25/Task_1/Task_1.cpp
    Module_25/Task_1/Task_1.hpp
    Module_25/Task_1/Task_1_coord.hpp
    
    Module_25/Task_2/Task_2.cpp
    Module_25/Task_2/inc/cpu.hpp
    Module_25/Task_2/src/cpu.cpp
    Module_25/Task_2/inc/disk.hpp
    Module_25/Task_2/src/disk.cpp
    Module_25/Task_2/inc/gpu.hpp
    Module_25/Task_2/src/gpu.cpp
    Module_25/Task_2/inc/kbd.hpp
    Module_25/Task_2/src/kbd.cpp
    Module_25/Task_2/inc/ram.hpp
    Module_25/Task_2/src/ram.cpp
)
target_include_directories(Skillbox_HomeWorks PUBLIC Module_25)
target_include_directories(Skillbox_HomeWorks PUBLIC Module_25/Task_1)
target_include_directories(Skillbox_HomeWorks PUBLIC Module_25/Task_2)
target_include_directories(Skillbox_HomeWorks PUBLIC Module_25/Task_2/inc)
target_include_directories(Skillbox_HomeWorks PUBLIC Module_25/Task_2/src)

# # Для модуля 25
# cmake_minimum_required(VERSION 3.17)
# project("Skillbox Homework" VERSION 1.0)
#
# set(CMAKE_CXX_STANDARD 20)
#
# # add needable definitions to build needable SW
# add_compile_definitions(__MODULE_25__)
# add_compile_definitions(__CMAKELISTS__)
#
# add_executable(
#     Skillbox_HomeWorks
#
#     main.cpp
#     main.hpp
#
#     Module_25/Module_25.cpp
#     Module_25/Module_25.hpp
#
#     Module_25/Task_1/Task_1.cpp
#     Module_25/Task_1/Task_1.hpp
#     Module_25/Task_1/Task_1_coord.hpp
#    
#     Module_25/Task_2/Task_2.cpp
#     Module_25/Task_2/inc/cpu.hpp
#     Module_25/Task_2/src/cpu.cpp
#     Module_25/Task_2/inc/disk.hpp
#     Module_25/Task_2/src/disk.cpp
#     Module_25/Task_2/inc/gpu.hpp
#     Module_25/Task_2/src/gpu.cpp
#     Module_25/Task_2/inc/kbd.hpp
#     Module_25/Task_2/src/kbd.cpp
#     Module_25/Task_2/inc/ram.hpp
#     Module_25/Task_2/src/ram.cpp
# )
# target_include_directories(Skillbox_HomeWorks PUBLIC Module_25)
# target_include_directories(Skillbox_HomeWorks PUBLIC Module_25/Task_1)
# target_include_directories(Skillbox_HomeWorks PUBLIC Module_25/Task_2)
# target_include_directories(Skillbox_HomeWorks PUBLIC Module_25/Task_2/inc)
# target_include_directories(Skillbox_HomeWorks PUBLIC Module_25/Task_2/src)


# # Для модуля 30
# cmake_minimum_required(VERSION 3.17)
# project("Skillbox Homework" VERSION 1.0)

# set(CMAKE_CXX_STANDARD 20)

# set(BUILD_CPR_TESTS OFF)
# set(CMAKE_USE_OPENSSL OFF)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# include(FetchContent)
# FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
# GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
# FetchContent_MakeAvailable(cpr)

# add_compile_definitions(__MODULE_30__)

# add_executable(
#     Skillbox_HomeWorks
    
#     main.cpp
#     main.hpp

#     Module_30/Module_30.cpp
#     Module_30/Module_30.hpp

#     Module_30/Task_1.cpp

#     Module_30/Task_2.cpp

#     Module_30/Task_3.cpp
#     )

# target_link_libraries(Skillbox_HomeWorks PRIVATE cpr::cpr)

# Для модуля 32
cmake_minimum_required(VERSION 3.17)
project("Skillbox Homework" VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_compile_definitions(__MODULE_32__)

add_executable(
    Skillbox_HomeWorks
    
    main.cpp
    main.hpp

    Module_32/Module_32.cpp
    Module_32/Module_32.hpp

    Module_32/Task_1.cpp

    Module_32/Task_2.cpp
    Module_32/Task_2.hpp

    Module_32/Task_3.cpp
    )

target_link_libraries(Skillbox_HomeWorks PRIVATE nlohmann_json::nlohmann_json)

# # Для модулей с Qt
# cmake_minimum_required(VERSION 3.17)
# project("Skillbox Homework" VERSION 1.0)

# set(CMAKE_CXX_STANDARD 14)
# # Qt установлен на диск D
# set(CMAKE_PREFIX_PATH "d:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")

# find_package(Qt5Widgets REQUIRED)

# add_executable(
#     Skillbox_HomeWorks
    
#     main.cpp
#     main.hpp
#     )
# target_link_libraries(Skillbox_HomeWorks Qt5::Widgets)

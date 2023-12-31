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

# # Для модуля 32
# cmake_minimum_required(VERSION 3.17)
# project("Skillbox Homework" VERSION 1.0)

# set(CMAKE_CXX_STANDARD 20)

# set(JSON_BuildTests OFF CACHE INTERNAL "")

# add_subdirectory(nlohmann_json)

# add_compile_definitions(__MODULE_32__)

# add_executable(
#     Skillbox_HomeWorks
    
#     main.cpp
#     main.hpp

#     Module_32/Module_32.cpp
#     Module_32/Module_32.hpp

#     Module_32/Task_1.cpp

#     Module_32/Task_2.cpp
#     Module_32/Task_2.hpp

#     Module_32/Task_3.cpp
#     )

# target_link_libraries(Skillbox_HomeWorks PRIVATE nlohmann_json::nlohmann_json)

# Для модулей с Qt
cmake_minimum_required(VERSION 3.14)
project(Skillbox_HomeWorks)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Quick
        REQUIRED)

add_compile_definitions(__MODULE_36__)
add_compile_definitions(__MODULE_37__)
# add_compile_definitions(__MODULE_38__)
# add_compile_definitions(__MODULE_39__)

add_executable(Skillbox_HomeWorks
        main.cpp
        main.hpp
        
        Module_36/Module_36.cpp
        Module_36/Task_36_1.cpp

        Module_37/Module_37.cpp
        Module_37/Module_37.hpp
        Module_37/Task_37_1.cpp
        Module_37/calculator.ui
        Module_37/calculatorMainWindow.cpp
        Module_37/calculatorMainWindow.hpp
        Module_37/Task_37_2.cpp
        Module_37/Task_37_3.cpp
        Module_37/pult.ui
        Module_37/pultMainWindow.cpp
        Module_37/pultMainWindow.hpp
)

target_link_libraries(Skillbox_HomeWorks
        PRIVATE Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Quick
)

if (WIN32)
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}/../..")
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif()
    foreach(QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach(QT_LIB)
endif ()

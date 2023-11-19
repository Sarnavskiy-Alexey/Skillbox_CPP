#ifdef __MODULE_35__
/* Задание 3 (к уроку 4)
 *  Цель задания:
 *  Поработать с файловой системой, используя новую библиотеку std::filesystem.
 *  
 *  Что нужно сделать:
 *  В нашем арсенале теперь есть возможность рекурсивно проходить по каталогам, то есть получить
 *  список всех файлов, каталогов (и подкаталогов), которые содержатся по указанному пути. Для этого
 *  в стандартной библиотеке есть std::filesystem::recursive_directory_iterator, принимающий на вход
 *  путь, который он будет обходить рекурсивно. На каждом шаге он будет выдавать очередной путь, это
 *  может быть как каталог, так и обычный файл. Например, код
 *  
 *      for(auto& p: fs::recursive_directory_iterator("D:\\dir1"))
 *          std::cout << p.path() << '\n';
 *  
 *  выведет полные пути ко всем файлам и подкаталогам в директории D:\dir1. Вызов p.path()
 *  возвращает объект типа std::filesystem::path, который позволяет:
 *    1. Определить, файл это или каталог при помощи метода is_regular_file().
 *    2. Получить расширение для обычного файла при помощи метода extension().
 *  При помощи метода compare() можно сравнить расширение с произвольной строкой:
 *      p.path().extension().compare(“.torrent”).
 *  
 *  Создайте лямбда-функцию, которая принимает на вход путь в файловой системе и искомое расширение
 *  в виде строки, а возвращает список имён файлов, которые имеют данное расширение(). Объявление
 *  нашей функции может начинаться так:
 *      auto recursiveGetFileNamesByExtension =
 *          [](std::filesystem::path path,
 *              const std::string extension) */

#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <algorithm>
#include "Module_35.hpp"

static auto recursiveGetFileNamesByExtension = [](std::filesystem::path &path, const std::string &extension) {
    std::vector<std::filesystem::path> v;
    for (auto& fn : std::filesystem::recursive_directory_iterator(path)) {
        if (fn.is_regular_file()) {
            if (!fn.path().extension().compare(extension)){
                v.push_back(fn.path());
            }
        }
    }
    return v;
};

static inline bool check_right_ext(const std::string& ext) {
    return ext.length() && ext[0] == '.' && std::count_if(ext.begin(), ext.end(), [](const char &c){ return (c == '.'); }) == 1;
}

void Task_35_3() {
    std::cout << equals << string_tasks[2] << equals;

    // очистка буфера ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string path_name, ext;

    std::cout << "Введите путь, в котором хотите найти файлы: ";
    std::getline(std::cin, path_name);
    while (true) {
        std::cout << "Введите расширение с точкой для поиска файлов с таким расширением: ";
        std::getline(std::cin, ext);
        if (check_right_ext(ext)) {
            break;
        } else {
            std::cout << "Некорректное расширение!\n";
        }
    }
    
    std::filesystem::path p(path_name);
    auto names = recursiveGetFileNamesByExtension(p, ext);

    if (names.size()) {
        std::cout << "\nПо вашему запросу найдены следующие файлы:\n";
        for (auto& name : names) {
            std::cout << "\t" << name << "\n";
        }
    } else {
        std::cout << "\nПо вашему запросу не найдено ни одного файла!\n";
    }
}
#endif

#ifdef __MODULE_19__
/* Задание 4. Разработка детектора PNG-файла
 *  Что нужно сделать
 *  Разработайте программу, которая получает на вход, в стандартный ввод, путь к файлу. На выходе
 *  программа должна определить, является ли данный файл PNG-изображением. Данная процедура не
 *  просто должна смотреть на расширение файла, но и произвести минимальный анализ его
 *  внутренностей, в бинарном режиме.
 *  Внутренности валидного бинарного файла начинаются со специального 8-байтового заголовка. Нас
 *  будут интересовать первые четыре байта. Первый байт всегда имеет значение −119 (число со знаком
 *  минус), а следующие — это просто символы ‘P’, ‘N’, ‘G’, расположенные друг за другом. Обратите
 *  внимание, что все они в верхнем регистре.
 *  По результатам проверки пути и внутренностей требуется сообщить пользователю о результате
 *  проверки в стандартный вывод.
 *  
 *  Советы и рекомендации:
 *  Чтобы определить расширение файла, используйте функцию substr, которая получает офсет и длину
 *  подстроки и возвращает её. */

#include <iostream>
#include <limits>
#include <fstream>
#include <cstring>
#include "Module_19.hpp"

static const char _PNG[] = { -119, 'P', 'N', 'G', '\0'};

static bool check_png_file(std::string filename) {
    std::ifstream file;
    file.open(filename, std::ios_base::binary);
    if (file.is_open()) {
        char buffer[5] = {0};
        int fn_size = filename.length();
        file.read(buffer, 4);
        
        // проверим, что расширение ввденного названия файла соответствует .png
        if (fn_size >= 5 && filename[fn_size - 1] == 'g' && filename[fn_size - 2] == 'n'
                         && filename[fn_size - 3] == 'p' && filename[fn_size - 4] == '.') {
            std::cout << "Файл имеет расширение .png!\n";
        } else {
            std::cout << "Файл не имеет расширение .png, но всё же проверим данные файла!\n";
        }

        // проверим, что в файле содержатся данные png-рисунка, начинающиеся с {-119, P, N, G}
        if (strcmp(_PNG, buffer) == 0) {
            std::cout << "Файл содержит данные, являющиеся PNG-рисунком!\n";
            return true;
        } else {
            std::cout << "Файл не является PNG-рисунком!\n";
            return false;
        }
    } else {
        std::cout << "File is not open!\n";
        return false;
    }

    return true;
}

void Task_19_4() {
    std::cout << equals << string_tasks[3] << equals;

    // очистка буфера ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string filename;
    std::cout << "Введите название файла для вывода данных: ";
    std::getline(std::cin, filename);

    check_png_file(filename);
}
#endif

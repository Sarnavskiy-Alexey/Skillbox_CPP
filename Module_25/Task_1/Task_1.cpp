#ifdef __MODULE_25__
/* Задание 1. Симулятор проведения операций
 *  Что нужно сделать
 *  Реализуйте простой симулятор проведения медицинской операции у пациента. Пользователь выступает
 *  в роли хирурга, который запрашивает инструменты у ассистента и применяет их сообразно ситуации.
 *  Пользователь взаимодействует с программой с помощью команд. Команды не имеют сложной встроенной
 *  логики: они просто принимают нужные данные в качестве аргументов и выводят сообщения в консоль о
 *  выполнении. Данные команд — это одна или две двумерные точки в формате double с координатами X и
 *  Y соответственно.
 *  Команда scalpel — принимает на вход две двумерные координаты начала и конца разреза или линии
 *  отсечения. При выполнении в консоль выводится сообщение о том, что был сделан разрез между
 *  введёнными координатами.
 *  Команда hemostat принимает на вход одну точку, в которой требуется сделать зажим, о чём также
 *  сообщает в консоль.
 *  Команда tweezers — пинцет, как и зажим, принимает одну точку для применения. Сообщение об этом
 *  выводится в консоль.
 *  Команда suture — хирургическая игла, которая делает шов между двумя указанными точками.
 *  Операция всегда начинается с команды scalpel и заканчивается командой suture. Для окончания
 *  работы программы их параметры-точки должны совпасть.
 *  Программу требуется реализовать именно с помощью одного заголовочного файла и одного файла с
 *  исходным кодом (CPP). В заголовочном файле должны находиться функции-инструменты. В основном
 *  файле — основная логика программы, обработка ввода пользователя.
 *  
 *  Советы и рекомендации
 *  - Создайте структуру с типом двумерной координаты (точки) вместе с набором функций для ввода
 *    этой координаты из консоли, её вывода в консоль и сравнения на предмет равенства. Для этих
 *    целей удобнее всего создать ещё один заголовочный файл.
 *  - Обратите внимание на порядок команд.
 *  - Заголовочные файлы с расширением .h следует расположить в папке include. Файлы исходного кода
 *    с расширением .cpp — в папке src. */

#include <sstream>
#include <limits>

#ifdef __CMAKELISTS__
// необходимо по условию и для корректной работы с CMake
#include "Module_25.hpp"
#else
// необходимо для удобной работы в vsc ()
#include "../Module_25.hpp"
#endif

#include "Task_1.hpp"

// массив строк с возможными операциями
const std::string operations[] = {
    "scalpel",
    "hemostat",
    "tweezers",
    "suture",
    "help"
};

// чтение операции с консоли
static void read_operation(std::stringstream& ss) {
    std::string buffer;
    std::cout << "Введите команду и необходимые параметры: ";
    std::getline(std::cin, buffer);

    ss.str(buffer);
}

// парсинг введенной операции
static S_Operation parse_operation(std::stringstream& ss) {
    S_Operation result = { E_Operation::error, 0.0, 0.0, 0.0, 0.0 };
    std::string operation;

    ss >> operation;
    if (operation == operations[(unsigned int)E_Operation::scalpel] ||
                operation == operations[(unsigned int)E_Operation::suture]) {
        if (!parse_coordinate(ss, result.coord1)) {
            result.operation_type = E_Operation::error;
        } else if (!parse_coordinate(ss, result.coord2)) {
            result.operation_type = E_Operation::error;
        } else {
            result.operation_type = (operation == operations[(unsigned int)E_Operation::scalpel]) ?
                                                    E_Operation::scalpel : E_Operation::suture;
        }
    } else if (operation == operations[(unsigned int)E_Operation::hemostat] ||
                operation == operations[(unsigned int)E_Operation::tweezers]) {
        if (!parse_coordinate(ss, result.coord1)) {
            result.operation_type = E_Operation::error;
        } else {
            result.operation_type = (operation == operations[(unsigned int)E_Operation::hemostat]) ?
                                                    E_Operation::hemostat : E_Operation::tweezers;
        }
    }

    // очистка потока для следующей команды
    ss.clear();

    return result;
}

void Task_25_1() {
    std::cout << equals << string_tasks[0] << equals;

    // объявление переменных
    std::stringstream buffer_stream;
    bool began = false, ended = false;

    // очистка буфера ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // основной цикл вызова операций
    do {
        S_Operation operation;

        read_operation(buffer_stream);
        operation = parse_operation(buffer_stream);

        if (operation.operation_type == E_Operation::scalpel && !began) {
            scalpel_func(operation);
            scalpel_operation = operation;
            began = true;
        } else if (operation.operation_type == E_Operation::hemostat && began) {
            hemostat_func(operation);
        } else if (operation.operation_type == E_Operation::tweezers && began) {
            tweezers_func(operation);
        } else if (operation.operation_type == E_Operation::suture && began &&
                   coord_equal(scalpel_operation.coord1, operation.coord1) &&
                   coord_equal(scalpel_operation.coord2, operation.coord2)) {
            suture_func(operation);
            ended = true;
        } else if (operation.operation_type == E_Operation::help) {
            std::cout << "\t\"scalpel x1 y1 x2 y2\" - скальпель и две двумерные координаты\n";
            std::cout << "\t\"hemostat x y\"        - зажим и одна двумерная координата\n";
            std::cout << "\t\"tweezers x y\"        - пинцет и одна двумерная координата\n";
            std::cout << "\t\"suture x1 y1 x2 y2\"  - хирургическая игла и две двухмерные координаты для сшивания\n";
            std::cout << "\t\"help\"                - вывод этого сообщения\n";
        } else {
            std::cout << "Ошибка в команде!\n";
        }
    } while (!ended);

    std::cout << "Хирургическая операция завершена!\n";
}

#endif

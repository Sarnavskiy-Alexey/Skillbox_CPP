#ifdef __MODULE_33__
/* Задание 2. Игра по ловле рыбы
 *  Что нужно сделать:
 *  Реализуйте простую игру-симуляцию ловли рыбы. Игровое поле представляет собой девять секторов
 *  условного пруда. В начале игры в одном из этих секторов с помощью генератора случайных чисел
 *  оказывается рыба. Точно так же, случайным образом, по секторам пруда распределяются и три
 *  сапога. Сапог и рыба при этом не могут находиться в одном и том же секторе одновременно, как и
 *  несколько сапог сразу в одном из секторов.
 *  Игрок закидывает удочку с приманкой в один из секторов, номер которого вводится стандартным
 *  способом через консоль. Задача игрока — угадать сектор, в котором находится рыба и, таким
 *  образом, поймать её. Если игрок попал на пустой сектор, то удочку надо забросить повторно. Если
 *  игрок поймал сапог, то игра завершается с отрицательным результатом.
 *  Реализовать задачу нужно с помощью исключений: когда успешный заброс удочки генерирует
 *  специальное пользовательское исключение, после чего программа должна завершиться и оповестить
 *  пользователя об успешной рыбалке и количестве попыток, которое ему для этого потребовалось. Если
 *  же был пойман сапог, то должно выводиться сообщение о неудачной ловле.
 *  
 *  Рекомендации:
 *  Вспомните, что вы можете выбросить в качестве исключения произвольный тип данных. Это может быть
 *  и сапог, и рыба.
 *  В функции main потребуется расположить рыбу случайным образом. Для этого сделайте
 *  std::srand(std::time(nullptr)); а затем само расположение:
 *  field[std::rand() % 9].fish = new Fish();
 *  Благодаря оператору % вы не выйдете за пределы массива.
 *  
 *  Что оценивается:
 *  Корректность работы игровой логики. Точность использования исключений. */

#include <iostream>
#include <exception>
#include <ctime>
#include <cassert>
#include "Module_33.hpp"
#include "Module_33_Exceptions.hpp"

#define SIZE 9
#define BOOTS 3

enum class Catch {
    nothing = 0,
    fish = 1,
    boot = 2,
};

static void try_catch_something(const Catch pond[SIZE]) {
    int pond_number;
    std::cout << "Введите номер пруда для попытки улова: ";
    std::cin >> pond_number;
    if (pond_number < 0 || pond_number >= SIZE) {
        throw PondNumberInvalidException();
    } else if (pond[pond_number] == Catch::nothing) {
        throw NothingInPondException();
    } else if (pond[pond_number] == Catch::boot) {
        throw BootInPondException();
    } else if (pond[pond_number] == Catch::fish) {
        throw FishInPondException();
    } else {
        throw std::exception();
    }
}

static int play(const Catch pond[SIZE]) {
    int tries = 0;
    while (true) {
        try {
            try_catch_something(pond);
        } catch (const PondNumberInvalidException& X) {
            std::cerr << X.what() << "\n";
        } catch (const NothingInPondException& X) {
            std::cerr << X.what() << "\n";
            ++tries;
        } catch (const BootInPondException& X) {
            std::cerr << X.what() << "\n";
            ++tries;
        } catch (const FishInPondException& X) {
            std::cerr << X.what() << "\n";
            ++tries;
            break;
        } catch (...) {
            std::cerr << "Какая-то ошибка..." << "\n";
            return -1;
        }
    }

    return tries;
}

void Task_33_2() {
    std::cout << equals << string_tasks[1] << equals;

    // проверяем, что define заданы правильно
    assert(SIZE > BOOTS && BOOTS > 0);

    Catch pond[SIZE]{};
    int counter = 0;
    int rand_num;
    int tries;
    
    std::srand(std::time(nullptr));
    pond[std::rand() % SIZE] = Catch::fish;

    while (counter < BOOTS) {
        rand_num = std::rand() % SIZE;
        if (pond[rand_num] == Catch::nothing) {
            pond[rand_num] = Catch::boot;
            counter++;
        }
    }

    tries = play(pond);
    if (tries == -1) {
        std::cout << "\n";
    } else {
        std::cout << "Для угадывания вам потребовалось: " << tries << " попыток(-а, -и)\n";
    }
}
#endif

#ifdef __MODULE_14__
/* Задание 8. Морской бой (дополнительное задание)
 *  Требуется реализовать упрощённую игру в морской бой. Игровое поле размером 10 на 10 клеток.
 *  Участвуют два игрока. В арсенале каждого из них 4 маленьких кораблика размером в одну клетку, 3
 *  небольших корабля размером в две клетки, 2 средних корабля размером в три клетки и один большой
 *  корабль размером в четыре клетки. Для простоты клетки поля пронумерованы по вертикали от 0 до 9
 *  и по горизонтали от 0 до 9. Мы не будем использовать классические наименования клеток, такие как
 *  B4, C6, а просто два индекса. Вначале игроки по очереди расставляют корабли, начиная с самых
 *  маленьких и заканчивая большими. Маленькие корабли в одну клетку расставляются с помощью
 *  указания одной клетки-точки на поле, к примеру 2,1. Корабли размерностью от двух клеток и выше
 *  расставляются с помощью координат их начала и конца, к примеру: 0,1–0,3. Корабли могут быть
 *  установлены только строго вертикально или горизонтально. Установка корабля по диагонали
 *  недопустима, об этом тоже надо сообщить пользователю. Если корабль не может быть размещён на
 *  заданных клетках из-за того, что он столкнётся с другим кораблём (окажется на его клетках) или
 *  выйдет за пределы поля, то игроку должно быть сделано предупреждение, после которого он должен
 *  переставить корабль на новые валидные координаты. В нашем упрощённом варианте игры мы не будем
 *  обсчитывать соприкосновения кораблей друг с другом, а потому корабли вполне можно будет
 *  размещать друг к другу вплотную, борт к борту. После того как все корабли расставлены,
 *  начинается игра. Игроки по очереди атакуют друг друга, называя координаты выстрела. После
 *  выстрела в консоль выводится информация о его результате: попал или мимо. Если выстрел успешен,
 *  клетка, на которой был корабль (или его фрагмент), затирается и становится пустой. Игра
 *  заканчивается тогда, когда все корабли одной из сторон будут полностью уничтожены. Как только
 *  это произойдёт, в консоль выводится информация с номером игрока, который победил.
 *  
 *  Советы и рекомендации:
 *  - Действия игроков практически одинаковые, их можно объединить в функции.
 *  - В программе достаточно иметь два поля, по одному на каждого игрока.
 *  - Лучше создать три отдельные функции: одну для размещения одного корабля, еще одну как обёртку
 *    над первой (она будет размещать все корабли), а третью для удара по координате. Также вам
 *    потребуются два глобальных массива для двух отдельных участков моря:
 *    bool field_1[10][10]; 
 *    bool field_2[10][10];
 *  
 *  Что оценивается:
 *  - Корабли расставляются правильно.
 *  - Есть возможность выиграть.
 *  - Реализован понятный и удобный для пользователя интерфейс игры. */

#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#endif
#include "Module_14.hpp"

// функция изменения цвета символов в консоли
static void changeColor(int color) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
#endif
}

// вывод на экран одного поля для игры
static void print_field(char field[10][10]) {
    changeColor(15);
    std::cout << "y\\x   0   1   2   3   4   5   6   7   8   9\n";
    std::cout << "    -----------------------------------------\n";
    for (int i = 0; i < 10; i++) {
        changeColor(15);
        std::cout << " " << i << " ";
        for (int j = 0; j < 10; j++) {
            changeColor(15);
            std::cout << " | ";
            changeColor((int)(field[i][j]) - 40);
            std::cout << field[i][j];
        }
        changeColor(15);
        std::cout << " |\n";
        std::cout << "    -----------------------------------------\n";
    }
}

// вывод на экран полей для игры с учетом того, что вражеское поле не должно отображаться полностью
static void print_fields(char fieldPlayer[10][10], char fieldEnemy[10][10]) {
    changeColor(15);
    std::cout << "y\\x   0   1   2   3   4   5   6   7   8   9      "
              << "y\\x   0   1   2   3   4   5   6   7   8   9\n";
    std::cout << "    -----------------------------------------        "
              << "-----------------------------------------\n";
    for (int i = 0; i < 10; i++) {
        changeColor(15);
        std::cout << " " << i << " ";
        for (int j = 0; j < 10; j++) {
            changeColor(15);
            std::cout << " | ";
            if (fieldPlayer[i][j] == 'X')
                changeColor(13);
            else if (fieldPlayer[i][j] == 'O')
                changeColor(14);
            else
                changeColor((int)(fieldPlayer[i][j]) - 40);
            std::cout << fieldPlayer[i][j];
        }
        std::cout << " | ";
        std::cout << "    " << i << " ";
        for (int j = 0; j < 10; j++) {
            changeColor(15);
            std::cout << " | ";
            if (fieldEnemy[i][j] == 'X') {
                changeColor(13);
                std::cout << fieldEnemy[i][j];
            } else if (fieldEnemy[i][j] == 'O') {
                changeColor(14);
                std::cout << fieldEnemy[i][j];
            } else {
                std::cout << ' ';
            }
        }
        changeColor(15);
        std::cout << " | \n";
        std::cout << "    -----------------------------------------        "
                  << "-----------------------------------------\n";
    }
    std::cout << "\n";
}

// безопасный ввод координаты
static int safe_enter(std::string invite_str, std::string error_str) {
    int X;
    do {
        std::cout << invite_str;
        std::cin >> X;
        if (X < 0 || X > 9)
            std::cout << error_str;
    } while (X < 0 || X > 9);
    
    return X;
}

// получение одного корабля заданного размера
static void get_ship(char field[10][10], int shipSize) {
    if (shipSize == 1) {
        int X, Y;
        do {
            X = safe_enter("Введите координату X 1-палубного корабля: ",
                           "ОШИБКА! Координата за пределами карты!\n");
            Y = safe_enter("Введите координату Y 1-палубного корабля: ",
                           "ОШИБКА! Координата за пределами карты!\n");
            if (field[Y][X] != ' ')
                std::cout << "Координата уже занята! Переставьте корабль в другое место!\n";
        } while (field[Y][X] != ' ');
        field[Y][X] = '1';
    } else {
        int X1, Y1, X2, Y2;
        bool check;
        do {
            check = true;
            X1 = safe_enter("Введите координату X1 " + std::to_string(shipSize) +
                                                                              "-палубного корабля: ",
                           "ОШИБКА! Координата за пределами карты!\n");
            Y1 = safe_enter("Введите координату Y1 " + std::to_string(shipSize) +
                                                                              "-палубного корабля: ",
                           "ОШИБКА! Координата за пределами карты!\n");
            X2 = safe_enter("Введите координату X2 " + std::to_string(shipSize) +
                                                                              "-палубного корабля: ",
                           "ОШИБКА! Координата за пределами карты!\n");
            Y2 = safe_enter("Введите координату Y2 " + std::to_string(shipSize) +
                                                                              "-палубного корабля: ",
                           "ОШИБКА! Координата за пределами карты!\n");
            
            // проверка возможности заполнения кораблем по указанным координатам
            if (X1 == X2 && abs(Y1 - Y2) == shipSize - 1) {
                for (int y = (Y1 < Y2 ? Y1 : Y2); y <= (Y1 > Y2 ? Y1 : Y2); y++)
                    if (field[y][X1] != ' ')
                        check = false;
            } else if (Y1 == Y2 && abs(X1 - X2) == shipSize - 1) {
                for (int x = (X1 < X2 ? X1 : X2); x <= (X1 > X2 ? X1 : X2); x++)
                    if (field[Y1][x] != ' ')
                        check = false;
            } else
                check = false;

            // в случае ошибки 
            if (!check)
                std::cout << "Координаты не доступны! Переставьте корабль в другое место!\n";
        } while (!check);

        if (X1 == X2)
            for (int y = (Y1 < Y2 ? Y1 : Y2); y <= (Y1 > Y2 ? Y1 : Y2); y++)
                field[y][X1] = char(48 + shipSize);
        else if (Y1 == Y2)
            for (int x = (X1 < X2 ? X1 : X2); x <= (X1 > X2 ? X1 : X2); x++)
                field[Y1][x] = char(48 + shipSize);
    }
}

// процесс получения всех кораблей на одно поле
static void get_ships(char field[10][10]) {
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j <= 4 - i; j++) {
            print_field(field);
            get_ship(field, i);
        }
    }
    print_field(field);
}

// инициализация поля для игры пустыми клетками (пробелами)
static void init_field(char field[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            field[i][j] = ' ';
        }
    }
}

static bool make_turn(char fieldPlayer[10][10], char fieldEnemy[10][10]) {
    int X, Y;
    bool check;
    do {
        check = true;
        X = safe_enter("Введите координату X противника для удара: ",
                           "ОШИБКА! Координата за пределами карты!\n");
        Y = safe_enter("Введите координату Y противника для удара: ",
                           "ОШИБКА! Координата за пределами карты!\n");
        if (fieldEnemy[Y][X] == 'X' || fieldEnemy[Y][X] == 'O') {
            check = false;
            std::cout << "Данная клетка уже была вами поражена! Попробуйте другую!\n";
        }
    } while (!check);

    if (fieldEnemy[Y][X] == ' ') {
        fieldEnemy[Y][X] = 'O';
        changeColor(12);
        std::cout << "Мимо! Ход переходит вашему сопернику!\n";
        changeColor(15);
        return false;
    } else {
        fieldEnemy[Y][X] = 'X';
        changeColor(10);
        std::cout << "Попадание! Продолжайте ход!\n";
        changeColor(15);
        return true;
    }
}

static int check_game_over(char field1[10][10], char field2[10][10]) {
    bool field1_lose = true;
    bool field2_lose = true;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (field1[i][j] == '1' || field1[i][j] == '2' ||
                field1[i][j] == '3' || field1[i][j] == '4') {
                field1_lose = false;
                break;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (field2[i][j] == '1' || field2[i][j] == '2' ||
                field2[i][j] == '3' || field2[i][j] == '4') {
                field2_lose = false;
                break;
            }
        }
    }
    if (field1_lose) return 2;
    else if (field2_lose) return 1;
    else return 0;
}

void Task_14_8() {
    std::cout << equals << string_tasks[7] << equals;

    char field_1[10][10], field_2[10][10];
    init_field(field_1);
    init_field(field_2);

    get_ships(field_1);
    get_ships(field_2);

    int EOG;
    bool turn = true;
    bool prev_turn = false;
    do {
        if (prev_turn != turn) {
            if (turn) std::cout << "\nИгрок 1 должен отвернуться!\n\n";
            else std::cout << "\nИгрок 2 должен отвернуться!\n\n";
            
            /* В терминале VS code функция работает некорректно, но возможно в других
             *  IDE будет работать лучше */
            // system("pause");

            for (int i = 0 ; i < 50; i++)
                std::cout << "\n";
        }
        prev_turn = turn;
        if (turn) {
            print_fields(field_1, field_2);
            std::cout << "Ход за 1 игроком!\n";
            turn = ((int)(make_turn(field_1, field_2))) % 2;
        } else {
            print_fields(field_2, field_1);
            std::cout << "Ход за 2 игроком!\n";
            turn = ((int)(make_turn(field_2, field_1)) + 1) % 2;
        }
        EOG = check_game_over(field_1, field_2);
    } while (!EOG);
    std::cout << "Игра окончена! ";
    if (EOG == 1) std::cout << "Победитель 1 игрок!";
    else std::cout << "Победитель 2 игрок!";
    std::cout << " Поздравляем!\n";
}
#endif

#ifdef __MODULE_14__
/* Задание 2. Крестики-нолики
 *  Что нужно сделать:
 *  Старая добрая игра на страницах всех школьных тетрадей. Поле размером 3 × 3 представлено в виде
 *  двумерного массива с типом элементов char. Участвуют два игрока, они ходят по очереди и ставят в
 *  указанные ими в стандартном вводе координаты свой символ — X или O (буквы латинского алфавита).
 *  Как только у одного из игроков будет установлено подряд три крестика или три нолика, он
 *  побеждает. Если свободных клеток не осталось, а трёх совпадающих элементов не найдено, то
 *  объявляется ничья. Для простоты не будем рассматривать диагональные совпадения — только строго
 *  вертикальные и строго горизонтальные.
 *  Изначально всё поле инициализируется символом пробела — ‘ ‘(для обозначения пробела кавычки
 *  одинарные и в одну сторону). Это можно сделать сразу при объявлении либо с помощью вложенного
 *  цикла. На каждом ходе при занятой клетке или при неверных координатах этой клетки должно быть
 *  выведено сообщение, и игрок должен указать координаты клетки повторно. После каждого хода надо
 *  выводить в консоль текущее состояние всего игрового поля для наглядности.
 *  
 *  Советы и рекомендации:
 *  - Действия для обоих игроков одинаковые, отличаются только символом, который ставится на поле.
 *  - Игровой цикл не должен быть бесконечным. Игра имеет определённое максимальное количество шагов.
 *  - Не забывайте про случай ничьей.
 *  - Как и в предыдущем задании, здесь будет удобно сразу заполнить массив значениями false.
 *    Количество мест, доступных для заполнения, заранее известно. В процессе заполнения из этой
 *    переменой нужно не забывать вычитать единицу. Чтобы отметить место как занятое, нужно лишь
 *    написать places[i][j] = true;.
 *  - Проверку на победу игрока, которую надо осуществлять после каждого хода, можно сделать с
 *    помощью вложенного цикла, сразу проверяя и вертикаль, и горизонталь, а как именно — попробуйте
 *    догадаться сами.
 *  - Здесь заранее известно число ходов — 3 * 3. Столько раз должен быть выполнен цикл, который
 *    спрашивает у очередного игрока координаты.
 *  - Символ, который будет установлен в указанных координатах, можно на каждом шаге менять подобным
 *    образом:
 *                        if (gamer_name == 'X') 
 *                            gamer_name = 'O'; 
 *                        else 
 *                            gamer_name = 'X';
 *  
 *  Что оценивается:
 *  - Корректный ход игры, соответствующий правилам.
 *  - Правильный (желательно красивый) вывод игрового поля.
 *  - Понятный игроку интерфейс. */

#include <iostream>
#include "Module_14.hpp"

// безопасный ввод координаты
static int safe_enter(std::string invite_str, std::string error_str) {
    int X;
    do {
        std::cout << invite_str;
        std::cin >> X;
        if (X <= 0 || X > 3)
            std::cout << error_str;
    } while (X <= 0 || X > 3);
    
    return X;
}

// вывод на экран игрового поля
static void print_field(char field[][3]) {
    std::cout << "y\\x   1   2   3\n";
    std::cout << "    -------------\n";
    for (int i = 0; i < 3; i++) {
        std::cout << " " << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            std::cout << " | " << field[i][j];
        }
        std::cout << " |\n";
        std::cout << "    -------------\n";
    }
}

void Task_14_2() {
    std::cout << equals << string_tasks[1] << equals;

    char field[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    int turns = 0;
    bool X_winner = false;
    bool O_winner = false;

    print_field(field);
    
    while (turns < 9) {
        int coord_x, coord_y;

        do {
            coord_x = safe_enter("Введите индекс по оси X (вправо): ",
                                 "Ошибка! Индекс должен быть в пределах от 1 до 3!\n");
            coord_y = safe_enter("Введите индекс по оси Y (вниз): ",
                                 "Ошибка! Индекс должен быть в пределах от 1 до 3!\n");
            if (field[coord_y - 1][coord_x - 1] != ' ') {
                std::cout << "Ошибка! Клетка занята! Попробуйте заново!\n";
            }
        } while (field[coord_y - 1][coord_x - 1] != ' ');
        
        field[coord_y - 1][coord_x - 1] = (turns % 2) ? 'O' : 'X';

        if (turns < 5) {
            for (int i = 0; i < 3; i++) {
                if (field[i][0] != ' ' && field[i][0] == field[i][1] && field[i][1] == field[i][2]) {
                    if (field[i][0] == 'X') X_winner = true;
                    else                    O_winner = true;
                    break;
                }
                if (field[0][i] != ' ' && field[0][i] == field[1][i] && field[1][i] == field[2][i]) {
                    if (field[0][i] == 'X') X_winner = true;
                    else                    O_winner = true;
                    break;
                }
            }
        }

        print_field(field);

        if (X_winner || O_winner) break;
        else                      turns++;

        std::cout << "\n";
    }

    if (X_winner) std::cout << "X выиграли!\n";
    else if (O_winner) std::cout << "O выиграли!\n";
    else std::cout << "Ничья!\n";
}
#endif

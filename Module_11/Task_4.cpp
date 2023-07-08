/* Задание 4. Оценка результатов игры в крестики-нолики
 *  Петя и Вася играли в крестики-нолики и не стёрли результаты своей игры. Теперь перед вами
 *  табличка 3 × 3, которая осталась после их поединка. Вы хотите понять, выиграл ли кто-то из них
 *  или они не доиграли.
 *  На вход программе даётся три строки, кодирующие верхнюю, среднюю и нижнюю строчки игрового поля.
 *  Крестик обозначается символом X (английская заглавная буква X), нолик — символом O (заглавная
 *  английская буква O), пустая клетка — точкой.
 *  Если ввод некорректен, то есть такая таблица не могла получиться в ходе настоящей игры, то надо
 *  написать в ответ слово Incorrect.
 *  Если таблица корректна и выиграли крестики, то нужно вывести в ответ слова Petya won, если
 *  нолики — Vanya won, иначе (то есть они не доиграли или сыграли вничью) надо написать Nobody. */

#include <iostream>
#include "Module_11.hpp"

// получение элемента по координатам
static char get_element(std::string strUp, std::string strMid, std::string strDown, int X, int Y) {
    if (X == 0)      return strUp[Y];
    else if (X == 1) return strMid[Y];
    else             return strDown[Y];
}

// проверка трех символов на совпадение
// возвращает 0 - нет совпадений, 1 - совпадение по X, 2 - совпадение по O
static int check_result(char first, char second, char third) {
    if (first == second && second == third) {
        if (first == 'X') return 1;
        else if (first == 'O') return 2;
    }
    return 0;
}

// проверка на победителей
// возвращает -1 - ошибка, 0 - нет победителей, 1 - победитель Петя, 2 - победитель Ваня
static int check_results(std::string strUp, std::string strMid, std::string strDown) {
    int checked, winner;

    // проверка основной диагонали
    checked = check_result(get_element(strUp, strMid, strDown, 0, 0),
                           get_element(strUp, strMid, strDown, 1, 1),
                           get_element(strUp, strMid, strDown, 2, 2));
    winner = checked;

    // проверка побочной диагонали
    checked = check_result(get_element(strUp, strMid, strDown, 2, 0),
                           get_element(strUp, strMid, strDown, 1, 1),
                           get_element(strUp, strMid, strDown, 0, 2));
    if (!winner) winner = checked;
    else if (winner != checked && checked != 0) return -1;
    
    // проверка каждой строки и каждого столбца
    for (int i = 0; i < 3; i++) {
        checked = check_result(get_element(strUp, strMid, strDown, i, 0),
                               get_element(strUp, strMid, strDown, i, 1),
                               get_element(strUp, strMid, strDown, i, 2));
        if (!winner) winner = checked;
        else if (winner != checked && checked != 0) return -1;
        
        checked = check_result(get_element(strUp, strMid, strDown, 0, i),
                               get_element(strUp, strMid, strDown, 1, i),
                               get_element(strUp, strMid, strDown, 2, i));
        if (!winner) winner = checked;
        else if (winner != checked && checked != 0) return -1;
    }

    return winner;
}

// проверка корректности заполнения поля для игры
static int check_correctness(std::string strUp, std::string strMid, std::string strDown) {
    int countX = 0, countO = 0;
    
    // подсчет количества крестиков и ноликов
    for (int i = 0; i < 3; i++) {
        if (strUp[i] == 'X')      countX++;
        else if (strUp[i] == 'O') countO++;
        if (strMid[i] == 'X')      countX++;
        else if (strMid[i] == 'O') countO++;
        if (strDown[i] == 'X')      countX++;
        else if (strDown[i] == 'O') countO++;
    }
    
    // ошибка, если разница между количеством крестиков и ноликов меньше нуля или больше единицы
    if (countX - countO != 1 && countX != countO)
        return -1;

    // проверка результата игры
    switch (check_results(strUp, strMid, strDown)) {
        case 0: return 0;
        case 1: if (countX - countO != 1) return -1; return 1;
        case 2: if (countX != countO) return -1; return 2;
        default: return -1;
    }
}

// проверка результатов игры
static std::string check_game(std::string strUp, std::string strMid, std::string strDown) {
    switch (check_correctness(strUp, strMid, strDown)) {
        case 0:  return "Nobody";
        case 1:  return "Petya won";
        case 2:  return "Vanya won";
        default: return "Incorrect";
    }
}

// функция для безопасного ввода строки Крестиков-Ноликов
static std::string safe_cin(std::string message) {
    std::string str, dict = "XO.";
    bool correctStr;
    
    // безопасный ввод строки поединка
    do {
        correctStr = true;
        std::cout << message;
        std::cin >> str;
        if (str.length() != 3) {
            std::cout << "На строчку из Крестиков-Ноликов 3х3 не похоже!\n";
            correctStr = false;
        }
        if (correctStr)
            for (unsigned int i = 0; i < str.length(); i++)
                if (dict.find(str[i]) == std::string::npos) {
                    std::cout << "В строке присутствуют лишние символы!\n";
                    correctStr = false;
                    break;
                }
    } while (!correctStr);

    return str;
}

void Task_11_4() {
    std::cout << equals << string_tasks[3] << equals;
    
    std::string strUp   = safe_cin("Введите верхнюю строчку поединка: ");
    std::string strMid  = safe_cin("Введите среднюю строчку поединка: ");
    std::string strDown = safe_cin("Введите нижнюю строчку поединка:  ");
    
    std::cout << check_game(strUp, strMid, strDown) << "\n";
}

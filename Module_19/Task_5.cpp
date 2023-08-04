// #ifdef __MODULE_19__
/* Задание 5. Реализация игры «Что? Где? Когда?»
 *  Что нужно сделать
 *  Реализуйте простую версию интеллектуальной игры «Что? Где? Когда?». 
 *  
 *  Как происходит игра:
 *  В начале каждого хода игроки вращают волчок, то есть выбирают сектор на столе, который сейчас
 *  играет. Всего таких секторов 13. Сектор выбирается так: с клавиатуры вводится офсет (смещение)
 *  относительно текущего сектора на барабане. Исходя из этого офсета вычисляется новый активный
 *  сектор, который и будет играть в этом ходе. Если выпавший сектор уже играл, выбирает следующий
 *  неигравший за ним. В начале всей игры стрелка установлена на первом секторе.
 *  Как только играет какой-то из секторов, с него берётся письмо с вопросом — то есть считывается
 *  из файла данного сектора. Вопрос показывается на экране.
 *  После того как вопрос показан, от игрока ожидается ответ на него. Игрок вводит этот ответ с
 *  помощью стандартного ввода. То, что он ввёл, сравнивается с ответом, который хранится во втором
 *  файле, ассоциированном с активным сектором. Данный файл должен содержать лишь одно слово-ответ.
 *  Если ответ знатока-игрока был правильным, ему начисляется один балл. Если неверен, то балл
 *  уходит телезрителям.
 *  Игра продолжается до тех пор, пока или игрок, или зрители не наберут шесть баллов. После этого
 *  называется победитель и программа заканчивает работу. */

#include <iostream>
#include <fstream>
#include <string>

#ifdef _WIN32
#include <Windows.h>
#endif

#include "Module_19.hpp"

static const std::string filename = CUR_DIR + DOCS_DIR + "www.txt";

// функция изменения цвета символов в консоли
static void changeColor(int color) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
#endif
}

// получение номера вопроса по оффсету
static unsigned int get_question_number(bool* const played_sectors, const unsigned int offset) {
    unsigned int idx = offset % 13;
    while (played_sectors[idx])
        idx = (idx + 1) % 13;
    played_sectors[idx] = true;
    return idx;
}

// получение вопроса и ответа из файла
static bool get_question_from_file(std::string& question, std::string& answer, unsigned int q_n) {
    std::ifstream file;
    file.open(filename);
    if (file.is_open()) {
        unsigned int counter = 0;
        while (!file.eof() && counter <= q_n) {
            std::getline(file, question);
            std::getline(file, answer);
            counter++;
        }
        return false;
    } else {
        std::cout << "File is not found!\n";
        return true;
    }
}

void Task_19_5() {
    std::cout << equals << string_tasks[4] << equals;

    bool playedSectors[13] = { 0 };
    int playerScore = 0, tvScore = 0;
    unsigned int offset;
    unsigned int question_number;
    std::string question, answer, playerAnswer;
    bool error_status;

    while (playerScore < 6 && tvScore < 6) {
        std::cout << "Введите оффсет (положительное число): ";
        std::cin >> offset;

        question_number = get_question_number(playedSectors, offset);
        error_status = get_question_from_file(question, answer, question_number);
        if (!error_status) {
            std::cout << "Внимание вопрос!\n\t" << question << "\nВаш ответ:\n\t";
            std::cin >> playerAnswer;

            // анализируем ответ игроков
            if (playerAnswer == answer) {
                changeColor(10);
                playerScore++;
                std::cout << "Верно! ";
            } else {
                changeColor(12);
                tvScore++;
                std::cout << "Неверно! Правильный ответ:\n\t" << answer << "\n";
            }
            
            // выводим текущие результаты игры
            changeColor(15);
            if (playerScore > tvScore)
                std::cout << "Счет " << playerScore << ":" << tvScore << " в пользу знатоков!\n";
            else if (playerScore < tvScore)
                std::cout << "Счет " << tvScore << ":" << playerScore << " в пользу телезрителей!\n";
            else
                std::cout << "Счет равный, " << tvScore << ":" << playerScore << "!\n";
        } else {
            changeColor(12);
            std::cout << "Продолжение игры невозможно!\n";
            changeColor(15);
            break;
        }
    }
    if (playerScore == 6)
        std::cout << "Игроки выиграли! Поздравляем! Ждите хрустальную сову по почте!\n";
    else if (tvScore == 6)
        std::cout << "Телезрители победили! Молодцы! Хорошие вопросы!\n";
    else
        std::cout << "Игра прервана!\n";
}
// #endif

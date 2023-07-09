#ifdef __MODULE_09__
/* Задание 4. «Быки и коровы» (дополнительное задание)
 *  В логической игре «Быки и коровы» первый игрок загадывает четырёхзначное число (оно может
 *  начинаться и с нулей), а второй игрок должен его отгадать.
 *  Отгадывание происходит так: второй игрок называет любое четырёхзначное число, а первый ему
 *  отвечает, сколько в этом числе «быков» и сколько «коров».
 *  «Корова» — это цифра, которая совпадает по значению с какой-то из цифр задуманного числа, но
 *  не стоит на нужном месте. «Бык» — это цифра, совпадающая с цифрой в задуманном числе и по
 *  значению, и по расположению.
 *  Напишите программу, которая по загаданному числу и по названному вторым игроком числу
 *  определяет, сколько во втором числе «быков» и сколько «коров». Не забудьте, что числа могут
 *  начинаться с нулей! */

#include <iostream>
#include "Module_09.hpp"

void Task_09_4() {
    std::cout << equals << string_tasks[3] << equals;

    std::string hiddenNumber, guessedNumber;
    int bulls, cows, tries = 0;
    int rightNumber;
    
    // безопасный ввод четырехзначного числа первым игроком
    do {
        rightNumber = 1;
        std::cout << "Загадайте четырехзначное число: ";
        std::cin >> hiddenNumber;
        if (hiddenNumber.length() != 4) {
            std::cout << "ОШИБКА! Необходимо вводить (!)4 цифры!\n";
            rightNumber = 0;
            continue;
        }
        for (int i = 0; i < 4; i++) {
            if (hiddenNumber[i] < '0' || hiddenNumber[i] > '9') {
                rightNumber = 0;
                break;
            }
        }
        if (!rightNumber)
            std::cout << "ОШИБКА! Необходимо загадать (!)число!\n";
    } while (!rightNumber);

    //system("cls");
    for (int i = 0; i < 51; i++, std::cout << "\n");
    std::cout << "\aХод передается второму игроку! Отгадывайте число!\n";

    // цикл отгадывания числа
    do {
        // безопасный ввод четырехзначного числа вторым игроком
        do {
            rightNumber = 1;
            std::cout << "Введите четырехзначное число: ";
            std::cin >> guessedNumber;
            if (guessedNumber.length() != 4) {
                std::cout << "ОШИБКА! Необходимо вводить (!)4 цифры!\n";
                rightNumber = 0;
                continue;
            }
            for (int i = 0; i < 4; i++) {
                if (guessedNumber[i] < '0' || guessedNumber[i] > '9') {
                    rightNumber = 0;
                    break;
                }
            }
            if (!rightNumber)
                std::cout << "ОШИБКА! Необходимо отгадать (!)число!\n";
        } while (!rightNumber);

        bulls = cows = 0;
        for (int i = 0; i < 4; i++) {
            if (guessedNumber[i] == hiddenNumber[i])
                bulls++;
            else {
                for (int j = 0; j < 4; j++)
                    if (guessedNumber[j] != hiddenNumber[j] && guessedNumber[i] == hiddenNumber[j]) {
                        cows++;
                        break;
                    }
            }
        }
        std::cout << "Быки: " << bulls << " Коровы: " << cows << "\n";

        tries++;
    } while (hiddenNumber != guessedNumber);

    std::cout << "Игра окончена! Вы отгадали загаданное число на " << tries << "-й ход.\n";
}
#endif

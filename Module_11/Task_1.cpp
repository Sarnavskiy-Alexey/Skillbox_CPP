/* Задание 1. Шифр Цезаря
 *  В древности для шифрования сообщений использовался такой способ: все буквы в сообщении
 *  сдвигались на одно и то же число позиций в алфавите. Число позиций могло быть как положительным,
 *  так и отрицательным и являлось параметром шифра — его ключом. Если для сдвига на данное число
 *  позиций алфавита не хватает, то он зацикливается (то есть буква с номером 27 — это снова буква
 *  a, буква с номером 28 — это буква b и так далее).
 *  Например, слово abracadabra при сдвиге на десять позиций превратится в klbkmknklbk. Этот
 *  простейший шифр называется шифром Цезаря. Регистр букв (заглавные и строчные) менять не нужно.
 *  Напишите функцию encrypt_caesar от строки и числа, которая возвращает исходную строку,
 *  зашифрованную шифром Цезаря с параметром, равным данному числу. Также напишите функцию
 *  decrypt_caesar, выполняющую обратное преобразование. Считаем, что входные строки состоят лишь из
 *  английских букв. Если там содержатся и другие символы, то их надо игнорировать. */

#include <iostream>
#include <limits>
#include "Module_11.hpp"

static std::string encrypt_caesar(std::string decrypted_str, int offset) {
    std::string result;

    // изменение сдвига в пределах от 0 до 26
    // взятие модуля от числа может оставлять отрицательные значения
    offset = ((offset % 26) + 26) % 26;
    for (unsigned int i = 0; i < decrypted_str.length(); i++) {
        if (decrypted_str[i] >= 'a' && decrypted_str[i] <= 'z') {
            result += (decrypted_str[i] + offset - 97) % 26 + 97;
        } else if (decrypted_str[i] >= 'A' && decrypted_str[i] <= 'Z') {
            result += (decrypted_str[i] + offset - 65) % 26 + 65;
        }
    }
    return result;
}

static std::string decrypt_caesar(std::string encrypted_str, int offset) {
    return encrypt_caesar(encrypted_str, -offset);
}

void Task_11_1() {
    std::cout << equals << string_tasks[0] << equals;
    
    // очистка буфера ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string str;
    int offset;
    std::cout << "Введите строку для шифровки: ";
    std::getline(std::cin, str);
    std::cout << "Введите сдвиг: ";
    std::cin >> offset;

    std::cout << "Зашифрованная строка: " << encrypt_caesar(str, offset) << "\n";

    std::cout << "---------------------\n";
    
    // очистка буфера ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Введите строку для дешифровки: ";
    std::getline(std::cin, str);
    std::cout << "Введите сдвиг, с которым предположительно была проведена шифровка: ";
    std::cin >> offset;

    std::cout << "Дешифрованная строка: " << decrypt_caesar(str, offset) << "\n";
}

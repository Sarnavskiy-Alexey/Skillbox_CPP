#ifdef __MODULE_11__
/* Задание 2. Проверка корректности email-адреса
 *  Напишите программу, которая проверяет корректность email-адреса, введённого пользователем.
 *  Согласно международным требованиям, корректный email-адрес должен состоять из двух частей,
 *  разделённых знаком @. Первая часть должна иметь длину не менее одного и не более 64 символов,
 *  вторая часть — не менее одного и не более 63 символов. Из символов допускаются только английские
 *  буквы, цифры и знак «-» (дефис), а также точка. Точка не может быть первым или последним
 *  символом, а кроме того, две точки не могут идти подряд. В первой части (которая предшествует
 *  символу @), кроме вышеперечисленных, разрешены ещё следующие символы:
 *  !#$%&'*+-/=?^_`{|}~
 *  Пользователь вводит строку, задающую email-адрес. Программа должна вывести слово Yes, если адрес
 *  корректен, а в противном случае — слово No. */

#include <iostream>
#include <limits>
#include "Module_11.hpp"

static std::string unrestricted_dict(bool fp_or_sp_email) {
    std::string dict = "-.";
    for (char c = 'A'; c <= 'Z'; c++) dict+= c;
    for (char c = 'a'; c <= 'z'; c++) dict+= c;
    for (char c = '0'; c <= '9'; c++) dict+= c;
    // если этот флаг true - значит словарь определяется для первой части email, иначе - для второй
    if (fp_or_sp_email)
        dict += "!#$%&'*+/=?^_`{|}~";
    return dict;
}

static bool check_first_part_email(std::string fp_email) {
    std::string dict = unrestricted_dict(true);
    if (fp_email.length() == 0 || fp_email.length() > 64 ||
        fp_email[0] == '.' || fp_email[fp_email.length() - 1] == '.' ||
        fp_email.find("..") != std::string::npos)
        return false;
    for (unsigned int i = 0; i < fp_email.length(); i++) {
        if (dict.find(fp_email[i]) == std::string::npos) return false;
    }
    return true;
}

static bool check_second_part_email(std::string sp_email) {
    std::string dict = unrestricted_dict(false);
    if (sp_email.length() == 0 || sp_email.length() > 63 ||
        sp_email[0] == '.' || sp_email[sp_email.length() - 1] == '.' ||
        sp_email.find("..") != std::string::npos)
        return false;
    for (unsigned int i = 0; i < sp_email.length(); i++) {
        if (dict.find(sp_email[i]) == std::string::npos) return false;
    }
    return true;
}

static bool check_email(std::string email) {
    if (email.find('@') < email.length())
        return check_first_part_email(email.substr(0, email.find('@'))) &&
               check_second_part_email(email.substr(email.find('@') + 1));
    else
        return false;
}

void Task_11_2() {
    std::cout << equals << string_tasks[1] << equals;
    
    // очистка буфера ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string str;
    std::cout << "Введите email для проверки: ";
    std::getline(std::cin, str);

    std::cout << (check_email(str) ? "Yes" : "No") << "\n";
}
#endif

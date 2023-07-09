#ifdef __MODULE_11__
#pragma once

const std::string string_tasks[] = {
    "\t\t\tЗадание 1. Шифр Цезаря\n  В древности для шифрования сообщений использовался такой способ: все буквы в сообщении сдвигались на одно и то же число позиций в алфавите. Число позиций могло быть как положительным, так и отрицательным и являлось параметром шифра — его ключом. Если для сдвига на данное число позиций алфавита не хватает, то он зацикливается (то есть буква с номером 27 — это снова буква a, буква с номером 28 — это буква b и так далее).\n  Например, слово abracadabra при сдвиге на десять позиций превратится в klbkmknklbk. Этот простейший шифр называется шифром Цезаря. Регистр букв (заглавные и строчные) менять не нужно. Напишите функцию encrypt_caesar от строки и числа, которая возвращает исходную строку, зашифрованную шифром Цезаря с параметром, равным данному числу. Также напишите функцию decrypt_caesar, выполняющую обратное преобразование. Считаем, что входные строки состоят лишь из английских букв. Если там содержатся и другие символы, то их надо игнорировать.\n",
    "\t\t\tЗадание 2. Проверка корректности email-адреса\n  Напишите программу, которая проверяет корректность email-адреса, введённого пользователем.\n  Согласно международным требованиям, корректный email-адрес должен состоять из двух частей, разделённых знаком @. Первая часть должна иметь длину не менее одного и не более 64 символов, вторая часть — не менее одного и не более 63 символов. Из символов допускаются только английские буквы, цифры и знак «-» (дефис), а также точка. Точка не может быть первым или последним символом, а кроме того, две точки не могут идти подряд. В первой части (которая предшествует символу @), кроме вышеперечисленных, разрешены ещё следующие символы:\n  !#$%&'*+-/=?^_`{|}~\n  Пользователь вводит строку, задающую email-адрес. Программа должна вывести слово Yes, если адрес корректен, а в противном случае — слово No.\n",
    "\t\t\tЗадание 3. Валидация IP-адреса\n  Проверьте, задаёт ли введённая пользователем строка корректный IP-адрес четвёртой версии (IPv4). IP-адрес должен представлять из себя четыре числа, разделённые точками без пробелов, причём каждое число должно быть в диапазоне от 0 до 255 включительно. Числа не должны содержать ведущих нулей. Других символов в строке, кроме вышеописанных, быть не должно.\n  Пользователь вводит строку, задающую IP-адрес через стандартный ввод. В результате программа должна вывести слово Valid, если адрес корректен, и слово Invalid, если это не так.\n",
    "\t\t\tЗадание 4. Оценка результатов игры в крестики-нолики\n  Петя и Вася играли в крестики-нолики и не стёрли результаты своей игры. Теперь перед вами табличка 3 × 3, которая осталась после их поединка. Вы хотите понять, выиграл ли кто-то из них или они не доиграли.\n  На вход программе даётся три строки, кодирующие верхнюю, среднюю и нижнюю строчки игрового поля. Крестик обозначается символом X (английская заглавная буква X), нолик — символом O (заглавная английская буква O), пустая клетка — точкой.\n  Если ввод некорректен, то есть такая таблица не могла получиться в ходе настоящей игры, то надо написать в ответ слово Incorrect.\n  Если таблица корректна и выиграли крестики, то нужно вывести в ответ слова Petya won, если нолики — Vanya won, иначе (то есть они не доиграли или сыграли вничью) надо написать Nobody.\n"
};

extern const std::string equals;

void Task_11_1();
void Task_11_2();
void Task_11_3();
void Task_11_4();
#endif

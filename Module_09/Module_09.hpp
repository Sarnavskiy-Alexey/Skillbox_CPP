#pragma once

const std::string string_tasks[] = {
    "\t\t\tЗадание 1. Время в пути\n  Поезд отправляется в AA часов BB минут и прибывает в пункт назначения в CC часов DD минут. Сколько часов и минут он находится в пути?\n  Напишите программу, которая принимает от пользователя две строки — время отправления и время прибытия поезда.Время задаётся строкой из пяти символов в формате HH:MM.Обеспечьте контроль ввода, убедитесь также, что время корректно.\n  Программа должна ответить, сколько часов и минут поезд находится в пути.Если время отправления больше времени прибытия, считайте, что поезд прибывает в пункт назначения на следующий день.\n",
    "\t\t\tЗадание 2. Длинное вещественное число\n  Вы решили разработать программу - калькулятор, которая складывает числа сколько угодно большой длины.Для этого вы планируете работать с ними как со строками.Первая проблема, с которой вы столкнулись, — по данной строке нужно понять, является она корректной записью вещественного числа или нет.\n  Корректной считается запись, удовлетворяющая следующим условиям:\n  - Первым символом должна быть либо цифра, либо точка, либо знак минус.\n  - После этого может идти ещё несколько цифр(возможно, ни одной).\n  - Затем может идти точка, отделяющая целую часть от дробной. До точки может и не быть цифр.В таком случае считается, что до точки стоит 0.\n  - После точки идёт ещё несколько цифр(возможно, ни одной). Хотя бы одна цифра в записи числа должна присутствовать. (Чтобы не усложнять задачу, в этом задании мы не будем рассматривать числа в экспоненциальной записи, такие как 1.2e-3.)\n  Напишите программу, которая получает от пользователя строку и выводит ответ Yes, если эта строка корректно задаёт вещественное число, в противном случае выводит No.\n",
    "\t\t\tЗадание 3. Подсчёт количества слов\n  Напишите программу, которая считает количество слов в тексте, введённом пользователем. Словом считается любая последовательность символов (не обязательно букв) без пробелов.\n  Пользователь вводит строку, состоящую из произвольных символов и пробелов. Программа должна вывести одно число — количество слов во введённой строке.\n",
    "\t\t\tЗадание 4. «Быки и коровы» (дополнительное задание)\n  В логической игре «Быки и коровы» первый игрок загадывает четырёхзначное число (оно может начинаться и с нулей), а второй игрок должен его отгадать.\n  Отгадывание происходит так: второй игрок называет любое четырёхзначное число, а первый ему отвечает, сколько в этом числе «быков» и сколько «коров».\n  «Корова» — это цифра, которая совпадает по значению с какой-то из цифр задуманного числа, но не стоит на нужном месте. «Бык» — это цифра, совпадающая с цифрой в задуманном числе и по значению, и по расположению.\n  Напишите программу, которая по загаданному числу и по названному вторым игроком числу определяет, сколько во втором числе «быков» и сколько «коров». Не забудьте, что числа могут начинаться с нулей!\n",
    "\t\t\tЗадание 5. Из обычных чисел — в римские (дополнительное задание)\n  Напишите программу, которая переводит данное пользователем число в римскую запись. Например, 19 в римской записи — XIX.\n  Римскую запись числа можно получить, если следовать правилам:\n  - Сначала в ней идут буквы, обозначающие количество тысяч в числе.\n  - Затем идут буквы, обозначающие количество сотен, затем буквы, обозначающие количество десятков, и в конце — буквы, обозначающие количество единиц.\n  - Для записи используются следующие буквы : 1 — I, 5 — V, 10 — X, 50 — L, 100 — C, 500 — D и 1000 — M.\n  - Число получается как сумма значений использованных в нём букв, за тем исключением, что если буква с меньшим значением идёт перед буквой с большим значением, то её значение вычитается из значения числа.\n  - Вычитание используется, только когда надо передать цифру 4 или 9, в остальных случаях используется сложение. Например, 9 обозначается как IX, 40 — как XL.\n  - В числе запрещено писать более трёх одинаковых букв подряд.Таким образом, максимальное число, которое можно записать по этим правилам, — 3999.\n  Программе на вход даётся целое число из диапазона от 1 до 3999. Вы можете считывать его как число или как строку, если так удобнее.\n  Программа должна вывести римскую запись данного числа.\n"
};

extern const std::string equals;

void Task_09_1();
void Task_09_2();
void Task_09_3();
void Task_09_4();
void Task_09_5();
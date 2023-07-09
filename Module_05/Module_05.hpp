#ifdef __MODULE_05__
#pragma once

const std::string string_tasks[] = {
    "\t\t\tЗадание 1. Военный фельдшер\n  Напишите программу, проверяющую, достаточно ли снаряжения у фельдшера для выхода на работу с ранеными. Для этого ему нужно иметь при себе не менее 2000 мл медицинского спирта или не менее пяти наборов походных аптек.\n",
    "\t\t\tЗадание 2. Полёт нормальный!\n  Напишите программу для аэропорта, проверяющую, правильным ли эшелоном летит самолёт. Его скорость должна быть в диапазоне от 750 до 850 км/ч, а высота — в диапазоне от 9000 до 9500 метров.\n",
    "\t\t\tЗадание 3. Майские!\n  Напишите программу-календарь для мая. Она должна проверять введённый номер дня и сообщать, выходной этот день или рабочий. Выходными считаются все субботы и воскресенья, а также даты с 1 по 5 и с 8 по 10 мая включительно. Наш месяц всегда начинается с понедельника.\n",
    "\t\t\tЗадание 4. Майские — усложнение\n  Добавьте возможность начать месяц с любого дня недели. Для этого вводится число — номер дня недели, с которого начинается месяц. Убедитесь, что введённое число корректно.\n",
    "\t\t\tЗадание 5. Склонение русских слов\n  Напишите программу для магазина, которая по заданной цене товара дописывает к нему слово «рубли» в правильном падеже. Например, если вводится число 2000, то ответ должен быть «2000 рублей», если 22 — то «22 рубля», если 51 — то «51 рубль».\n",
    "\t\t\tЗадание 6. Усложнение задачи про кирпич\n  На видео мы с вами писали программу для проверки, удастся ли засунуть кирпич определённых размеров в определённое прямоугольное отверстие. Теперь представьте, что у вас имеется коробка размером AxBxC и другая коробка размером MxNxK. Напишите программу, которая по шести данным числам A, B, C, M, N, K проверяет, можно ли первую коробку положить внутрь второй. Разумеется, коробки можно как угодно переворачивать, но одна коробка должна помещаться в другую целиком. Как обычно, постарайтесь сделать свою программу по возможности лаконичнее.\n",
    "\t\t\tЗадание 7. Банкомат-2\n  Однажды Вася подошёл к банкомату и захотел обналичить N рублей. В банкомате есть купюры достоинством 100, 200, 500, 1000, 2000 и 5000 рублей. Банкомат хочет выдать Васе запрошенную сумму, обойдясь как можно меньшим числом купюр.\n  Напишите программу для банкомата, которая по заданному числу N решает, сколько купюр каждого номинала нужно выдать (4 по 200, 1 по 1000) для получения суммы ровно N рублей, либо говорит, что выдать ровно N рублей невозможно (например, если N не делится на 100). В качестве дополнительного ограничения учтите, что банкомат не может выдать за раз более 150 000 рублей. При попытке запросить такую сумму должно быть выдано сообщение об ошибке.\n  Например, 800 рублей нужно выдать как 1 по 500, 1 по 200 и ещё 1 по 100.\n",
    "\t\t\tЗадание 8. Грустное совершеннолетие\n  Посетитель пришёл в бар и попросил кружку пива. Напишите программу для бармена, который не умеет считать, чтобы по заданной дате рождения посетителя и текущей дате определить, можно ему продавать алкоголь или нет. Программа должна попросить ввести сегодняшнюю дату и дату рождения покупателя, после чего ответить: «можно» или «нельзя».\n  Учтите, что в день 18-летия алкоголь продавать посетителю ещё нельзя, а вот на следующий день после этого — уже можно.\n  Как обычно, постарайтесь сделать свою программу по возможности лаконичнее.\n",
    "\t\t\tЗадание 9. Треугольник на координатной плоскости\n  Проверьте, образуют ли треугольник три данные точки на координатной плоскости. Каждая точка задается двумя координатами. Таким образом, на вход программе даётся шесть чисел: координаты первой точки, затем координаты второй точки и координаты третьей точки. Программа должна ответить Yes, если три данные точки задают треугольник, или No.\n  Например, если хотя бы две из данных точек совпадают, то треугольника данные три точки не образуют. Другой пример: точки с координатами (1; 2), (3; 6) и (-2; −4) не образуют треугольника, поскольку они лежат на одной прямой, хоть и не совпадают.\n  Постарайтесь сделать свою программу по возможности лаконичнее.\n"
};

extern const std::string equals;

void Task_05_1();
void Task_05_2();
void Task_05_3();
void Task_05_4();
void Task_05_5();
void Task_05_6();
void Task_05_7();
void Task_05_8();
void Task_05_9();
#endif

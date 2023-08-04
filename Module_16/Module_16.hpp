#ifdef __MODULE_16__
#pragma once

#include <string>
const std::string string_tasks[] = {
    "\t\t\tЗадание 1. Спидометр\n  Реализуйте цифровой спидометр автомобиля. Сама модель автомобиля, которую нужно будет воссоздать, весьма проста. Начальная скорость — 0 км/ч. Пользователь вводит в стандартный ввод разницу (дельту) в скорости, и результирующая скорость показывается на спидометре в стандартный вывод. Так происходит до той поры, пока машина снова не остановится, то есть пока скорость не станет меньше или равна нулю (сравнение должно происходить с дельтой в 0,01). Диапазон возможных значений скорости машины от 0 до 150 км/ч. Сам показатель спидометра вместе с единицами измерения требуется записывать в отдельную строку-буфер, которая потом и будет показываться на экране. Точность отображения скорости — до 0,1 км/ч.\n  Пример работы программы:\n  Speed delta:30\n  Speed: 30.0\n  Speed delta:20.2\n  Speed: 50.2\n  Speed delta:100\n  Speed: 150.0\n  Speed delta:-22.24\n  Speed: 127.8\n",
    "\t\t\tЗадание 2. Сшиватель дробных чисел\n  Напишите небольшую программу. Из целой и дробной частей числа, которые в отдельности вводит пользователь, составьте новое число с плавающей точкой (типа double) и выведите это число обратно в консоль для проверки. Целая часть — это часть числа, которая находится до точки (запятой), дробная — после.\n",
    "\t\t\tЗадание 3. Калькулятор\n  Создайте небольшую программу для вычисления простых действий с числами. При запуске программа ожидает пользовательского ввода во временную переменную строку. После ввода строки она распарсивается на отдельные члены. Строка записывается в форме “<число-1><действие><число-2>” (без пробелов). Оба числа — это значения с плавающей точкой, повышенной точности (double). Действие может быть одним из: +, −, /, *. Результат действия выводится в стандартный вывод cout.\n",
    "\t\t\tЗадание 4. Механическое пианино\n  Создайте упрощённую модель механического пианино. Всего у данного пианино семь клавиш, которые соответствуют семи нотам. Каждая клавиша кодируется уникальной битовой маской, которая записывается в enum. В начале программы пользователь вводит мелодию. Ввод осуществляется с помощью цифр на клавиатуре, от 1 до 7 включительно (от ноты до до ноты си). В результате из чисел может быть составлена любая комбинация нот. К примеру 512 или 154. После ввода комбинации вводится следующая. Всего таких комбинаций нот — 12. Как только все комбинации были введены пользователем, мелодия проигрывается. Для этого каждая комбинация нот последовательно выводится на экран. Однако на этот раз она печатается «красиво», то есть все ноты указываются словами, а не цифрами. При этом слова разделяются пробелами.\n",
    "\t\t\tЗадание 5. Умный дом\n  Разработайте упрощённую модель умного дома для дачи. Выполните симуляцию его работы на протяжении двух дней. Стартовое время для симуляции умного дома 00:00. Есть несколько датчиков: датчик температуры снаружи, датчик температуры внутри дома. В доме расположен электронный умный щиток с автоматами. Каждый автомат отвечает за включение и отключение определённых устройств или групп устройств:\n  1. отключение и включение питания всего дома;\n  2. основные розетки дома;\n  3. свет внутри дома;\n  4. наружный свет в саду;\n  5. отопление в помещении;\n  6. отопление водопровода, идущего из скважины с насосом;\n  7. кондиционер в помещении.\n  Есть несколько условий по включению/отключению техники в доме и вне его.\n  - Как только температура снаружи падает ниже 0 °С, надо включить систему обогрева водопровода. Если температура снаружи поднялась выше 5 °С, то систему обогрева водопровода нужно отключить.\n  - Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) и снаружи есть какое-то движение, то необходимо включить садовое освещение. Если движения нет или время не вечернее, то света снаружи быть не должно.\n  - Если температура в помещении упала ниже 22 °С, должно включиться отопление. Как только температура равна или поднимается выше 25 °С, отопление автоматически отключается.\n  - Если температура в помещении поднялась до 30 °С, включается кондиционер. Как только температура становится 25 °С, кондиционер отключается.\n  - Всё освещение в доме также умное и поддерживает настройку цветовой температуры для комфортного нахождения. Каждый день начиная с 16:00 и до 20:00 температура цвета должна плавно изменяться с 5000K до 2700К. Разумеется, это изменение должно происходить, если свет сейчас включён. В 00:00 температура сбрасывается до 5000К.\n  Все события по отключению и включению устройств должны выводиться в консоль явным образом. Если устройство не изменило своё состояние (осталось включённым или выключенным), событие генерироваться не должно! Если свет в доме включён, должна отображаться текущая цветовая температура.\n  Программа выполняется следующим образом:\n  - Каждый час пользователь сообщает состояние всех основных датчиков и света (температура снаружи, температура внутри, есть ли движение снаружи, включён ли свет в доме).\n  - Данные параметры вводятся разом в одну строку через пробел, а потом парсятся в переменные из строкового буфера stringstream.\n  - Информация о движении выводится в формате yes/no.\n  - Включение и отключение света происходит с помощью on/off.\n"
};

extern const std::string equals;

void Task_16_1();
void Task_16_2();
void Task_16_3();
void Task_16_4();
void Task_16_5();
#endif

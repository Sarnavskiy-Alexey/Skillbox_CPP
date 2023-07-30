#ifdef __MODULE_16__
/* Задание 4. Механическое пианино
 *  Что нужно сделать:
 *  Создайте упрощённую модель механического пианино. Всего у данного пианино семь клавиш, которые
 *  соответствуют семи нотам. Каждая клавиша кодируется уникальной битовой маской, которая
 *  записывается в enum. В начале программы пользователь вводит мелодию. Ввод осуществляется с
 *  помощью цифр на клавиатуре, от 1 до 7 включительно (от ноты до до ноты си). В результате из
 *  чисел может быть составлена любая комбинация нот. К примеру 512 или 154. После ввода комбинации
 *  вводится следующая. Всего таких комбинаций нот — 12. Как только все комбинации были введены
 *  пользователем, мелодия проигрывается. Для этого каждая комбинация нот последовательно выводится
 *  на экран. Однако на этот раз она печатается «красиво», то есть все ноты указываются словами, а
 *  не цифрами. При этом слова разделяются пробелами.
 *  
 *  Рекомендации:
 *  Для вычленения отдельных символов-цифр из строки с нотами используйте оператор индексации
 *  строки. Для дальнейшей конвертации символа в строку используйте соответствующий конструктор.
 *  Для простоты, чтобы из индекса ноты получить саму ноту-флаг из enum, используйте оператор
 *  сдвига. Общая формула такова: 1 << индекс ноты (начинается с нуля). К примеру, 1 << 0 — битовый
 *  флаг ноты до, 1 << 6 — битовая маска ноты си.
 *  Перечисление, хранящее ноты, имеет вид:
 *  
 *  enum note 
 *  { 
 *      DO = 1, 
 *      RE = 2, 
 *      MI = 4, 
 *      FA = 8, 
 *      SOL = 16, 
 *      LA = 32, 
 *      SI = 64 
 *  };
 *  Соответственно, когда мы проходим по всей мелодии и печатаем её на экран, очередную комбинацию
 *  (аккорд) проверяем так:
 *  if (notes & DO) 
 *  {
 *      std::cout << "DO"; 
 *  }
 *  Где notes — это целое число, один звук нашей мелодии. Она состоит из 12 звуков и имеет вид
 *  int melody[12]; */

#include <iostream>
#include "Module_16.hpp"

// безопасный ввод ноты
static int safe_enter(std::string invite_str, std::string error_str) {
    int X;
    do {
        std::cout << invite_str;
        std::cin >> X;
        if (X < 0 || X > 127)
            std::cout << error_str;
    } while (X < 0 || X > 127);
    
    return X;
}

enum note { 
    DO = 1, 
    RE = 2, 
    MI = 4, 
    FA = 8, 
    SOL = 16, 
    LA = 32, 
    SI = 64 
};

static void play_note(int note) {
    int counter = 0;
    if (note & DO) {
        std::cout << "DO";
        counter++;
    }
    if (note & RE) {
        if (counter)
            std::cout << "-";
        std::cout << "RE";
        counter++;
    }
    if (note & MI) {
        if (counter)
            std::cout << "-";
        std::cout << "MI";
        counter++;
    }
    if (note & FA) {
        if (counter)
            std::cout << "-";
        std::cout << "FA";
        counter++;
    }
    if (note & SOL) {
        if (counter)
            std::cout << "-";
        std::cout << "SOL";
        counter++;
    }
    if (note & LA) {
        if (counter)
            std::cout << "-";
        std::cout << "LA";
        counter++;
    }
    if (note & SI) {
        if (counter)
            std::cout << "-";
        std::cout << "SI";
        counter++;
    }
}

static void play_melody(int melody[], const int size) {
    for (int i = 0; i < size; i++) {
        play_note(melody[i]);
        std::cout << "\n";
    }
}

static void enter_melody(int melody[], const int size) {
    for (int i = 0; i < size; i++)
        melody[i] = safe_enter("Введите звук в виде числа от 0 до 127: ",
                               "ОШИБКА! Звук должен быть в пределах от 0 до 127!\n");
}

void Task_16_4() {
    std::cout << equals << string_tasks[3] << equals;

    const int size = 12;
    int melody[size];
    enter_melody(melody, size);
    play_melody(melody, size);
}
#endif

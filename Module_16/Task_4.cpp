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
    int X, tmp;
    bool right;

    do {
        right = true;
        std::cout << invite_str;
        std::cin >> X;
        
        // если введенное число меньше нуля, то такого аккорда быть не может
        if (X < 0) {
            right = false;
            std::cout << error_str;
        } else {
            // проверяем каждый разряд числа X
            tmp = X;
            while (tmp > 0) {
                if (tmp % 10 > 7 || tmp % 10 == 0) {
                    right = false;
                    std::cout << error_str;
                    break;
                }
                tmp /= 10;
            }
        }
    } while (!right);
    
    return X;
}

enum e_note {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

// функция сбора в один параметр аккорда
static bool check_note(int note, e_note n, int& note_state) {
    if (note & n) {
        note_state |= n;
        return true;
    }
    return false;
}

// функция для вывода на экран названия ноты в аккорде
static void print_note(int note_state, e_note n, std::string note_str, int& counter) {
    if (note_state & n) {
        if (counter != 0)
            std::cout << "-";
        std::cout << note_str;
        counter++;
    }
}

// функция для проигрыша одного аккорда
static void play_note(int note) {
    int note_state = 0;
    int tmp = note;
    while (tmp != 0) {
        int note_as_is = 1 << (tmp % 10 - 1);
        if (check_note(note_as_is, DO, note_state));
        else if (check_note(note_as_is, RE, note_state));
        else if (check_note(note_as_is, MI, note_state));
        else if (check_note(note_as_is, FA, note_state));
        else if (check_note(note_as_is, SOL, note_state));
        else if (check_note(note_as_is, LA, note_state));
        else if (check_note(note_as_is, SI, note_state));

        tmp /= 10;
    }

    int counter = 0;
    print_note(note_state, DO, "DO", counter);
    print_note(note_state, RE, "RE", counter);
    print_note(note_state, MI, "MI", counter);
    print_note(note_state, FA, "FA", counter);
    print_note(note_state, SOL, "SOL", counter);
    print_note(note_state, LA, "LA", counter);
    print_note(note_state, SI, "SI", counter);
}

// функция для проигрыша всей мелодии
static void play_melody(int melody[], const int size) {
    for (int i = 0; i < size; i++) {
        play_note(melody[i]);
        std::cout << "\n";
    }
}

// функция для ввода мелодии
static void enter_melody(int melody[], const int size) {
    for (int i = 0; i < size; i++)
        melody[i] = safe_enter("Введите аккорд в виде числа с цифрами от 1 до 7: ",
                         "ОШИБКА! Аккорд должен быть положительным и состоять из цифр от 1 до 7!\n");
}

void Task_16_4() {
    std::cout << equals << string_tasks[3] << equals;

    const int size = 12;
    int melody[size];
    enter_melody(melody, size);
    play_melody(melody, size);
}
#endif

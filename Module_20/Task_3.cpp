#ifdef __MODULE_20__
/* Задание 3. Реализация симуляции игры «Рыбалка»
 *  Что нужно сделать
 *  Реализуйте простую симуляцию игры в рыбалку. В исходном текстовом файле реки (river.txt)
 *  задаётся список из видов рыб, которые можно в ней поймать. Рыбок может быть сколько угодно,
 *  разных видов. Виды при этом могут повторяться.
 *  В начале программы пользователь указывает, какую именно рыбу он сейчас будет ловить — вид этой
 *  рыбы. После этого из первого файла друг за другом осуществляется чтение его содержимого, вид за
 *  видом. Если на отдельных шагах вид совпал с указанным пользователем, в выходной файл basket.txt
 *  (корзинка) записывается этот вид.
 *  В конце программы показывается, сколько было поймано рыб за текущую ловлю. Программу можно
 *  запускать несколько раз, при этом уже пойманные рыбы должны сохраняться в файле-корзинке.
 *  
 *  Пример содержания исходного файла:
 *      sunfish
 *      shad
 *      carp
 *      bass
 *      bullhead
 *      carp
 *      walleye
 *      catfish
 *      carp */

#include <iostream>
#include <fstream>
#include <string>
#include "Module_20.hpp"

// внесение данных о рыбе в корзину
static void set_basket(std::string fish) {
    std::ofstream file;

    file.open(CUR_DIR + DOCS_DIR + "basket.txt", std::ios_base::app);
    if (file.is_open()) {
        file << fish << "\n";
    } else {
        std::cout << "File is not open!\n";
    }
}

// сравнение данных из реки с рыбой для поимки
static bool get_river(std::string fishFind) {
    std::ifstream file;
    std::string fish;
    bool found = false;

    file.open(CUR_DIR + DOCS_DIR + "river.txt");
    if (file.is_open()) {
        std::string tmp;
        while (!file.eof()) {
            file >> fish;
            if (fish == fishFind) {
                found = true;
                break;
            }
        }
        file.close();
    } else {
        std::cout << "File is not open!\n";
    }
    return found;
}

void Task_20_3() {
    std::cout << equals << string_tasks[2] << equals;

    std::string answer, fish;
    do {
        std::cout << "Введите вид рыбы для поимки из реки: ";
        std::cin >> fish;
        if (get_river(fish))
            set_basket(fish);

        std::cout << "Хотите продолжить улов рыбы? (Y/N)";
        std::cin >> answer;
    } while (answer == "Y" || answer == "y");

    // вывод на экран всей пойманной рыбы
    std::ifstream basket;
    basket.open(CUR_DIR + DOCS_DIR + "basket.txt");
    if (basket.is_open()) {
        std::string fish;

        std::cout << "Ваш улов:\n";
        while (!basket.eof()) {
            std::getline(basket, fish);
            std::cout << fish << "\n";
        }
        basket.close();
    } else {
        std::cout << "File is not open!\n";
    }
}
#endif

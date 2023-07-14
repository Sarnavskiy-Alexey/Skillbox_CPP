#ifdef __MODULE_13__
/* Задача 2
 *  С помощью списка инициализации задаётся вектор цен на продукты (дробными числами). Таким же
 *  образом с помощью списка инициализации задаётся вектор покупок (в виде индексов), которые
 *  совершает человек. Необходимо вывести на экран итоговую стоимость покупок. Вектор цен и вектор
 *  покупок можно задать напрямую в коде. */

#include <iostream>
#include <vector>
#include "Module_13.hpp"

static float get_sum(std::vector<float> prices, std::vector<int> items) {
    float sum = 0.0f;

    for (unsigned int i = 0; i < items.size(); i++) {
        if (items[i] >= 0 && (unsigned int)items[i] < prices.size())
            sum += prices[items[i]];
        else{
            std::cout << "ОШИБКА! В векторе покупок содержатся не распознанные товары.\n";
            std::cout << "Работа функции остановлена!\n";
            break;
        }
    }
    return sum;
}

static void print_prices(std::vector<float> prices) {
    std::cout << "Вектор цен товаров содержит следующие позиции:\n";
    for (unsigned int i = 0; i < prices.size(); i++)
        std::cout << "\t" << i << " - " << prices[i] << "\n";
}

static int safe_enter(std::string invite_str, std::string error_str) {
    int X;
    do {
        std::cout << invite_str;
        std::cin >> X;
        if (X <= 0)
            std::cout << error_str;
    } while (X <= 0);
    
    return X;
}

// функция получения size значений, заносимых в возвращаемый вектор покупок
static std::vector<int> get_item_vector(int size, std::vector<float> prices) {    
    std::vector<int> vect(size);

    for (int i = 0; i < size; i++) {
        std::cout << "Введите " << i << "-й номер товара из вектора цен: ";
        std::cin >> vect[i];
    }

    return vect;
}

// функция получения size значений, заносимых в возвращаемый вектор цен
static std::vector<float> get_price_vector(int size) {
    std::vector<float> vect(size);

    for (int i = 0; i < size; i++) {
        std::cout << "Введите цену " << i << "-го товара: ";
        std::cin >> vect[i];
    }

    return vect;
}

void Task_13_2() {
    std::cout << equals << string_tasks[1] << equals;
    
    // std::vector<float> prices { 2.5, 4.25, 3.0, 10.0 };
    // std::vector<int> items { 1, 1, 0, 3 };

    std::vector<float> prices;
    std::vector<int> items;
    int size_prices, size_items;

    // безопасный ввод размера вектора цен
    size_prices = safe_enter("Введите количество товаров для определения цен: ",
                             "ОШИБКА! Количество товаров должно быть положительным значением!\n");

    // безопасный ввод размера вектора покупок
    size_items = safe_enter("Введите количество товаров для покупки: ",
                            "ОШИБКА! Количество товаров должно быть положительным значением!\n");

    // получение данных о ценах товаров
    prices = get_price_vector(size_prices);
    print_prices(prices);

    // получение данных о покупках
    items = get_item_vector(size_items, prices);

    // получение итоговой суммы покупок
    float sum = get_sum(prices, items);
    std::cout << "Суммарная стоимость будет равна " << sum << ".\n";
}
#endif

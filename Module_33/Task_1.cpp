#ifdef __MODULE_33__
/* Задание 1. Работа корзины с покупками
 *  Что нужно сделать:
 *  Реализуйте простую и безопасную модель работы корзины онлайн-магазина.
 *  В начале программы вы заполняете базу данных самого магазина через стандартную консоль. Каждый
 *  элемент этой базы данных состоит из двух компонентов — артикула и количества штук.
 *  Корзина должна поддерживать следующие операции: добавление товара с указанным его количеством —
 *  add, удаление товара с указанным количеством — remove. Обе операции принимают артикул товара в
 *  виде строки и количество в виде целого числа.
 *  При вводе аргументов к операциям должна осуществляться их валидация. Артикул должен быть в базе
 *  данных магазина, количество не должно превышать количество доступного продукта на складе (при
 *  удалении — в корзине).
 *  
 *  Рекомендации:
 *  В качестве контейнера для базы данных и самой корзины можете использовать std::map.
 *  Если пользователь ввёл некорректную информацию, то лучше выбросить std::invalid_argument, в
 *  других случаях — runtime_error. 
 *  
 *  Что оценивается:
 *  Корректность логики работы при использовании исключений. */

#include <iostream>
#include <map>
#include <string>
#include "Module_33.hpp"
#include "Module_33_Exceptions.hpp"

static void add_data_in_db(std::map<std::string, int>& db, std::string art, int amount) {
    if (amount < 0) {
        throw AmountIsLessZeroException();
    }
    db[art] = amount;
}

static void fill_db(std::map<std::string, int>& db) {
    std::string article;
    int amount;

    std::cout << "Введите артикул (\"exit\" для выхода): ";
    std::cin >> article;
    while (article != "exit") {
        std::cout << "Введите количество: ";
        std::cin >> amount;
        try {
            add_data_in_db(db, article, amount);
        } catch (const AmountIsLessZeroException& X) {
            std::cerr << X.what() << "\n";
        } catch (...) {
            std::cerr << "Возникла неизвестная ошибка!" << "\n";
        }
        std::cout << "Введите артикул (\"exit\" для выхода): ";
        std::cin >> article;
    }
}

static void add_product_in_basket(std::map<std::string, int>& db,
                           std::map<std::string, int>& basket,
                           std::string art,
                           int amount) {
    if (db.find(art) == db.end()) {
        throw ArticleNotInDatabaseException();
    } else if (db[art] < amount) {
        throw AmountIsMoreThanInDatabaseException();
    } else if (amount <= 0) {
        throw AmountIsEqualOrLessToZeroException();
    } else {
        basket[art] = amount;
    }
}

static void fill_basket(std::map<std::string, int>& db, std::map<std::string, int>& basket) {
    std::string article;
    int amount;

    std::cout << "Введите артикул (\"exit\" для выхода): ";
    std::cin >> article;
    while (article != "exit") {
        std::cout << "Введите количество: ";
        std::cin >> amount;
        try {
            add_product_in_basket(db, basket, article, amount);
        } catch (const ArticleNotInDatabaseException& X) {
            std::cerr << X.what() << "\n";
        } catch (const AmountIsMoreThanInDatabaseException& X) {
            std::cerr << X.what() << "\n";
        } catch (const AmountIsEqualOrLessToZeroException& X) {
            std::cerr << X.what() << "\n";
        } catch (...) {
            std::cerr << "Возникла неизвестная ошибка!" << "\n";
        }
        std::cout << "Введите артикул (\"exit\" для выхода): ";
        std::cin >> article;
    }
}

static void print_database(const std::map<std::string, int>& db){
    for (auto art : db) {
        std::cout << "\t" << art.first << " : " << art.second << "\n";
    }
}

void Task_33_1() {
    std::cout << equals << string_tasks[0] << equals;

    std::map<std::string, int> database;
    std::map<std::string, int> basket;

    fill_db(database);
    print_database(database);

    fill_basket(database, basket);
    print_database(basket);
}
#endif

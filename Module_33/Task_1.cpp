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
#include <vector>
#include <limits>
#include <sstream>
#include "Module_33.hpp"
#include "Module_33_Exceptions.hpp"

class MyShop {
private:
    std::map<std::string, size_t> storage;
    std::vector<std::map<std::string, size_t>> userBasket;
public:
    // конструкторы
    MyShop(std::map<std::string, size_t> _storage) : storage(_storage) {};
    MyShop() {};

    // методы обработки склада
    bool found_by_article_in_db(const std::string article) const noexcept {
        return storage.find(article) != storage.end();
    }

    void add_in_db(const std::string article, size_t amount) {
        if (!found_by_article_in_db(article)) {
            storage[article] = amount;
        } else {
            throw ArticleIsInDatabaseException();
        }
    }

    void remove_from_db(const std::string article) {
        if (found_by_article_in_db(article)) {
            storage.erase(article);
        } else {
            throw ArticleNotInDatabaseException();
        }
    }

    void replace_in_db(const std::string article, size_t amount) {
        if (found_by_article_in_db(article)) {
            storage.at(article) = amount;
        } else {
            throw ArticleNotInDatabaseException();
        }
    }

    void print_storage() const noexcept {
        if (storage.begin() == storage.end()) {
            std::cout << "В данный момент склад пуст!\n";
        } else {
            std::cout << "Сейчас на складе содержатся:\n";
            for (auto it = storage.begin(); it != storage.end(); it++) {
                std::cout << "\t" << it->first << " : " << it->second << "\n";
            }
        }
    }

    // методы обработки корзины
    size_t create_new_basket() noexcept {
        std::map<std::string, size_t> temp;
        userBasket.push_back(temp);
        return userBasket.size() - 1;
    }

    void remove_basket(const size_t basketNumber) {
        if (basketNumber < userBasket.size()) {
            userBasket.erase(userBasket.begin() + basketNumber);
        } else {
            throw BasketIsNotInShopException();
        }
    }

    bool found_by_article_in_basket(const size_t basketNumber, const std::string article) const noexcept {
        return userBasket[basketNumber].find(article) != userBasket[basketNumber].end();
    }

    // добавление товара в корзину с функцией дополнения
    void add_in_basket(const size_t basketNumber, const std::string article, const size_t amount) {
        if (found_by_article_in_db(article)) {
            if (basketNumber < userBasket.size()) {
                if (amount > 0) {
                    if (amount <= storage.at(article)) {
                        if (userBasket[basketNumber].find(article) != userBasket[basketNumber].end()) {
                            userBasket[basketNumber].at(article) = userBasket[basketNumber].at(article) + amount;
                        } else {
                            userBasket[basketNumber][article] = amount;
                        }
                        storage.at(article) = storage.at(article) - amount;
                    } else {
                        throw AmountIsMoreThanInDatabaseException();
                    }
                } else {
                    throw AmountIsEqualToZeroException();
                }
            } else {
                throw BasketIsNotInShopException();
            }
        } else {
            throw ArticleNotInDatabaseException();
        }
    }

    // удаление товара из корзины
    void remove_from_basket(const size_t basketNumber, const std::string article) {
        if (found_by_article_in_db(article)) {
            if (basketNumber < userBasket.size()) {
                if (found_by_article_in_basket(basketNumber, article)) {
                    storage.at(article) += userBasket[basketNumber].at(article);
                    userBasket[basketNumber].erase(article);
                } else {
                    throw ArticleNotInBasketException();
                }
            } else {
                throw BasketIsNotInShopException();
            }
        } else {
            throw ArticleNotInDatabaseException();
        }
    }

    void print_baskets() const noexcept {
        if (userBasket.begin() == userBasket.end()) {
            std::cout << "На данный момент ни одной корзины не создано!\n";
        } else {
            for (size_t i = 0; i < userBasket.size(); i++) {
                if (userBasket[i].begin() == userBasket[i].end()) {
                    std::cout << "Корзина №" << i << " пуста!\n";
                } else {
                    std::cout << "В корзине №" << i << " находятся:\n";
                    for (auto it = userBasket[i].begin(); it != userBasket[i].end(); it++) {
                        std::cout << "\t" << it->first << " : " << it->second << "\n";
                    }
                }
            }
        }
        print_storage();
    }
};

static bool check_uint(std::string numStr) {
    for (unsigned int i = 0; i < numStr.length(); i++) {
        if (numStr[i] < '0' || numStr[i] > '9') {
            return false;
        }
    }
    return true;
}

static void help_fill() {
    std::cout << "  add <article> <amount>         - добавление товара на склад по артикулу и количеству\n";
    std::cout << "  replace <article> <new_amount> - замена количества товара на складе по артикулу и количеству\n";
    std::cout << "  remove <article>               - удаление товара со склада по артикулу\n";
    std::cout << "  print                          - вывод всех товаров и их количества на складе на экран\n";
    std::cout << "  help                           - вывод данного сообщения\n";
    std::cout << "  exit                           - выход из обновления БД\n";
    std::cout << "\n";
}

static void add_in_db_command(std::string part_command, MyShop& shop) {
    std::string article, amountStr, err;
    std::stringstream buf(part_command);
    size_t amountNum;

    buf >> article >> amountStr >> err;
    if (article.length() && amountStr.length() && !err.length() && check_uint(amountStr)) {
        amountNum = std::stoul(amountStr);
        try {
            shop.add_in_db(article, amountNum);
        } catch (const ArticleIsInDatabaseException& X) {
            std::cout << X.what() << "\n";
        }
    } else {
        std::cout << "Команда не распознана!\n";
    }
}

static void replace_in_db_command(std::string part_command, MyShop& shop) {
    std::string article, amountStr, err;
    std::stringstream buf(part_command);
    size_t amountNum;

    buf >> article >> amountStr >> err;
    if (article.length() && amountStr.length() && !err.length() && check_uint(amountStr)) {
        amountNum = std::stoul(amountStr);
        try {
            shop.replace_in_db(article, amountNum);
        } catch (const ArticleNotInDatabaseException& X) {
            std::cout << X.what() << "\n";
        }
    } else {
        std::cout << "Команда не распознана!\n";
    }
}

static void remove_from_db_command(std::string part_command, MyShop& shop) {
    std::string article, err;
    std::stringstream buf(part_command);

    buf >> article >> err;
    if (article.length() && !err.length()) {
        try {
            shop.remove_from_db(article);
        } catch (const ArticleNotInDatabaseException& X) {
            std::cout << X.what() << "\n";
        }
    } else {
        std::cout << "Команда не распознана!\n";
    }
}

static void help_work() {
    std::cout << "  add <basket> <article> <amount> - добавление товара в корзину по артикулу и количеству\n";
    std::cout << "  create                          - создание пользовательской корзины\n";
    std::cout << "  remove <basket>                 - удаление пользовательской корзины\n";
    std::cout << "  remove <basket> <article>       - удаление товара со склада по артикулу\n";
    std::cout << "  print                           - вывод всех товаров и их количества во всех корзинах на экран\n";
    std::cout << "  help                            - вывод данного сообщения\n";
    std::cout << "  exit                            - выход из программы\n";
    std::cout << "\n";
}

static void add_in_basket_command(std::string part_command, MyShop& shop) {
    std::string basketNumStr, article, amountStr, err;
    std::stringstream buf(part_command);
    size_t basketNum, amountNum;

    buf >> basketNumStr >> article >> amountStr >> err;
    if (basketNumStr.length() && article.length() && amountStr.length()
                              && !err.length()
                              && check_uint(amountStr) && check_uint(basketNumStr)) {
        basketNum = std::stoul(basketNumStr);
        amountNum = std::stoul(amountStr);
        try {
            shop.add_in_basket(basketNum, article, amountNum);
        } catch (const std::exception& X) {
           std::cout << X.what() << "\n";
        }
    } else {
        std::cout << "Команда не распознана!\n";
    }
}

static void remove_basket_or_from_basket_command(std::string part_command, MyShop& shop) {
    std::string basketNumStr, article, err;
    std::stringstream buf(part_command);
    size_t basketNum;

    buf >> basketNumStr >> article >> err;
    if (basketNumStr.length() && !err.length() && check_uint(basketNumStr)) {
        if (article.length()) {
            basketNum = std::stoul(basketNumStr);
            try {
                shop.remove_from_basket(basketNum, article);
            } catch (const std::exception& X) {
                std::cout << X.what() << "\n";
            }
        } else {
            try {
                shop.remove_basket(basketNum);
            } catch (const std::exception& X) {
                std::cout << X.what() << "\n";
            }
        }
    } else {
        std::cout << "Команда не распознана!\n";
    }
}

static void fill_database(MyShop& shop) {
    std::string command, operation;

    while (true) {
        std::cout << "Введите команду: ";
        std::getline(std::cin, command);
        std::stringstream buffer(command);

        buffer >> operation;
        if (command == "help") {
            help_fill();
        } else if (command == "exit") {
            std::cout << "Заполнение базы данных окончено!\n";
            break;
        } else if (operation == "print") {
            shop.print_storage();
        } else if (operation == "add" && (command.length() > operation.length() + 1)) {
            add_in_db_command(buffer.str().substr(operation.length() + 1), shop);
        } else if (operation == "replace" && (command.length() > operation.length() + 1)) {
            replace_in_db_command(buffer.str().substr(operation.length() + 1), shop);
        } else if (operation == "remove" && (command.length() > operation.length() + 1)) {
            remove_from_db_command(buffer.str().substr(operation.length() + 1), shop);
        } else {
            std::cout << "Команда не распознана! Введите \"help\" для помощи.\n";
        }
    }
}

static void work(MyShop& shop) {
    std::string command, operation;

    while (true) {
        std::cout << "Введите команду: ";
        std::getline(std::cin, command);
        std::stringstream buffer(command);

        buffer >> operation;
        if (command == "help") {
            help_work();
        } else if (command == "exit") {
            std::cout << "Работа с программой окончена!\n";
            break;
        } else if (operation == "print") {
            shop.print_baskets();
        } else if (operation == "create") {
            size_t basketNum = shop.create_new_basket();
            std::cout << "Вы создали корзину под номером " << basketNum << "\n";
        } else if (operation == "add" && (command.length() > operation.length() + 1)) {
            add_in_basket_command(buffer.str().substr(operation.length() + 1), shop);
        } else if (operation == "remove" && (command.length() > operation.length() + 1)) {
            remove_basket_or_from_basket_command(buffer.str().substr(operation.length() + 1), shop);
        } else {
            std::cout << "Команда не распознана! Введите \"help\" для помощи.\n";
        }
    }
}

void Task_33_1() {
    std::cout << equals << string_tasks[0] << equals;

    // очистка буфера ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    MyShop shop;
    fill_database(shop);
    work(shop);     
}
#endif

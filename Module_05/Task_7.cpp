/* Задание 7. Банкомат-2
 *  Однажды Вася подошёл к банкомату и захотел обналичить N рублей. В банкомате есть купюры
 *  достоинством 100, 200, 500, 1000, 2000 и 5000 рублей. Банкомат хочет выдать Васе запрошенную
 *  сумму, обойдясь как можно меньшим числом купюр.
 *  Напишите программу для банкомата, которая по заданному числу N решает, сколько купюр каждого
 *  номинала нужно выдать (4 по 200, 1 по 1000) для получения суммы ровно N рублей, либо говорит,
 *  что выдать ровно N рублей невозможно (например, если N не делится на 100). В качестве
 *  дополнительного ограничения учтите, что банкомат не может выдать за раз более 150 000 рублей.
 *  При попытке запросить такую сумму должно быть выдано сообщение об ошибке.\n  Например, 800
 *  рублей нужно выдать как 1 по 500, 1 по 200 и ещё 1 по 100. */

#include <iostream>
#include "Module_05.hpp"

void Task_05_7() {
    std::cout << equals << string_tasks[6] << equals;

    int requestedMoney,
        cash100 = 0, cash200 = 0, cash500 = 0,
        cash1000 = 0, cash2000 = 0, cash5000 = 0;

    std::cout << "Введите сумму, кратную 100: ";
    std::cin >> requestedMoney;

    std::cout << "\n------------Проверка введенной суммы------------\n\n";

    if (requestedMoney % 100)
        std::cout << "Введенная сумма не кратна 100!\n";
    else if (requestedMoney <= 0 || requestedMoney > 150000)
        std::cout << "Запрошенная сумма не может быть выдана!\n";
    else {
        std::cout << "\n------------Подсчет банкнот------------\n\n";

        int requestedMoneyDropped;
        requestedMoneyDropped = requestedMoney;
        if (requestedMoneyDropped >= 5000) {
            cash5000 = requestedMoneyDropped / 5000;
            requestedMoneyDropped -= cash5000 * 5000;
        }
        if (requestedMoneyDropped >= 2000) {
            cash2000 = requestedMoneyDropped / 2000;
            requestedMoneyDropped -= cash2000 * 2000;
        }
        if (requestedMoneyDropped >= 1000) {
            cash1000 = requestedMoneyDropped / 1000;
            requestedMoneyDropped -= cash1000 * 1000;
        }
        if (requestedMoneyDropped >= 500) {
            cash500 = requestedMoneyDropped / 500;
            requestedMoneyDropped -= cash500 * 500;
        }
        if (requestedMoneyDropped >= 200) {
            cash200 = requestedMoneyDropped / 200;
            requestedMoneyDropped -= cash200 * 200;
        }
        if (requestedMoneyDropped >= 100) {
            cash100 = requestedMoneyDropped / 100;
            requestedMoneyDropped -= cash100 * 100;
        }

        std::cout << requestedMoney << " руб. выдано следующими банкнотами:\n";
        if (cash5000) std::cout << "\t5000 руб.: " << cash5000 << "\n";
        if (cash2000) std::cout << "\t2000 руб.: " << cash2000 << "\n";
        if (cash1000) std::cout << "\t1000 руб.: " << cash1000 << "\n";
        if (cash500) std::cout << "\t500 руб.: " << cash500 << "\n";
        if (cash200) std::cout << "\t200 руб.: " << cash200 << "\n";
        if (cash100) std::cout << "\t100 руб.: " << cash100 << "\n";
    }
}
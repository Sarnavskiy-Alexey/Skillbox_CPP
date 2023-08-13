#ifdef __MODULE_20__
/* Задание 4. Реализация симуляции банкомата
 *  Что нужно сделать
 *  Требуется реализовать упрощённую симуляцию работы банкомата. В банкомате могут храниться только
 *  бумажные купюры номиналом от 100 до 5000 рублей. Максимально в банкомате может храниться только
 *  1000 купюр. Все они записываются в отдельный файл. У банкомата, как у устройства, две основных
 *  операции — снятие денег пользователем и наполнение деньгами инкассаторами банка.
 *  Наполнение банкомата происходит, если при старте программы в консоль вводится символ плюс “+”. 
 *  Количество купюр рассчитывается так, чтобы банкомат был заполнен полностью. Все купюры при этом
 *  выбираются случайным образом.
 *  Если на старте программы в консоль вводится минус (“-”), то симулируется снятие пользователем
 *  денег. Пользователь указывает сумму с точностью до 100 рублей. Мы будем считать, что каждый
 *  клиент обладает неограниченным балансом в системе и теоретически может снять любую сумму. На
 *  практике, если данная сумма не может быть снята из-за отсутствия подходящих денег в машине,
 *  показывается сообщение, что эта операция невозможна.
 *  После выполнения любой из операций программа завершает выполнение. Состояние банкомата должно
 *  храниться в отдельном бинарном файле, автономно.
 *  
 *  Советы и рекомендации:
 *  Вы можете хранить массив купюр целиком, помечая отсутствующие позиции нулями. */

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include "Module_20.hpp"

#define ATM_SIZE 1000

// перечисление для умножения денег при подсчете
enum MULT_MONEY {
    ONE,    // сто
    TWO,    // двести
    FIVE,   // пятьсот
    TEN,    // одна тысяча
    TWENTY, // две тысячи
    FIFTY,  // пять тысяч
    SIZE    // количество элементов в перечислении
};

// функция перевода из MULT_MONEY в int
static int mult_money_to_int(MULT_MONEY mult) {
    switch (mult) {
        case ONE: return 100;
        case TWO: return 200;
        case FIVE: return 500;
        case TEN: return 1000;
        case TWENTY: return 2000;
        case FIFTY: return 5000;
        default: break;
    }
    return 0;
}

// функция перевода из int в MULT_MONEY
static MULT_MONEY int_to_mult_money(int money) {
    switch (money) {
        case 100: return ONE;
        case 200: return TWO;
        case 500: return FIVE;
        case 1000: return TEN;
        case 2000: return TWENTY;
        case 5000: return FIFTY;
        default: return SIZE;
    }
}

// безопасный ввод суммы для снятия
static int safe_enter(std::string invite_str, std::string error_str) {
    int X;
    do {
        std::cout << invite_str;
        std::cin >> X;
        if (X % 100 != 0 || X < 100 || X > 300000)
            std::cout << error_str;
    } while (X % 100 != 0 || X < 100 || X > 300000);
    
    return X;
}

// функция нахождения общего количества банкнот в банкомате
static unsigned int get_atm_real_size() {
    unsigned int size = 0;
    std::ifstream file;
    file.open(CUR_DIR + DOCS_DIR + "automat.bin", std::ios_base::binary);
    if (file.is_open()) {
        char buffer[ATM_SIZE * 4 + 1] = { 0 };
        file.read(buffer, ATM_SIZE * 4);
        size = file.gcount();
        file.close();
    } else {
        std::cout << "File is not open!\n";
    }
    return size;
}

// функция пополнения банкомата наличными
static void topup_cash() {
    std::ofstream atm;

    atm.open(CUR_DIR + DOCS_DIR + "automat.bin", std::ios_base::binary | std::ios_base::app);
    if (atm.is_open()) {
        unsigned int real_size = get_atm_real_size() / 4;
        int number;

        // цикл заполняет файл до конца (до 1000 элементов)
        for (unsigned int _ = real_size; _ < ATM_SIZE; _++) {
            // добавляется одна из купюр (100, 200, 500, 1000, 2000, 5000)
            number = mult_money_to_int((MULT_MONEY)(rand() % SIZE));
            atm.write((char*)&number, sizeof(number));
        }

        atm.close();
        std::cout << "Банкомат пополнен!\n";
    } else {
        std::cout << "File is not open!\n";
    }
}

// функция подсчета купюр
static void count_bills(int* bills, int* cash) {
    for (int i = 0; i < ATM_SIZE; i++) {
        MULT_MONEY mult = int_to_mult_money(cash[i]);
        if (mult != SIZE)
            bills[mult]++;
    }
}

// функция уточнения хватки купюр для выдачи (простая)
static bool check_bills(int* bills, int* bills_needed, int sum) {
    // подсчитываем количество необходимых купюр
    for (int i = SIZE - 1; i >= 0; i--) {
        int minus = mult_money_to_int((MULT_MONEY)i);
        MULT_MONEY mult = int_to_mult_money(minus);

        while (sum >= minus) {
            sum -= minus;
            bills_needed[mult]++;
        }
    }

    // проверяем хватит ли купюр на выдачу
    for (int i = 0; i < SIZE; i++)
        if (bills[i] < bills_needed[i])
            return false;
    // если хватает, то выдаем
    for (int i = 0; i < SIZE; i++)
        bills[i] -= bills_needed[i];
    return true;
}

// функция возврата всех денег в банкомат
static void return_bills(int* bills) {
    std::ofstream atm;
    
    atm.open(CUR_DIR + DOCS_DIR + "automat.bin", std::ios_base::binary |
                                                 std::ios_base::trunc |
                                                 std::ios_base::out);
    if (atm.is_open()) {
        for (int i = ONE; i < SIZE; i++) {
            int number = mult_money_to_int((MULT_MONEY)i);
            for (int j = 0; j < bills[i]; j++)
                atm.write((char*)&number, sizeof(number));
        }
        atm.close();
    } else {
        std::cout << "File is not open!\n";
    }
}

// функция снятия наличных из банкомата
static void withdraw_cash(int money) {
    int cash[ATM_SIZE] = { 0 };
    int bills[6] = { 0 };
    int bills_needed[6] = { 0 };
    std::ifstream file;

    file.open(CUR_DIR + DOCS_DIR + "automat.bin", std::ios_base::binary);
    if (file.is_open()) {
        file.read((char*)cash, ATM_SIZE * 4);
        file.close();

        // подсчет кэша в банкомате
        count_bills(bills, cash);
        // проверяем хватит ли нужного количества банкнот в банкомате
        if (check_bills(bills, bills_needed, money)) {
            std::cout << "Заберите выданные наличные!\n";
            // если хватило, то обновляем файл с банкнотами
            return_bills(bills);
        } else {
            std::cout << "Деньги не выданы из-за нехватки купюр. Попробуйте ввести другую сумму!\n";
        }
    } else {
        std::cout << "File is not open!\n";
    }
}

void Task_20_4() {
    std::cout << equals << string_tasks[3] << equals;

    std::srand(std::time(nullptr));
    
    std::string answer;
    std::cout << "Введите \"+\" для пополнения банкомата или \"-\" для снятия наличных: ";
    std::cin >> answer;
    if (answer == "+")
        topup_cash();
    else if (answer == "-") {
        int money_to_withdraw = safe_enter("Введите сумму для снятия: ",
                                "ОШИБКА! Сумма должна быть кратной 100 и не больше 300000!\n");
        
        withdraw_cash(money_to_withdraw);
    } else {
        std::cout << "Операция не распознана!\n";
    }
}
#endif

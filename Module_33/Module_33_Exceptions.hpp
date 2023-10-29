// #ifdef __MODULE_33__

#pragma once

#include <exception>

class AmountIsLessZeroException : std::exception {
public:
    const char * what() const noexcept override {
        return "Количество товара не должно быть меньше нуля!";
    }
};

class ArticleNotInDatabaseException : std::exception {
public:
    const char * what() const noexcept override {
        return "Артикул не найден в базе данных!";
    }
};

class AmountIsMoreThanInDatabaseException : std::exception {
public:
    const char * what() const noexcept override {
        return "Количество товара превышает доступное количество на складе!";
    }
};

class AmountIsEqualOrLessToZeroException : std::exception {
public:
    const char * what() const noexcept override {
        return "Количество товара в корзине должно быть больше нуля!";
    }
};

class PondNumberInvalidException : std::exception {
public:
    const char * what() const noexcept override {
        return "Номер пруда выбран неверно!";
    }
};

class FishInPondException : std::exception {
public:
    const char * what() const noexcept override {
        return "Поздравляю! Рыба поймана!";
    }
};

class BootInPondException : std::exception {
public:
    const char * what() const noexcept override {
        return "ХА-ХА! Сапог в пруду!";
    }
};

class NothingInPondException : std::exception {
public:
    const char * what() const noexcept override {
        return "Жаль, но этот пруд пуст! Попробуйте следующий!";
    }
};

class KeyIsNotInRegistryException : std::exception {
public:
    const char * what() const noexcept override {
        return "Такой ключ отсутствует в реестре!";
    }
};

class VectorSizeIsZeroException : std::exception {
public:
    const char * what() const noexcept override {
        return "В векторе нет элементов!";
    }
};

// #endif

#ifdef __MODULE_33__
/* Задание 3. Реестр данных на шаблонах
 *  Что нужно сделать:
 *  С помощью шаблонов реализуйте простой класс реестра, хранящий произвольные типы значений по
 *  ключам произвольного типа. Ключи при этом могут повторяться.
 *  Реестр должен поддерживать следующие операции: добавление элемента с ключом, удаление элементов
 *  с заданным ключом, вывод всех значений с ключами в консоль, поиск элементов по ключу.
 *  Для тестирования программы предусмотрите ввод данных и команд из стандартной консоли: 
 *  - add — добавить элемент с ключом;
 *  - remove — удалить все элементы с заданным ключом;
 *  - print — напечатать на экране все элементы с их ключами;
 *  - find — найти все элементы по их ключу.
 *  Данный словарь должен работать на значениях и ключах следующих типов: int, double, std::string.
 *  
 *  Рекомендации:
 *  - Для реализации можете использовать стандартный шаблон std::vector, который в свою очередь уже
 *    будет хранить ваши пары ключей и значений.
 *  - Сама пара ключа и значения как раз и будет классом (или струкурой), шаблонизированным двумя
 *    типами: типом значения и типом ключа. 
 *  - При желании вы можете создать отдельную шаблонизированную функцию с вводом команд и их данных.
 *  
 *  Что оценивается:
 *  Корректность работы логики программы, реализованной с помощью шаблонов. */

#include <iostream>
#include <vector>
#include <exception>
#include "Module_33.hpp"
#include "Module_33_Exceptions.hpp"

template<typename T1, typename T2>
class MyPair {
private:
    T1 key;
    T2 value;
public:
    MyPair(T1 _key, T2 _value) : key(_key), value(_value) {};
    T1 first() const noexcept { return key; };
    T2 second() const noexcept { return value; };
    friend std::ostream& operator<< (std::ostream& Os, const MyPair<T1, T2> mypair) {
        Os << "{ " << mypair.key << " : " << mypair.value << " }";
        return Os;
    }
};

template<typename T1, typename T2>
class MyRegister {
private:
    std::vector<MyPair<T1, T2>> reg;
public:
    MyRegister(std::vector<MyPair<T1, T2>> v) {reg = v;};

    bool found_by_key(const T1 key) const {
        for (const MyPair<T1, T2>& mypair : reg) {
            if (mypair.first() == key) {
                return true;
            }
        }
        return false;
    }

    std::vector<MyPair<T1, T2>>::const_iterator find_by_key(const T1& key) const {
        for (auto it = reg.begin(); it != reg.end(); it++) {
            if (it->first() == key) {
                return it;
            }
        }
        return reg.end();
    }

    void add(const T1 key, const T2 value) {
        reg.push_back(MyPair(key, value));
    }

    void remove(const T1 key) {
        auto it = find_by_key(key);
        if (it != reg.end()) {
            reg.erase(it);
        } else {
            throw KeyIsNotInRegistryException();
        }
    }

    std::vector<MyPair<T1, T2>>::const_iterator begin() const noexcept {
        return reg.begin();
    }

    std::vector<MyPair<T1, T2>>::const_iterator end() const noexcept {
        return reg.end();
    }

    void print() const noexcept {
        for (auto it = reg.begin(); it != reg.end(); it++) {
            std::cout << *it << "\n";
        }
    }

    std::vector<MyPair<T1, T2>> find(const T1 key) const noexcept {
        std::vector<MyPair<T1, T2>> result;
        for (const MyPair<T1, T2>& mypair : reg) {
            if(mypair.first() == key) {
                result.push_back(mypair);
            }
        }
        return result;
    }
};

void Task_33_3() {
    std::cout << equals << string_tasks[2] << equals;

    // std::cout << "Ключ - число (1), вещественное число (2) или строка (3)? ";
    MyRegister<int, int> registry({{1, 2}, {3, 4}, {5, 6}, {7, 8}});
    std::cout << 1 << " " << registry.found_by_key(1) << "\n";
    std::cout << 2 << " " << registry.found_by_key(2) << "\n";
    std::cout << 3 << " " << registry.found_by_key(3) << "\n";
    std::cout << 4 << " " << registry.found_by_key(4) << "\n";
    std::cout << 5 << " " << registry.found_by_key(5) << "\n";
    std::cout << 6 << " " << registry.found_by_key(6) << "\n";
    std::cout << 7 << " " << registry.found_by_key(7) << "\n";
    std::cout << 8 << " " << registry.found_by_key(8) << "\n";
    std::cout << "\n";
    registry.print();
    try {
        registry.remove(3);
        std::cout << "Удалено значение по ключу: " << 3 << "\n";
    } catch (const KeyIsNotInRegistryException& X) {
        std::cout << X.what() << "\n";
    }
    registry.print();
    try {
        registry.remove(4);
    } catch (const KeyIsNotInRegistryException& X) {
        std::cout << X.what() << "\n";
    }
    registry.print();
    registry.add(1, 5);
    registry.print();
    
    MyRegister<int, int> r = MyRegister(registry.find(1));
    r.print();
}
#endif

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
static bool found_by_key(std::vector<MyPair<T1, T2>>& v, const T1 key) {
    for (const MyPair<T1, T2>& mypair : v) {
        if (mypair.first() == key) {
            return true;
        }
    }
    return false;
}

template<typename T1, typename T2>
static std::vector<MyPair<T1, T2>>::const_iterator find_by_key(const std::vector<MyPair<T1, T2>>& v, const T1& key) {
    for (auto it = v.begin(); it != v.end(); it++) {
        if (it->first() == key) {
            return it;
        }
    }
    return v.end();
}

template<typename T1, typename T2>
static void add(std::vector<MyPair<T1, T2>>& v, const T1 key, const T2 value) {
    v.push_back(MyPair(key, value));
}

/*! \brief Шаблонная функция remove
 *  \details функция реализует удаление одного элемента по ключу
 *  \param v[in] вектор пар <ключ - значение>
 *  \param key[in] ключ, по которому ищется элемент в векторе для удаления
 *  \exception \b KeyIsNotInRegistryException - ключ не найден в реестре
*/
template<typename T1, typename T2>
static void remove(std::vector<MyPair<T1, T2>>& v, const T1 key) {
    auto it = find_by_key(v, key);
    if (it != v.end()) {
        v.erase(it);
    } else {
        throw KeyIsNotInRegistryException();
    }
}

template<typename T1, typename T2>
static void print(std::vector<MyPair<T1, T2>>& v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << *it << "\n";
    }
}

template<typename T1, typename T2>
static std::vector<MyPair<T1, T2>> find(std::vector<MyPair<T1, T2>>& v, const T1 key) {
    std::vector<MyPair<T1, T2>> result;
    for (const MyPair<T1, T2>& mypair : v) {
        if(mypair.first() == key) {
            result.push_back(mypair);
        }
    }
    return result;
}

void Task_33_3() {
    std::cout << equals << string_tasks[2] << equals;

    // std::cout << "Ключ - число (1), вещественное число (2) или строка (3)? ";
    std::vector<MyPair<int, int>> v = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    std::cout << 1 << " " << found_by_key(v, 1) << "\n";
    std::cout << 2 << " " << found_by_key(v, 2) << "\n";
    std::cout << 3 << " " << found_by_key(v, 3) << "\n";
    std::cout << 4 << " " << found_by_key(v, 4) << "\n";
    std::cout << 5 << " " << found_by_key(v, 5) << "\n";
    std::cout << 6 << " " << found_by_key(v, 6) << "\n";
    std::cout << 7 << " " << found_by_key(v, 7) << "\n";
    std::cout << 8 << " " << found_by_key(v, 8) << "\n";
    std::cout << "\n";
    print(v);
    try {
        remove(v, 3);
        std::cout << "Удалено значение по ключу: " << 3 << "\n";
    } catch (const KeyIsNotInRegistryException& X) {
        std::cout << X.what() << "\n";
    }
    print(v);
    try {
        remove(v, 4);
    } catch (const KeyIsNotInRegistryException& X) {
        std::cout << X.what() << "\n";
    }
    print(v);
    add(v, 1, 5);
    print(v);
    
    std::vector<MyPair<int, int>> r = find(v, 1);
    print(r);
}
#endif

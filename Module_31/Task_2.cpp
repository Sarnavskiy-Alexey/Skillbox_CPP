// #ifdef __MODULE_31__
/* Задание 2. Реализация умного указателя
 *  Что нужно сделать:
 *  1. Реализуйте умный указатель shared_ptr_toy с распределённым доступом и механикой подсчёта
 *     ссылок для класса Toy, реализованного в задании. 
 *     Указатель должен: 
 *     - иметь все стандартные методы класса,
 *     - быть функциональной заменой использованию shared_ptr<Toy>.
 *  2. Реализуйте свободную функцию make_shared_toy, которая принимает набор аргументов и
 *     конструирует игрушку от названия или при помощи копии другой игрушки.
 *  
 *  Советы и рекомендации:
 *  Не забудьте уменьшить число ссылок на единицу в деструкторе умного указателя. Когда на счётчике
 *  появится значение 0, удалите объект.
 *  - Вы можете использовать перегрузки под разные типы. Их количество ограничено.
 *  
 *  Чек-лист для проверки задания:
 *  - Класс называется shared_ptr_toy.
 *  - Реализованы конструктор, конструктор копий, оператор присваивания копированием, деструктор и
 *    функция make_shared. */

#include <iostream>
#include <string>
#include "Module_31.hpp"

// класс Toy
class Toy {
private:
    std::string name;
public:
    Toy(std::string _name) : name(_name) {};
    Toy() : name("Ball") {};
    Toy(const Toy& toy) : name(toy.name) {};
};

// класс shared_ptr_toy
class shared_ptr_toy {
private:
    unsigned int* masters;
    Toy* obj;
public:
    shared_ptr_toy() {
        std::cout << "OBJ CREATED 1!\n";
        obj = new Toy;
        masters = new unsigned int(1);
    }
    shared_ptr_toy(const Toy& toy) {
        std::cout << "OBJ CREATED 2!\n";
        obj = new Toy(toy);
        masters = new unsigned int(1);
    }
    shared_ptr_toy(const shared_ptr_toy& spt) {
        std::cout << "OBJ CREATED 3!\n";
        obj = spt.obj;
        masters = spt.masters;
        (*masters)++;
    }
    shared_ptr_toy& operator= (const shared_ptr_toy& spt) {
        if (this != &spt) {
            if (obj != nullptr) {
                delete obj;
            }
            if (masters != nullptr) {
                delete masters;
            }
            masters = spt.masters + 1;
            obj = new Toy(*spt.obj);
        }
        return *this;
    }
    ~shared_ptr_toy() {
        (*masters)--;
        if (*masters == 0) {
            std::cout << "OBJ DELETED!\n";
            delete obj;
            delete masters;
        }
        obj = nullptr;
        masters = nullptr;
    }
};

shared_ptr_toy make_shared_toy(std::string name) {
    return shared_ptr_toy(name);
}

shared_ptr_toy make_shared_toy(const Toy& toy) {
    return shared_ptr_toy(toy);
}

void Task_31_2() {
    std::cout << equals << string_tasks[1] << equals;

    shared_ptr_toy pa;
    shared_ptr_toy pb(pa);
    shared_ptr_toy pc = make_shared_toy("Ball");
    shared_ptr_toy pd = make_shared_toy(Toy("Ball"));
}
// #endif

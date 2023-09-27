// #ifdef __MODULE_31__
/* Задание 1. Использование умного указателя
 *  Что нужно сделать:
 *  1. Реализуйте класс Dog, который использует стандартный умный указатель shared_ptr для класса
 *     Toy.
 *  2. Реализуйте у класса Dog метод getToy, с помощью которого собака подбирает игрушку. 
 *     a. Если у собаки уже есть эта игрушка, необходимо вывести в консоль фразу: I already have
 *        this toy.
 *     b. Если в данный момент игрушка находится у другой собаки, нужно вывести в консоль: Another
 *        dog is playing with this toy.
 *     c. Если игрушка свободна, собака подбирает её.
 *  3. Реализуйте у класса Dog метод dropToy, с помощью которого собака бросает игрушку на пол,
 *     после чего другая может подобрать её. 
 *     a. Если у собаки в этот момент нет игрушки, в консоль необходимо вывести: Nothing to drop.
 *  
 *  Советы и рекомендации:
 *  - Чтобы узнать, у скольких собак в данный момент есть игрушка, можно использовать метод 
 *    use_count() у класса shared_ptr. При этом необходимо учитывать, что создание shared_ptr от
 *    класса Toy тоже увеличивает показатели счётчика.
 *  - Чтобы увидеть удаление класса Toy, используйте следующее определение:
 *    class Toy {
 *    public:
 *       Toy(const std::string& name) {
 *           name_ = name;
 *       }
 *       std::string getNmae() {
 *           return name_;
 *       }
 *       ~Toy() {
 *           std::cout << "Toy " << name_ << " was dropped " << std::endl;
 *       }
 *    private:
 *       std::string name_;
 *    }; */

#include <iostream>
#include <string>
#include <memory>
#include "Module_31.hpp"

class Toy {
private:
    std::string name;
public:
    Toy(std::string _name) : name(_name) {};
    Toy() : name("Ball") {};
    std::string getName() const { return name; }
    ~Toy() { std::cout << "Toy " << name << " was dropped!\n"; }
};

class Dog {
private:
    std::shared_ptr<Toy> lovelyToy;
    std::string name;
public:
    Dog(std::string _name, std::shared_ptr<Toy>& toy) : name(_name), lovelyToy(toy) {};
    Dog(std::string _name) : name(_name) {};
    Dog() : name("Snow") {};
    Dog(std::shared_ptr<Toy>& toy) : Dog("Snow", toy) {};
    void getToy(const std::shared_ptr<Toy>& toy) {
        if (toy.get() == lovelyToy.get()) {
            std::cout << "I already have this toy!\n";
        } else if (toy.use_count() > 1) {
            std::cout << "Another dog is playing with this toy!\n";
        } else {
            lovelyToy = toy;
            std::cout << "I get it!\n";
        }
    }
    void dropToy() {
        if (lovelyToy.use_count() > 1) {
            lovelyToy.reset();
            std::cout << "I dropped the toy!\n";
        } else {
            std::cout << "Nothing to drop!\n";
        }
    }
    ~Dog() {
        if (lovelyToy.use_count() > 1) {
            std::cout << "Dog was deleted!\n";
        } else {
            std::cout << "Dog without toy was deleted!\n";
        }
    }
};

void Task_31_1() {
    std::cout << equals << string_tasks[0] << equals;
    
    std::shared_ptr<Toy> toy_ptr = std::make_shared<Toy>();
    std::shared_ptr<Dog> da = std::make_shared<Dog>("Druzhok");
    std::shared_ptr<Dog> db = std::make_shared<Dog>();
    std::shared_ptr<Dog> dc = std::make_shared<Dog>();

    da.get()->dropToy();
    da.get()->getToy(toy_ptr);
    da.get()->dropToy();
    db.get()->getToy(toy_ptr);

    da.reset();
    db.get()->getToy(toy_ptr);

    db.reset();
    dc.reset();
    toy_ptr.reset();
}
// #endif

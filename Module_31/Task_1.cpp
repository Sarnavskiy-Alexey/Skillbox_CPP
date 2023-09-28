#ifdef __MODULE_31__
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
#include <limits>
#include <sstream>
#include <vector>
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
    std::string name = "";
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

static unsigned int safe_enter(std::string invite_str, std::string error_str) {
    unsigned int X;
    do {
        std::cout << invite_str;
        std::cin >> X;
        if (X == 0)
            std::cout << error_str;
    } while (X == 0);
    
    return X;
}

static bool check_uint(std::string numStr) {
    for (unsigned int i = 0; i < numStr.length(); i++) {
        if (numStr[i] < '0' || numStr[i] > '9') {
            return false;
        }
    }
    return true;
}

static void help() {
    std::cout << "  connect <игрушка> <собака>    - соединить номер игрушки (от 0) с номером собаки (от 0)\n";
    std::cout << "  disconnect <игрушка> <собака> - разъединить номер игрушки (от 0) с номером собаки (от 0)\n";
    std::cout << "  help                          - вывод данного сообщения\n";
    std::cout << "  exit                          - выход из задания\n";
    std::cout << "\n";
}

static bool check_to_discon_and_con(std::string command_part) {
    std::string toyNum, dogNum, err;
    std::stringstream buf(command_part);
    buf >> toyNum >> dogNum >> err;

    return (toyNum.length() && dogNum.length() && !err.length() &&
            check_uint(toyNum) && check_uint(dogNum));
}

void Task_31_1() {
    std::cout << equals << string_tasks[0] << equals;

    unsigned int dogCount, toyCount;
    std::vector<std::shared_ptr<Dog>> dogs;
    std::vector<std::shared_ptr<Toy>> toys;
    std::string userCommand, command;

    dogCount = safe_enter("Введите количество собак: ",
                          "Количество собак должно быть больше нуля!\n");
    toyCount = safe_enter("Введите количество игрушек: ",
                          "Количество игрушек должно быть больше нуля!\n");
    
    for (unsigned int i = 0; i < dogCount; i++) {
        std::string name;
        std::cout << "Введите имя собаки №" << i << ": ";
        std::cin >> name;
        dogs.push_back(std::make_shared<Dog>(name));
    }
    for (unsigned int i = 0; i < toyCount; i++) {
        std::string name;
        std::cout << "Введите имя игрушки №" << i << ": ";
        std::cin >> name;
        toys.push_back(std::make_shared<Toy>(name));
    }

    // очистка буфера ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        std::cout << "Введите команду (help - помощь): ";
        std::getline(std::cin, userCommand);
        std::stringstream command_buf(userCommand);
        command_buf >> command;

        if (command == "help") {
            help();
        } else if (command == "exit") {
            std::cout << "Работа с заданием окончена!\n";
            break;
        } else if (command == "connect" && (userCommand.length() > command.length() + 1)) {
            if (check_to_discon_and_con(command_buf.str().substr(command.length() + 1))) {
                std::string toyNum_str, dogNum_str;
                command_buf >> toyNum_str >> dogNum_str;
                unsigned int toyNum = std::stoul(toyNum_str);
                unsigned int dogNum = std::stoul(dogNum_str);

                if (toyNum < toys.size() && dogNum < dogs.size()) {
                    dogs[dogNum].get()->getToy(toys[toyNum]);
                } else {
                    std::cout << "Взятие этой игрушки этой собакой невозможно!\n";
                }
            } else {
                std::cout << "Команда не распознана!\n";
            }
        } else if (command == "disconnect" && (userCommand.length() > command.length() + 1)) {
            if (check_to_discon_and_con(command_buf.str().substr(command.length() + 1))) {
                std::string toyNum_str, dogNum_str;
                command_buf >> toyNum_str >> dogNum_str;
                unsigned int toyNum = std::stoul(toyNum_str);
                unsigned int dogNum = std::stoul(dogNum_str);

                if (toyNum < toys.size() && dogNum < dogs.size()) {
                    dogs[dogNum].get()->dropToy();
                } else {
                    std::cout << "Взятие этой игрушки этой собакой невозможно!\n";
                }
            } else {
                std::cout << "Команда не распознана!\n";
            }
        } else {
            std::cout << "Команда не распознана! Введите \"help\" для помощи.\n";
        }
    } while (userCommand != "exit");

    for (unsigned int i = 0; i < dogs.size(); i++) {
        dogs[i].reset();
    }
    for (unsigned int i = 0; i < toys.size(); i++) {
        toys[i].reset();
    }
}
#endif

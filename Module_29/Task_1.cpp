#ifdef __MODULE_29__
/* Задача 1. Суперпёс
 *  Возьмём решение из видео. Все наши животные могут мяукать и гавкать, то есть издавать звуки в
 *  соответствии со своим классом. Но что, если нужно добавить им новое поведение, например, научить
 *  плавать или стоять на задних лапах. Рассмотрим класс Dog: все собаки умеют лаять и бегать, а
 *  некоторые собаки умеют хорошо плавать. Чтобы добавить эти качества классу Dog, мы можем создать
 *  ещё один класс «плавающих» животных и наследовать от него наш класс. Но что, если не все собаки
 *  умеют хорошо плавать, а некоторые из них совсем не умеют плавать.Наша задача — построить класс
 *  Dog таким образом, чтобы к его объектам можно было выборочно добавлять новые умения, но при этом
 *  не менять поведение основного класса. Список умений будет вызываться с помощью метода
 *  show_talents().
 *  
 *  Что нужно сделать:
 *  Создайте класс Dog, к которому можно добавлять новые способности.
 *  Создайте абстрактный класс «Талант» (Talent), от которого будут наследоваться все добавляемые
 *  способности. Пока таких способностей три: умение плавать (Swimming), умение танцевать (Dancing),
 *  умение считать (Counting), но можете добавить и другие.
 *  Создайте у класса Dog метод show_talents() для показа всех способностей, которыми обладает
 *  собака.
 *  
 *  Требования к реализации:
 *  - Класс Talent должен быть абстрактным. Это значит, что объекты такого класса мы создать не
 *    сможем, так как одна из его функций объявлена как «чисто» виртуальная (pure virtual).
 *  - Каждая способность, наследуемая от абстрактного класса Talent, должна быть представлена в виде
 *    отдельного класса.
 *  
 *  Пример выполнения:
 *  Создаём собаку с именем Steve:
 *  
 *      Dog dog1("Steve")
 *  
 *  Добавляем ей умение танцевать и плавать.
 *  Если мы сделаем запрос умений show_talents(), то на экран будет выведено:
 *  This is Steve and it has some talents: 
 *              It can “Dance” 
 *              It can “Swim”
 *  
 *  Советы и рекомендации:
 *  - Для хранения способностей можно использовать вектор.
 *  - Для создания абстрактного класса рекомендуем пересмотреть видео, где функция voice в классе
 *    Animal была объявлена «чисто» виртуальной. Это поможет в выполнении задания. */

#include <iostream>
#include <vector>
#include <set>
#include "Module_29.hpp"

class Talent {
public:
    Talent() {};
    virtual void talent() = 0;
};

class Swim : public Talent {
public:
    Swim() {};
    virtual void talent() {
        std::cout << "It can \"Swim\"\n";
    }
};

class Dance : public Talent {
public:
    Dance() {};
    virtual void talent() {
        std::cout << "It can \"Dance\"\n";
    }
};

class Count : public Talent {
public:
    Count() {};
    virtual void talent() {
        std::cout << "It can \"Count\"\n";
    }
};

class Dog {
private:
    enum class E_Talent {
        Swim,
        Dance,
        Count
    };
    std::vector<Talent*> talents;
    std::set<E_Talent> added_talents;
public:
    void show_talents() {
        for (Talent*& talent : talents) {
            talent->talent();
        }
    }
    void add_swimming() {
        Talent* s = new Swim();
        if (added_talents.find(E_Talent::Swim) == added_talents.end()) {
            talents.push_back(s);
            added_talents.insert(E_Talent::Swim);
        }
    }
    void add_dancing() {
        Talent* d = new Dance();
        if (added_talents.find(E_Talent::Dance) == added_talents.end()) {
            talents.push_back(d);
            added_talents.insert(E_Talent::Dance);
        }
    }
    void add_counting() {
        Talent* c = new Count();
        if (added_talents.find(E_Talent::Count) == added_talents.end()) {
            talents.push_back(c);
            added_talents.insert(E_Talent::Count);
        }
    }
};

void Task_29_1() {
    std::cout << equals << string_tasks[0] << equals;

    Dog dog;
    std::cout << "    Добавлена одна способность\n";
    dog.add_counting();
    dog.show_talents();
    std::cout << "    Добавлена уже имеющаяся способность\n";
    dog.add_counting();
    dog.show_talents();
    std::cout << "    Добавлены оставшиеся две способности\n";
    dog.add_dancing();
    dog.add_swimming();
    dog.show_talents();
}
#endif

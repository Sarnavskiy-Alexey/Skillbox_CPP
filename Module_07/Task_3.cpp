#ifdef __MODULE_07__
/* Задание 3. Красный Марс
 *  В «Спейс Инжиниринг» были впечатлены тем, как вы справились с кофемашиной и решили отдать вам
 *  на аутсорс разработку программы для нового робота-разведчика поверхности Марса. Это первый
 *  прототип, поэтому он тестируется в прямоугольном помещении размером 15 на 20 метров. Марсоход
 *  высаживается в центре комнаты, после чего управление им передаётся оператору — пользователю
 *  вашей программы. Программа спрашивает, в какую сторону оператор хочет направить робота: север
 *  (клавиша W), юг (клавиша S), запад (клавиша A) или восток (клавиша D). Оператор делает выбор,
 *  марсоход перемещается на 1 метр в эту сторону и программа сообщает новую позицию марсохода.
 *  Если марсоход упёрся в стену, то он не должен пытаться перемещаться в сторону стены, в этом
 *  случае его позиция не меняется. */

#include <iostream>
#include "Module_07.hpp"

void Task_07_3() {
    std::cout << equals << string_tasks[2] << equals;

    const int roomWidth = 15, roomLength = 20;
    int X = roomWidth / 2, Y = roomLength / 2;
    std::string userChoice;
    std::cout << "Для движения марсохода в комнате воспользуйтесь клавишами WASD.\n"
        << "Для выхода из управления марсоходом нажмите Q.\n";
    
    while (true) {
        std::cout << "[Программа]: Марсоход находитмся на позиции " << X << ", " << Y
            << ", введите команду:\n";
        std::cout << "[Оператор]: ";
        std::cin >> userChoice;
        if (userChoice == "W" || userChoice == "w") {
            if (Y + 1 < roomLength) Y++;
            else std::cout << "На пути марсохода встречена стена!\n";
        }
        else if (userChoice == "S" || userChoice == "s") {
            if (Y - 1 > 0) Y--;
            else std::cout << "На пути марсохода встречена стена!\n";
        }
        else if (userChoice == "D" || userChoice == "d") {
            if (X + 1 < roomWidth) X++;
            else std::cout << "На пути марсохода встречена стена!\n";
        }
        else if (userChoice == "A" || userChoice == "a") {
            if (X - 1 > 0) X--;
            else std::cout << "На пути марсохода встречена стена!\n";
        }
        else if (userChoice == "Q" || userChoice == "q")
            break;
        else
            std::cout << "Введена неверная команда!\n";
    }

    std::cout << "Управление марсоходом окончено!\n";
}
#endif

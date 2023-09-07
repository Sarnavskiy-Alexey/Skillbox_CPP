#ifdef __MODULE_26__
/* Задание 1. Реализация имитации аудиоплеера
 *  Что нужно сделать
 *  С помощью классов реализуйте программу имитации работы аудиоплеера. В плеере находится несколько
 *  аудиозаписей, доступных для воспроизведения. Для них вы должны создать отдельный класс Track.
 *  Полями этого класса должны быть: название, дата создания (здесь вы можете использовать тип
 *  std::tm) и продолжительность записи в секундах.
 *  Сам плеер тоже реализуйте с помощью класса. Внутри он должен содержать список доступных записей
 *  и нужные для логики работы плеера поля.
 *  Пользователь взаимодействует с программой с помощью команд:
 *  - Команда play запрашивает у пользователя название записи для воспроизведения и начинает её
 *    воспроизведение. Воспроизведение симулируется с помощью вывода в консоль всей информации о
 *    записи. Если произведение какой-то записи уже начато, ничего не происходит.
 *  - Команда pause. Ставит запись на паузу, о чём выводит соответствующее сообщение в консоль. Если
 *    запись уже на паузе или не воспроизводится вовсе, ничего не происходит.
 *  - Команда next переходит к следующей записи для воспроизведения. Запись при этом выбирается
 *    случайно, как будто плеер работает в режиме shuffle.
 *  - Команда stop прекращает воспроизведение текущей записи, если таковая имеется. Об этом
 *    выводится сообщение в консоль. Два раза остановить воспроизведение невозможно, так что команда
 *    должна срабатывать только в первом случае.
 *  - Команда exit — выход из программы.
 *  
 *  Советы и рекомендации
 *  Забудьте про отдельные глобальные функции и используйте возможности классов и методов по
 *  максимуму. */

#include <iostream>
#include <limits>
#include "../Module_26.hpp"
#include "MusicPlayer.hpp"

enum class E_Command {
    play,
    pause,
    next,
    stop,
    help,
    exit
};

static const std::string commands[] = {
    "play",
    "pause",
    "next",
    "stop",
    "help",
    "exit"
};

void Task_26_1() {
    std::cout << equals << string_tasks[0] << equals;

    std::string command;
    E_Command e_command;
    MusicPlayer player;
    do {
        std::cout << "Введите команду: ";
        std::cin >> command;
        if (command == commands[(unsigned int)E_Command::play]) {
            player.play();
            e_command = E_Command::play;
        } else if (command == commands[(unsigned int)E_Command::pause]) {
            player.pause();
            e_command = E_Command::pause;
        } else if (command == commands[(unsigned int)E_Command::next]) {
            player.next();
            e_command = E_Command::next;
        } else if (command == commands[(unsigned int)E_Command::stop]) {
            player.stop();
            e_command = E_Command::stop;
        } else if (command == commands[(unsigned int)E_Command::help]) {
            std::cout << "\"play\"  - воспроизведение записи\n";
            std::cout << "\"pause\" - приостановка воспроизведения записи\n";
            std::cout << "\"next\"  - воспроизведение следующей записи\n";
            std::cout << "\"stop\"  - остановка воспроизведения записи\n";
            std::cout << "\"help\"  - вывод этого сообщения\n";
            std::cout << "\"exit\"  - выход\n";
            e_command = E_Command::help;
        } else if (command == commands[(unsigned int)E_Command::exit]) {
            e_command = E_Command::exit;
        } else {
            std::cout << "Something is wrong!\n";
        }
    } while (e_command != E_Command::exit);
}
#endif

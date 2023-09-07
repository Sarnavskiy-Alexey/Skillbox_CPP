#ifdef __MODULE_26__
/* Объявление класса Monitor */
#pragma once

#include <string>
#include "Window.hpp"

class Monitor {
private:
    unsigned int m_max_y;
    unsigned int m_max_x;
    Window m_window;

    void move(std::string part_command);
    void resize(std::string part_command);
    void display() const;
    void help() const;
    void close() const;

    bool check_int(std::string s);
public:
    Monitor();

    // использование: do..while(!cmd(command));
    bool cmd(std::string command);
};

#endif

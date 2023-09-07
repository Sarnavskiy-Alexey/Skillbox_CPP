#ifdef __MODULE_26__
/* Определение класса Monitor */

#include <iostream>
#include <sstream>
#include "Monitor.hpp"

Monitor::Monitor() {
    this->m_max_x = 80;
    this->m_max_y = 50;
    std::cout << "Монитор включен!\n";
}

bool Monitor::check_int(std::string s) {
    if (s.length() > 0) {
        unsigned int beg = (s[0] == '-' ? 1 : 0);
        for (unsigned int i = beg; i < s.length(); i++) {
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

void Monitor::move(std::string part_command) {
    std::string x_offset, y_offset, err;
    std::stringstream buffer(part_command);
    
    buffer >> x_offset >> y_offset >> err;
    if (!x_offset.length() || !y_offset.length() || err.length()) {
        std::cout << "Команда не распознана!\n";
    } else {
        bool offsets_numbers = this->check_int(x_offset) && this->check_int(y_offset);
        if (offsets_numbers) {
            int result_x_offset = std::stol(x_offset);
            int result_y_offset = std::stol(y_offset);

            if ((unsigned int)((int)this->m_window.get_x() + result_x_offset) < this->m_max_x &&
                (unsigned int)((int)this->m_window.get_y() + result_y_offset) < this->m_max_y) {
                this->m_window.move(result_x_offset, result_y_offset);
                std::cout << "Окно смещено! Новые координаты окна: ("
                          << this->m_window.get_x() << ", "
                          << this->m_window.get_y() << ")\n";
            } else {
                std::cout << "Смещение превышает ширину или высоту монитора!\n";
            }

        } else {
            std::cout << "Команда не распознана!\n";
        }
    }
}

void Monitor::resize(std::string part_command) {
    std::string width, height, err;
    std::stringstream buffer(part_command);
    
    buffer >> width >> height >> err;
    if (!width.length() || !height.length() || err.length()) {
        std::cout << "Команда не распознана!\n";
    } else {
        bool offsets_numbers = this->check_int(width) && this->check_int(height);
        if (offsets_numbers) {
            unsigned int result_width = std::stoul(width);
            unsigned int result_height = std::stoul(height);
            if (result_width <= (this->m_max_x - this->m_window.get_x()) && result_width > 0 &&
                result_height <= (this->m_max_y - this->m_window.get_y()) && result_height > 0) {
                this->m_window.resize(result_width, result_height);
                std::cout << "Размер окна изменен! Теперь: "
                          << this->m_window.get_width() << "x"
                          << this->m_window.get_height() << "\n";
            } else {
                std::cout << "Изменение размера окна не произведено!\n";
            }
        } else {
            std::cout << "Команда не распознана!\n";
        }
    }
}

void Monitor::display() const {
    unsigned int window_x = this->m_window.get_x();
    unsigned int window_y = this->m_window.get_y();
    unsigned int width = this->m_window.get_width();
    unsigned int height = this->m_window.get_height();

    for (unsigned int y = 0; y < this->m_max_y; y++) {
        for (unsigned int x = 0; x < this->m_max_x; x++) {
            if (x >= window_x && x < (window_x + width) &&
                y >= window_y && y < (window_y + height)) {
                std::cout << 1;
            } else {
                std::cout << 0;
            }
        }
        std::cout << "\n";
    }
}

void Monitor::help() const {
    std::cout << "  move <x offset> <y offset> - смещение окна относительно текущих координат\n";
    std::cout << "  resize <width> <height>    - изменение размера окна\n";
    std::cout << "  display                    - отображение окна в консоли\n";
    std::cout << "  help                       - вывод данного сообщения\n";
    std::cout << "  close                      - закрытие окна и завершение работы\n";
}

void Monitor::close() const {
    std::cout << "Работа с монитором окончена!\n";
}

// использование: do..while(!cmd(command));
bool Monitor::cmd(std::string command) {
    std::string operation;
    std::stringstream buffer(command);

    buffer >> operation;
    if (operation == "move" && (command.length() > operation.length() + 1)) {
        this->move(buffer.str().substr(operation.length() + 1));
    } else if (operation == "resize" && (command.length() > operation.length() + 1)) {
        this->resize(buffer.str().substr(operation.length() + 1));
    } else if (operation == "display") {
        this->display();
    } else if (operation == "help") {
        this->help();
    } else if (operation == "close") {
        this->close();
        return true;
    } else {
        std::cout << "Команда не распознана! Введите \"help\" для помощи.\n";
    }

    return false;
}
#endif

#ifdef __MODULE_26__
/* Определение класса Window */

#include <iostream>
#include "Window.hpp"

Window::Window() {
    this->m_x = 0;
    this->m_y = 0;
    this->m_width = 1;
    this->m_height = 1;
}

Window::Window(unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    this->m_x = x;
    this->m_y = y;
    this->m_width = width;
    this->m_height = height;
}

void Window::move(int x_offset, int y_offset) {
        this->m_x = (unsigned int)((int)this->m_x + x_offset);
        this->m_y = (unsigned int)((int)this->m_y + y_offset);
}

void Window::resize(unsigned int width, unsigned int height) {
    this->m_width = width;
    this->m_height = height;
}

unsigned int Window::get_x() const {
    return this->m_x;
}

unsigned int Window::get_y() const {
    return this->m_y;
}

unsigned int Window::get_width() const {
    return this->m_width;
}

unsigned int Window::get_height() const {
    return this->m_height;
}

#endif

#ifdef __MODULE_26__
/* Объявление класса Window */
#pragma once

class Window {
private:
    unsigned int m_x;
    unsigned int m_y;
    unsigned int m_width;
    unsigned int m_height;
public:
    Window();
    Window(unsigned int x, unsigned int y, unsigned int width, unsigned int height);

    void move(int x_offset, int y_offset);
    void resize(unsigned int width, unsigned int height);

    unsigned int get_x() const;
    unsigned int get_y() const;
    unsigned int get_width() const;
    unsigned int get_height() const;
};

#endif

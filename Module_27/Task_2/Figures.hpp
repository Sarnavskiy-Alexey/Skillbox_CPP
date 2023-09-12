#ifdef __MODULE_27__
#pragma once
#include <cmath>
#include <string>

// константа пи
const double pi = 3.14159265358979323846;

// класс-перечисление цветов фигуры
enum class Color {
    none,
    red,
    blue,
    green,
    size
};

// константа для выдачи в консоль цвета
static const std::string Colors[] = {
    "none", "red", "blue", "green"
};

// класс координаты
class Coordinates {
private:
    double x = 0.0;
    double y = 0.0;
public:
    Coordinates(const double x, const double y) : x(x), y(y) {}
    Coordinates() {}

    double get_x() const { return x; }
    double get_y() const { return y; }
    void set_x(double x) { this->x = x; }
    void set_y(double y) { this->y = y; }
};

// класс фигуры, общий для круга, квадрата, треугольника и прямоугольника
class Figure {
protected:
    Coordinates center;
    Color color = Color::none;
public:
    Figure(const Coordinates& center, const Color& color = Color::none) : center(center), color(color) {}
    Figure() {}

    void set_color(const Color& color) { this->color = color; };
    Color get_color() const { return color; };
    void set_coordinates(const Coordinates& c) { this->center = c; };
};

// класс круга
class Circle : public Figure {
private:
    double radius = 0.0;
public:
    Circle() {}

    double sqr() const;
    void set_radius(double r) { radius = r; }
    double get_radius() const { return radius; }
    void get_covering_rect(Coordinates& c1, Coordinates& c2) const;
};

// класс квадрата
class Square : public Figure {
private:
    double edgeLength = 0.0;
public:
    Square() {}

    double sqr() const;
    void set_edge_length(double el) { edgeLength = el; }
    double get_edge_length() const { return edgeLength; }
    void get_covering_rect(Coordinates& c1, Coordinates& c2) const;
};

// класс треугольника
class Triangle : public Figure {
private:
    double edgeLength = 0.0;
public:
    Triangle() {}

    double sqr() const;
    void set_edge_length(double el) { edgeLength = el; }
    double get_edge_length() const { return edgeLength; }
    void get_covering_rect(Coordinates& c1, Coordinates& c2) const;
};

// класс прямоугольника
class Rectangle : public Figure {
private:
    double width = 0.0;
    double height = 0.0;
public:
    Rectangle() {}

    double sqr() const;
    void set_width(double w) { width = w; }
    void set_height(double w) { height = w; }
    double get_width() const { return width; }
    double get_height() const { return height; }
    void get_covering_rect(Coordinates& c1, Coordinates& c2) const;
};

#endif

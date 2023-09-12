#ifdef __MODULE_27__
#include "Figures.hpp"

double Circle::sqr() const {
    return radius * radius * pi;
}

double Square::sqr() const {
    return edgeLength * edgeLength;
}

double Triangle::sqr() const {
    return edgeLength * edgeLength * std::sqrt(3.0) / 4.0;
}

double Rectangle::sqr() const {
    return width * height;
}

void Circle::get_covering_rect(
                               Coordinates& c1, // левый верхний угол описывающего прямоугольника
                               Coordinates& c2  // правый нижний угол описывающего прямоугольника
                              ) const {
    c1.set_x(center.get_x() - radius);
    c1.set_y(center.get_y() + radius);
    c2.set_x(center.get_x() + radius);
    c2.set_y(center.get_y() - radius);
}

void Square::get_covering_rect(
                               Coordinates& c1, // левый верхний угол описывающего прямоугольника
                               Coordinates& c2  // правый нижний угол описывающего прямоугольника
                              ) const {
    c1.set_x(center.get_x() - edgeLength / 2.0);
    c1.set_y(center.get_y() + edgeLength / 2.0);
    c2.set_x(center.get_x() + edgeLength / 2.0);
    c2.set_y(center.get_y() - edgeLength / 2.0);
}

void Triangle::get_covering_rect(
                               Coordinates& c1, // левый верхний угол описывающего прямоугольника
                               Coordinates& c2  // правый нижний угол описывающего прямоугольника
                              ) const {
    c1.set_x(center.get_x() - edgeLength / 2.0);
    c1.set_y(center.get_y() + edgeLength * std::sqrt(3.0) / 2.0);
    c2.set_x(center.get_x() + edgeLength / 2.0);
    c2.set_y(center.get_y() - edgeLength * std::sqrt(3.0) / 2.0);
}

void Rectangle::get_covering_rect(
                               Coordinates& c1, // левый верхний угол описывающего прямоугольника
                               Coordinates& c2  // правый нижний угол описывающего прямоугольника
                              ) const {
    c1.set_x(center.get_x() - width / 2.0);
    c1.set_y(center.get_y() + height / 2.0);
    c2.set_x(center.get_x() + width / 2.0);
    c2.set_y(center.get_y() - height / 2.0);
}

#endif

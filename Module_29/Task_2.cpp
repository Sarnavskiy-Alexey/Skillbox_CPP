#ifdef __MODULE_29__
/* Задача 2. Интерфейс Shape (дополнительное задание)
 *  У вас есть набор классов различных геометрических фигур: круг(Circle), прямоугольник(Rectangle)
 *  и треугольник(Triangle), которые наследуются от общего класса геометрическая фигура (Shape).
 *  Каждый из этих классов имеет методы подсчёта площади, описывающего прямоугольника и взятия типа.
 *  Также есть общая функция printParams которая по переданному ей указателю на объект типа
 *  геометрическая фигура выводит на экран тип фигуры.
 *  
 *  Что нужно сделать:
 *  Создайте интерфейс Shape (фигуру), который предоставляет следующие методы:
 *  — virtual double square() = 0; — возвращает площадь конкретной фигуры;
 *  — virtual BoundingBoxDimensions dimensions() = 0; — размеры описывающего прямоугольника;
 *  BoundingBoxDimensions — простая структура, которая содержит ширину и высоту;
 *  — virtual std::string type() = 0; — название конкретного типа, например, вернуть строку Triangle
 *  для класса Triangle;
 *  void printParams(Shape *shape) — сюда можно будет передавать любые фигуры:
 *  { 
 *     std::cout <<"Type: " << shape->type() << std::endl;
 *  комбинация virtual … = 0; — создаёт чисто виртуальный метод. Это означает, что такой метод
 *  обязательно должен быть переопредёлен в классе-наследнике. Если программист пронаследует свой
 *  класс от такого интерфейса, то компилятор будет ругаться на отсутствие методов, описанных как
 *  virtual … = 0. То есть программист будет вынужден добавить такие методы в свой класс, чтобы
 *  создать объект такого типа.
 *     ….
 *  }
 *  Создайте классы-наследники Shape: Circle, Rectangle и Triangle.
 *  У каждого из классов будет разный набор полей: у треугольника будут три стороны в виде
 *  переменных double, у круга — радиус, а у прямоугольника — длина и ширина. Так как все они
 *  наследуются от Shape, в каждом из классов следует реализовать методы нахождения размерности,
 *  площади и метод, возвращающий название типа.
 *  Площадь треугольника при известных длинах сторон находится при помощи формулы Герона:
 *  sqrt(p * (p - a) * (p - b) * (p - c)), где p — полупериметр.
 *  Размеры описывающего прямоугольника для треугольника находятся по похожей формуле — сначала
 *  находим радиус описанной окружности:
 *  a * b * c / (4 * sqrt(p*(p - a)*(p - b)*(p - c))), где р — снова полупериметр.
 *  Затем умножаем его на два и получаем сторону квадрата, в который помещён треугольник.
 *  В функции main вызовите printParams со всеми типами, которые вы создали.
 *  
 *  Пример:
 *  Triangle t(3,4,5); 
 *      printParams(&t);
 *  
 *  Вывод:
 *  Type: Triangle 
 *  Square: 6 
 *  Width: 5 
 *  Height: 5 */

#include <iostream>
#include <cmath>
#include "Module_29.hpp"

struct BoundingBoxDimensions {
    double width = 0.0;
    double height = 0.0;
};

class Shape {
public:
    Shape() {};
    virtual double square() = 0;
    virtual BoundingBoxDimensions dimensions() = 0;
    virtual std::string type() = 0;
};

class Circle : public Shape {
private:
    static inline const double PI = 3.14159265358979323846;
    double r;
public:
    Circle(double _r) {
        // если круг существует
        if (_r > 0) {
            r = _r;
        } else {
            std::cout << "Ошибка! Круг не существует!\n";
        }
    }

    virtual double square() {
        return PI * r * r;
    }

    virtual BoundingBoxDimensions dimensions() {
        BoundingBoxDimensions result;
        result.width = 2.0 * r;
        result.height = 2.0 * r;
        return result;
    }

    virtual std::string type() {
        return "Circle";
    }
};

class Rectangle : public Shape {
private:
    double w;
    double h;
public:
    Rectangle(double _w, double _h) {
        // если прямоугольник существует
        if (_w > 0 && _h > 0) {
            w = _w;
            h = _h;
        } else {
            std::cout << "Ошибка! Прямоугольник не существует!\n";
        }
    }

    virtual double square() {
        return w * h;
    }

    virtual BoundingBoxDimensions dimensions() {
        BoundingBoxDimensions result;
        result.width = w;
        result.height = h;
        return result;
    }

    virtual std::string type() {
        return "Rectangle";
    }
};

class Triangle : public Shape {
private:
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
public:
    // конструктор
    Triangle(double _a, double _b, double _c) {
        // если треугольник существует
        if (_a > 0 && _b > 0 && _c > 0 && (_a + _b > _c) && (_b + _c > _a) && (_c + _a > _b)) {
            a = _a;
            b = _b;
            c = _c;
        } else {
            std::cout << "Ошибка! Треугольник не существует!\n";
        }
    }

    virtual double square() {
        double pp = (a + b + c) / 2.0;
        return std::sqrt(pp * (pp - a) * (pp - b) * (pp - c));
    }

    virtual BoundingBoxDimensions dimensions() {
        BoundingBoxDimensions result;
        if (a != 0) {
            result.width = 2.0 * a * b * c / (4.0 * square());
            result.height = 2.0 * a * b * c / (4.0 * square());
        }
        return result;
    }

    virtual std::string type() {
        return "Triangle";
    }
};

// отклонение от правил в виде модификатора static обосновано тем, что все домашние работы
// реализуются в одном проекте, что означает, что интерфейсные функции могут повторяться
static void printParams(Shape* shape) {
    BoundingBoxDimensions bbd = shape->dimensions();
    std::cout <<"Type: " << shape->type() << "\n";
    std::cout << "Square: " << shape->square() << "\n";
    std::cout << "Width: " << bbd.width << "\n";
    std::cout << "Height: " << bbd.height << "\n";
}

void Task_29_2() {
    std::cout << equals << string_tasks[1] << equals;

    Shape * c = new Circle(5);
    printParams(c);
    Shape * r = new Rectangle(4, 5);
    printParams(r);
    Shape * t = new Triangle(3, 4, 5);
    printParams(t);
}
#endif
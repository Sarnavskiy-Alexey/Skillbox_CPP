#ifdef __MODULE_29__
#pragma once

#include <string>
const std::string string_tasks[] = {
    "\t\t\tЗадача 1. Суперпёс\n  Возьмём решение из видео. Все наши животные могут мяукать и гавкать, то есть издавать звуки в соответствии со своим классом. Но что, если нужно добавить им новое поведение, например, научить плавать или стоять на задних лапах. Рассмотрим класс Dog: все собаки умеют лаять и бегать, а некоторые собаки умеют хорошо плавать. Чтобы добавить эти качества классу Dog, мы можем создать ещё один класс «плавающих» животных и наследовать от него наш класс. Но что, если не все собаки умеют хорошо плавать, а некоторые из них совсем не умеют плавать.Наша задача — построить класс Dog таким образом, чтобы к его объектам можно было выборочно добавлять новые умения, но при этом не менять поведение основного класса. Список умений будет вызываться с помощью метода show_talents().\n\n  Что нужно сделать:\n  Создайте класс Dog, к которому можно добавлять новые способности.\n  Создайте абстрактный класс «Талант» (Talent), от которого будут наследоваться все добавляемые способности. Пока таких способностей три: умение плавать (Swimming), умение танцевать (Dancing), умение считать (Counting), но можете добавить и другие.\n  Создайте у класса Dog метод show_talents() для показа всех способностей, которыми обладает собака.\n\n  Требования к реализации:\n  Класс Talent должен быть абстрактным. Это значит, что объекты такого класса мы создать не сможем, так как одна из его функций объявлена как «чисто» виртуальная (pure virtual).\n  Каждая способность, наследуемая от абстрактного класса Talent, должна быть представлена в виде отдельного класса.\n\n  Пример выполнения:\n  Создаём собаку с именем Steve:\n      Dog dog1(\"Steve\")\n  Добавляем ей умение танцевать и плавать.\n  Если мы сделаем запрос умений show_talents(), то на экран будет выведено:\n  This is Steve and it has some talents: \n              It can “Dance” \n              It can “Swim”\n\n  Советы и рекомендации:\n  - Для хранения способностей можно использовать вектор.\n  - Для создания абстрактного класса рекомендуем пересмотреть видео, где функция voice в классе Animal была объявлена «чисто» виртуальной. Это поможет в выполнении задания.\n",
    "\t\t\tЗадача 2. Интерфейс Shape (дополнительное задание)\n  У вас есть набор классов различных геометрических фигур: круг(Circle), прямоугольник(Rectangle) и треугольник(Triangle), которые наследуются от общего класса геометрическая фигура (Shape). Каждый из этих классов имеет методы подсчёта площади, описывающего прямоугольника и взятия типа. Также есть общая функция printParams которая по переданному ей указателю на объект типа геометрическая фигура выводит на экран тип фигуры.\n\n  Что нужно сделать:\n  Создайте интерфейс Shape (фигуру), который предоставляет следующие методы:\n  — virtual double square() = 0; — возвращает площадь конкретной фигуры;\n  — virtual BoundingBoxDimensions dimensions() = 0; — размеры описывающего прямоугольника;\n  BoundingBoxDimensions — простая структура, которая содержит ширину и высоту;\n  — virtual std::string type() = 0; — название конкретного типа, например, вернуть строку Triangle для класса Triangle;\n  void printParams(Shape *shape) — сюда можно будет передавать любые фигуры:\n  { \n     std::cout <<\"Type: \" << shape->type() << std::endl;\n  комбинация virtual … = 0; — создаёт чисто виртуальный метод. Это означает, что такой метод обязательно должен быть переопредёлен в классе-наследнике. Если программист пронаследует свой класс от такого интерфейса, то компилятор будет ругаться на отсутствие методов, описанных как virtual … = 0. То есть программист будет вынужден добавить такие методы в свой класс, чтобы создать объект такого типа.\n     ….\n  }\n  Создайте классы-наследники Shape: Circle, Rectangle и Triangle.\n  У каждого из классов будет разный набор полей: у треугольника будут три стороны в виде переменных double, у круга — радиус, а у прямоугольника — длина и ширина. Так как все они наследуются от Shape, в каждом из классов следует реализовать методы нахождения размерности, площади и метод, возвращающий название типа.\n  Площадь треугольника при известных длинах сторон находится при помощи формулы Герона:\n  sqrt(p * (p - a) * (p - b) * (p - c)), где p — полупериметр.\n  Размеры описывающего прямоугольника для треугольника находятся по похожей формуле — сначала находим радиус описанной окружности:\n  a * b * c / (4 * sqrt(p*(p - a)*(p - b)*(p - c))), где р — снова полупериметр.\n  Затем умножаем его на два и получаем сторону квадрата, в который помещён треугольник.\n  В функции main вызовите printParams со всеми типами, которые вы создали.\n\n  Пример:\n  Triangle t(3,4,5);\n      printParams(&t);\n\n  Вывод:\n\n  Type: Triangle\n  Square: 6\n  Width: 5\n  Height: 5\n"
};

extern const std::string equals;

void Task_29_1();
void Task_29_2();
#endif
/* Задание 9. Треугольник на координатной плоскости
 *  Проверьте, образуют ли треугольник три данные точки на координатной плоскости. Каждая точка
 *  задается двумя координатами. Таким образом, на вход программе даётся шесть чисел: координаты
 *  первой точки, затем координаты второй точки и координаты третьей точки. Программа должна
 *  ответить Yes, если три данные точки задают треугольник, или No.
 *  Например, если хотя бы две из данных точек совпадают, то треугольника данные три точки не
 *  образуют. Другой пример: точки с координатами (1; 2), (3; 6) и (-2; −4) не образуют
 *  треугольника, поскольку они лежат на одной прямой, хоть и не совпадают.
 *  Постарайтесь сделать свою программу по возможности лаконичнее. */

#include <iostream>
#include "Module_05.hpp"

void Task_05_9() {
    std::cout << equals << string_tasks[8] << equals;

    int ax, bx, cx;
    int ay, by, cy;

    std::cout << "Введите координаты точки A: ";
    std::cin >> ax >> ay;
    std::cout << "Введите координаты точки B: ";
    std::cin >> bx >> by;
    std::cout << "Введите координаты точки C: ";
    std::cin >> cx >> cy;
    
    std::cout << "\n------------Проверка------------\n\n";

    if ((ax == bx && ay == by) ||
        (bx == cx && by == cy) ||
        (cx == ax && cy == ay))
        std::cout << "Среди введенных точек есть совпадающие!"
            << " Построение треугольника невозможно!\n";
//  ошибка
//  else if (ay != by && ay != cy && ((ax - bx) / (ay - by)) == ((ax - cx) / (ay - cy)) &&
//                                            ((ax - bx) % (ay - by)) == ((ax - cx) % (ay - cy)) ||
//           by != cy && by != ay && ((bx - cx) / (by - cy)) == ((bx - ax) / (by - ay)) &&
//                                            ((bx - cx) % (by - cy)) == ((bx - ax) % (by - ay)) ||
//           cy != ay && cy != by && ((cx - ax) / (cy - ay)) == ((cx - bx) / (cy - by)) &&
//                                            ((cx - ax) % (cy - ay)) == ((cx - bx) % (cy - by)))
    else if ((ax - bx) * (ay - cy) == (ax - cx) * (ay - by) ||
             (bx - cx) * (by - ay) == (bx - ax) * (by - cy) || 
             (cx - ax) * (cy - by) == (cx - bx) * (cy - ay))
        std::cout << "Три точки лежат на одной прямой! Построение треугольника невозможно!\n";
    else
        std::cout << "Построение треугольника возможно!\n";
}
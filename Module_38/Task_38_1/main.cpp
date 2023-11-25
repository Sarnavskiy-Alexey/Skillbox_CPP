/* Задание 1. Добавление звука для красной кнопки
 *  Что нужно сделать:
 *  Вспомните программу с красной кнопкой, которая изменяет свой внешний вид.
 *  При помощи QMediaPlayer добавьте звук щелчка при нажатии на кнопку.
 *
 *  Критерии оценки:
 *  1. Приложение отображает одно окно, в котором есть красная кнопка.
 *  2. При нажатии кнопка принимает вид нажатой, воспроизводится любой звук нажатия на кнопку. */

#include <QApplication>
#include <iostream>
#include "imagebutton.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ImageButton myButton(nullptr);
    myButton.setFixedSize(100, 100);
    myButton.move(1000, 400);

    QObject::connect(&myButton, &QPushButton::clicked, [](){ std::cout << "clicked\n"; });
    myButton.show();

    return a.exec();
}

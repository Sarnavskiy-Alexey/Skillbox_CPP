#ifdef __MODULE_37__
/* Задание 3. Пульт дистанционного управления ТВ
 *  Что нужно сделать:
 *  Реализуйте простой симулятор управления телевизором с помощью пульта, представленного в виде
 *  графического интерфейса с кнопками.
 *  Интерфейс представляет собой вертикальное окно (в портретной ориентации) размером 240х680
 *  пикселей. На пульте находятся кнопки переключения каналов от 0 до 9, кнопки перехода к
 *  следующему и предыдущему каналу, кнопки увеличения и уменьшения громкости с шагом в 10%.
 *  Снизу пульта находится мини-дисплей с отображением текущего статуса: текущий выбранный канал и
 *  текущий уровень громкости в процентах. */

#include <iostream>
#include "Module_37.hpp"
#include "./ui_pult.h"
#include "pultMainWindow.hpp"

void Task_37_3(int argc, char **argv) {
    std::cout << equals;
    std::wcout << string_tasks[2];
    std::cout << equals;

    QApplication app(argc, argv);

    MyPult::PultMainWindow window(nullptr);
    Ui::MainWindow_pult pult;
    pult.setupUi(&window);

    window.spinBox_ch = pult.spinBox_ch;
    window.spinBox_volume = pult.spinBox_volume;

    window.show();

    app.exec();
}

#include <Task_37_3.moc>

#endif

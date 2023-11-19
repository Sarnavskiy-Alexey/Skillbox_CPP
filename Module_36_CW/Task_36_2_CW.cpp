#ifdef __MODULE_36__
/*  */

#include <iostream>
#include "Module_36_CW.hpp"

void Task_36_2_CW(int argc, char **argv) {
    std::cout << equals << string_tasks[1] << equals;

    QApplication app(argc, argv);
    auto *slider = new QSlider(Qt::Horizontal);
    auto *spinbox = new QSpinBox();
    slider->setMinimum(0);
    slider->setMaximum(100);
    spinbox->setMinimum(0);
    spinbox->setMaximum(100);

    QObject::connect(slider, &QSlider::valueChanged, spinbox, &QSpinBox::setValue);
    QObject::connect(spinbox, QOverload<int>::of(&QSpinBox::valueChanged), slider, &QSlider::setValue);

    slider->resize(300, 40);
    spinbox->resize(220, 220);
    slider->move(700, 500);
    spinbox->move(1000, 500);

    slider->show();
    spinbox->show();

    app.exec();
}

#include <Task_36_2_CW.moc>

#endif

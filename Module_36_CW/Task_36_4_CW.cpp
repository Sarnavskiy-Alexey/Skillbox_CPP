#ifdef __MODULE_36__
/*  */

#include <iostream>
#include "Module_36_CW.hpp"

void Task_36_4_CW(int argc, char **argv) {
    std::cout << equals << string_tasks[3] << equals;

    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    QPushButton *button1 = new QPushButton("One", window);
    QPushButton *button2 = new QPushButton("Two", window);
    QPushButton *button3 = new QPushButton("Three", window);
    QPushButton *button4 = new QPushButton("Four", window);
    QPushButton *button5 = new QPushButton("Five", window);
    // auto *layout = new QVBoxLayout(window);
    auto *layout = new QGridLayout(window);
    // layout->addWidget(button1);
    // layout->addWidget(button2);
    // layout->addWidget(button3);
    layout->addWidget(button1, 0, 0);
    layout->addWidget(button2, 0, 1);
    layout->addWidget(button3, 1, 0, 1, 2);
    layout->addWidget(button4, 2, 0);
    layout->addWidget(button5, 2, 1);
    // button1->move(40, 50);
    // button2->move(140, 150);
    // button3->move(200, 200);

    window->resize(300, 300);
    window->move(1000, 500);
    window->show();

    app.exec();
}

#include <Task_36_4_CW.moc>

#endif

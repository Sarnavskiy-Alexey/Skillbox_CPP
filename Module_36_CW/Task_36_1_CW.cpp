#ifdef __MODULE_36__
/*  */

#include <iostream>
#include "Module_36_CW.hpp"

class Printer : public QObject {
    Q_OBJECT
public slots:
    void printFinished() {
        std::cout << "finished" << std::endl;
    }
};

void Task_36_1_CW(int argc, char **argv) {
    std::cout << equals << string_tasks[0] << equals;

    QApplication app(argc, argv);

    QTimer myTimer;
    Printer myPrinter;
    QObject::connect(&myTimer, &QTimer::timeout, &myPrinter, &Printer::printFinished);
    myTimer.start(2000);

    app.exec();
}

#include <Task_36_1_CW.moc>

#endif

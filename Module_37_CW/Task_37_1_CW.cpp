#ifdef __MODULE_37__
/*  */

#include <iostream>
#include "Module_37_CW.hpp"
#include "callerMainWindow.hpp"
#include "./ui_caller.h"

void Task_37_1_CW(int argc, char **argv) {
    std::cout << equals << string_tasks[0] << equals;

    QApplication app(argc, argv);
    CallerMainWindow window(nullptr);
    Ui::MainWindow caller;
    caller.setupUi(&window);

    window.lineEdit = caller.lineEdit;

    window.resize(480, 640);
    window.show();
    
    app.exec();
}

#include <Task_37_1_CW.moc>

#endif

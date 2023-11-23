#pragma once

#include <QMainWindow>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QPushButton>

namespace MyPult {
    class PultMainWindow : public QMainWindow {
        Q_OBJECT
    private:
        bool isChanging = false;
        int new_ch = 0;
        int curr_ch = 1;

        void add_ch(int num);
        void set_color_exec();
        void set_color_new();
    public:
        PultMainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {}
        QSpinBox* spinBox_ch = nullptr;
        QSpinBox* spinBox_volume = nullptr;
    public slots:
        void add0();
        void add1();
        void add2();
        void add3();
        void add4();
        void add5();
        void add6();
        void add7();
        void add8();
        void add9();
        void exec_ch();
        void del_symb();
        void next_ch();
        void prev_ch();
        void louder();
        void quieter();
    };
};

#include "pultMainWindow.hpp"

namespace MyPult {
    void PultMainWindow::set_color_exec() {
        spinBox_ch->setStyleSheet(QString("color: #00ff00"));
    }
    void PultMainWindow::set_color_new() {
        spinBox_ch->setStyleSheet(QString("color: #0000ff"));
    }
    void PultMainWindow::add_ch(int num) {
        if (new_ch < 100) {
            if (num == 0 && new_ch == 0) {
                /* NOTHING TO DO */
            } else {
                new_ch = new_ch * 10 + num;
                spinBox_ch->setValue(new_ch);
                set_color_new();
            }
        }
    }
    void PultMainWindow::add0() {
        add_ch(0);
    }
    void PultMainWindow::add1() {
        add_ch(1);
    }
    void PultMainWindow::add2() {
        add_ch(2);
    }
    void PultMainWindow::add3() {
        add_ch(3);
    }
    void PultMainWindow::add4() {
        add_ch(4);
    }
    void PultMainWindow::add5() {
        add_ch(5);
    }
    void PultMainWindow::add6() {
        add_ch(6);
    }
    void PultMainWindow::add7() {
        add_ch(7);
    }
    void PultMainWindow::add8() {
        add_ch(8);
    }
    void PultMainWindow::add9() {
        add_ch(9);
    }
    void PultMainWindow::exec_ch() {
        if (new_ch != 0) {
            curr_ch = new_ch;
            new_ch = 0;
        }
        spinBox_ch->setValue(curr_ch);
        set_color_exec();
    }
    void PultMainWindow::del_symb() {
        new_ch /= 10;
        if (new_ch == 0) {
            spinBox_ch->setValue(curr_ch);
            set_color_exec();
        } else {
            spinBox_ch->setValue(new_ch);
            set_color_new();
        }
    }
    void PultMainWindow::next_ch() {
        if (curr_ch == 999) {
            curr_ch = 1;
        } else {
            curr_ch++;
        }
        spinBox_ch->setValue(curr_ch);
    }
    void PultMainWindow::prev_ch() {
        if (curr_ch == 1) {
            curr_ch = 999;
        } else {
            curr_ch--;
        }
        spinBox_ch->setValue(curr_ch);
    }
    void PultMainWindow::louder() {
        if (spinBox_volume->value() < 100) {
            spinBox_volume->setValue(spinBox_volume->value() + 10);
        }
    }
    void PultMainWindow::quieter() {
        if (spinBox_volume->value() > 0) {
            spinBox_volume->setValue(spinBox_volume->value() - 10);
        }
    }
}
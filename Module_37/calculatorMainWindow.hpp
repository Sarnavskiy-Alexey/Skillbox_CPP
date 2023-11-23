#pragma once

#include <exception>
#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

namespace MyCalc {
    class ZeroDivisionError : std::exception {
    public:
        const char * what() const noexcept override {
            return "Деление на нуль!";
        }
    };

    enum class E_Calculator_Action {
        Null,
        Sum,
        Diff,
        Mult,
        Div,
    };

    class CalculatorMainWindow : public QMainWindow {
        Q_OBJECT
    public:
        CalculatorMainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {}
        QLineEdit* lineEdit_num1 = nullptr;
        QLineEdit* lineEdit_num2 = nullptr;
        QLineEdit* lineEdit_result = nullptr;
        QRadioButton* radioButton_sum = nullptr;
        QRadioButton* radioButton_diff = nullptr;
        QRadioButton* radioButton_mult = nullptr;
        QRadioButton* radioButton_div = nullptr;
    public slots:
        void exec();
        E_Calculator_Action check_action();
        double make_action(double a, double b);
    };
};

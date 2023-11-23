#include <iostream>
#include "calculatorMainWindow.hpp"

namespace MyCalc {
    void CalculatorMainWindow::exec() {
        bool ok1, ok2;
        double num1 = lineEdit_num1->text().toDouble(&ok1);
        double num2 = lineEdit_num2->text().toDouble(&ok2);
        if (ok1 && ok2) {
            try {
                double result = make_action(num1, num2);
                lineEdit_result->setText(QString::number(result, 'g', 10));
            } catch (const ZeroDivisionError &X) {
                lineEdit_result->setText(QString("ERROR"));
            }
        } else {
            lineEdit_result->setText(QString("ERROR"));
        }
        // } 
    }

    E_Calculator_Action CalculatorMainWindow::check_action() {
        if (radioButton_sum->isChecked()) {
            return E_Calculator_Action::Sum;
        } else if (radioButton_diff->isChecked()) {
            return E_Calculator_Action::Diff;
        } else if (radioButton_mult->isChecked()) {
            return E_Calculator_Action::Mult;
        } else if (radioButton_div->isChecked()) {
            return E_Calculator_Action::Div;
        } else {
            return E_Calculator_Action::Null;
        }
    }

    double CalculatorMainWindow::make_action(double a, double b) {
        E_Calculator_Action action = check_action();
        if (action == E_Calculator_Action::Sum) {
            return a + b;
        } else if (action == E_Calculator_Action::Diff) {
            return a - b;
        } else if (action == E_Calculator_Action::Mult) {
            return a * b;
        } else if (action == E_Calculator_Action::Div) {
            if (b == 0) {
                throw ZeroDivisionError();
            } else {
                return a / b;
            }
        } else {
            return 0.0;
        }
    }
};

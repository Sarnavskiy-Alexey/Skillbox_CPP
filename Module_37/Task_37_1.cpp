#ifdef __MODULE_37__
/* Задание 1. Графический калькулятор
 *  Что нужно сделать:
 *  Реализуйте графическое приложение для основных операций с целыми числами: сложение, вычитание,
 *  умножение, деление.
 *  В верхней части окна приложения расположено два текстовых поля для ввода двух чисел. Чуть ниже —
 *  поле с выводом результата. Далее снизу — кнопки четырёх основных действий: сложить, вычесть,
 *  умножить, разделить. Интерфейс должен быть свободно масштабируемым в зависимости от размера
 *  самого окна.
 *  Если какая-то операция не может быть выполнена по причине некорректности данных, в поле
 *  результата записывается текст «ERROR».
 *  
 *  Советы и рекомендации:
 *  При желании вы можете усложнить себе задачу, реализовав работу калькулятора на числах с
 *  плавающей точкой. */

#include <iostream>
#include "Module_37.hpp"
#include "calculatorMainWindow.hpp"
#include "./ui_calculator.h"

void Task_37_1(int argc, char **argv) {
    std::cout << equals;
    std::wcout << string_tasks[0];
    std::cout << equals;

    QApplication app(argc, argv);

    MyCalc::CalculatorMainWindow window(nullptr);
    Ui::MainWindow calculator;
    calculator.setupUi(&window);

    window.lineEdit_num1 = calculator.lineEdit_num1;
    window.lineEdit_num2 = calculator.lineEdit_num2;
    window.lineEdit_result = calculator.lineEdit_result;
    window.radioButton_sum = calculator.radioButton_sum;
    window.radioButton_diff = calculator.radioButton_diff;
    window.radioButton_mult = calculator.radioButton_mult;
    window.radioButton_div = calculator.radioButton_div;

    window.show();
    
    app.exec();
}

#include <Task_37_1.moc>

#endif

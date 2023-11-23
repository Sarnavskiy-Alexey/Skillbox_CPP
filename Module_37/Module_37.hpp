#ifdef __MODULE_37__
#pragma once

#include <string>
#include <QApplication>
#include <QTimer>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

const std::wstring string_tasks[] = {
    L"\t\t\tЗадание 1. Графический калькулятор\n  Что нужно сделать:\n  Реализуйте графическое приложение для основных операций с целыми числами: сложение, вычитание, умножение, деление.\n  В верхней части окна приложения расположено два текстовых поля для ввода двух чисел. Чуть ниже — поле с выводом результата. Далее снизу — кнопки четырёх основных действий: сложить, вычесть, умножить, разделить. Интерфейс должен быть свободно масштабируемым в зависимости от размера самого окна.\n  Если какая-то операция не может быть выполнена по причине некорректности данных, в поле результата записывается текст «ERROR».\n\n  Советы и рекомендации:\n  При желании вы можете усложнить себе задачу, реализовав работу калькулятора на числах с плавающей точкой.\n",
    L"\t\t\tЗадание 2. Видеопроигрыватель на QML\n  Что нужно сделать\n  Требуется составить интерфейс простого видеопроигрывателя на языке QML.\n  Основную верхнюю зону интерфейса составляет сам экран проигрывателя. Снизу расположены средства управления воспроизведением, а именно: кнопка начала воспроизведения (Play), кнопка паузы воспроизведения (Pause), кнопка остановки воспроизведения (Stop), перемотка (Rewind), быстрое воспроизведение (Forward). Далее за ними расположен горизонтальный ползунок текущего места воспроизведения.\n\n  Советы и рекомендации:\n  Для отображения элементов управления вы можете использовать Unicode-символы: ▶️,⏸️,⏹,⏪️,⏩️. Ползунок воспроизведения вы можете реализовать с помощью элемента ProgressBar.\n",
    L"\t\t\tЗадание 3. Пульт дистанционного управления ТВ\n  Что нужно сделать:\n  Реализуйте простой симулятор управления телевизором с помощью пульта, представленного в виде графического интерфейса с кнопками.\n  Интерфейс представляет собой вертикальное окно (в портретной ориентации) размером 240х680 пикселей. На пульте находятся кнопки переключения каналов от 0 до 9, кнопки перехода к следующему и предыдущему каналу, кнопки увеличения и уменьшения громкости с шагом в 10%.\n  Снизу пульта находится мини-дисплей с отображением текущего статуса: текущий выбранный канал и текущий уровень громкости в процентах.\n",
};

extern const std::string equals;

void Task_37_1(int argc, char **argv);
void Task_37_2(int argc, char **argv);
void Task_37_3(int argc, char **argv);
#endif

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>
#include <QLineEdit>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textEdited, [this](QString currentText) {
        QRegularExpression exp("^\\+\\d{11}$");
        if (exp.match(currentText).hasMatch()) {
            setOKLabel();
        } else {
            setKOLabel();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOKLabel()
{
    ui->label->setText("OK");
    ui->label->setStyleSheet("QLabel {color : green;}");
}

void MainWindow::setKOLabel()
{
    ui->label->setText("KO");
    ui->label->setStyleSheet("QLabel {color : red;}");
}


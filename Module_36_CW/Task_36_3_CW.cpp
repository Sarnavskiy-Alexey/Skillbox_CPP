#ifdef __MODULE_36__
/*  */

#include <iostream>
#include "Module_36_CW.hpp"

class ImageButton : public QPushButton {
    Q_OBJECT
public:
    ImageButton() = default;
    ImageButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;
public slots:
    void setUp();
    void setDown();
private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
    bool isDown = false;
};

ImageButton::ImageButton(QWidget *parent) {
    setParent(parent);
    setToolTip("Стоп");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mButtonUpPixmap = QPixmap("D:\\Study\\skillbox\\Developer_CPP\\Module_36\\image\\buttonUp.png");
    mButtonDownPixmap = QPixmap("D:\\Study\\skillbox\\Developer_CPP\\Module_36\\image\\buttonDown.png");
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());
    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);
}

void ImageButton::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

QSize ImageButton::sizeHint() const {
    return QSize(100, 100);
}

QSize ImageButton::minimumSizeHint() const {
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent *e) {
    setDown();
}

void ImageButton::setDown() {
    mCurrentButtonPixmap = mButtonDownPixmap;
    update();
    QTimer::singleShot(100, this, &ImageButton::setUp);
}

void ImageButton::setUp() {
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
}

void Task_36_3_CW(int argc, char **argv) {
    std::cout << equals << string_tasks[2] << equals;

    QApplication app(argc, argv);

    ImageButton myButton(nullptr);
    myButton.setFixedSize(100, 100);
    myButton.move(1000, 400);
    QObject::connect(&myButton, &QPushButton::clicked, [](){ std::cout << "clicked\n"; });
    myButton.show();

    app.exec();
}

#include <Task_36_3_CW.moc>

#endif

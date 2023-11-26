/* Задание 3. Создание приложения, которое позволяет наложить Blur-эффект
 *  Что нужно сделать:
 *  Необходимо создать приложение, которое позволяет открыть картинку и наложить Blur-эффект.
 *  Глубину наложения можно варьировать при помощи слайдера. Пример приложения: (на сайте с ДЗ)
 *
 *  Можно использовать Qt Creator и Qt Designer, чтобы быстро добавить три элемента. Первый виджет —
 *  QLabel для отображения картинки. Второй — QSlider для установления глубины blur. Для этого
 *  выберите min слайдера 0, а max — десять. Третий виджет — кнопка QPushButton для открытия диалога
 *  выбора картинки. Используйте файловый диалог из задания про медиаплеер. Виджеты можно
 *  расположить по вертикали одной кнопкой в Qt Designer, как это было в предыдущем задании.
 *
 *  При перемещении слайдера к изображению применяется эффект с нужной величиной blurRadius.
 *  Воспользуйтесь функцией из примера, в котором применялся QtConcurrent. Эта величина всегда
 *  равнялась восьми. Необходимо вынести её в аргументы функции примерно таким образом:
 *      QImage blurImage(QImage source, int blurRadius);
 *
 *  Установить картинку из функции в label можно так:
 *      ui->imageLabel->setPixmap(QPixmap::fromImage(blurImage(sourceImage, newValue).scaled(
 *                                          ui->imageLabel->width(),
 *                                          ui->imageLabel->height(), Qt::KeepAspectRatio)));
 *
 *  ImageLabel — label, в который необходимо загрузить картинку. Использование метода scaled
 *  позволяет изменять размеры изображения. В данном случае нужно сжать изображение под размер,
 *  который занимает label с сохранением соотношения сторон (Qt::KeepAspectRatio).
 *
 *  Критерии оценки:
 *  - Приложение отображает одно окно с кнопкой и слайдером.
 *  - При нажатии на кнопку появляется диалог выбора файлов, в котором можно выбирать файлы JPG. При
 *    выборе файл отображается в приложении.
 *  - При перемещении ползунка изображение получает Blur-эффект. */

#include <QApplication>
#include <QDir>
#include <QFileDialog>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QImage>
#include <QLabel>
#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>

QImage blurImage(QImage source, qint32 blurRadius)
{
    if (source.isNull())
        return QImage();

    QGraphicsScene scene;
    QGraphicsPixmapItem item;

    item.setPixmap(QPixmap::fromImage(source));
    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(), QRectF(0, 0, source.width(), source.height()));
    return result;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto *window = new QWidget;

    auto *bluredImage = new QGraphicsView;
    auto *scene = new QGraphicsScene(bluredImage);
    auto *image = new QImage;
    auto *slider = new QSlider(Qt::Horizontal);
    auto *openButton = new QPushButton("Открыть");
    auto *vbox = new QVBoxLayout(window);
    QString filePath;

    // slider properties
    slider->setMinimum(0);
    slider->setMaximum(10);
    slider->setPageStep(1);
    slider->setSingleStep(1);

    vbox->addWidget(bluredImage);
    vbox->addWidget(slider);
    vbox->addWidget(openButton);

    QObject::connect(slider, &QSlider::valueChanged, [bluredImage, image, scene](const int value){

        QImage new_image = blurImage(*image, value);
        QPixmap new_p = QPixmap::fromImage(new_image);
        scene->addPixmap(new_p);
        scene->setSceneRect(new_p.rect());
        bluredImage->setScene(scene);
    });

    QObject::connect(openButton, &QPushButton::clicked, [bluredImage, scene, image, slider, &filePath](){
        filePath = QFileDialog::getOpenFileName(nullptr,
                                                "Open image",
                                                "D:/Study/skillbox/Developer_CPP/Module_38/Task_38_3/image/",
                                                "images (*.jpg)");
        QPixmap p(filePath);
        *image = p.toImage();
        scene->clear();
        scene->addPixmap(p);
        scene->setSceneRect(p.rect());
        bluredImage->setScene(scene);

        slider->valueChanged(slider->value());
    });

    vbox->stretch(1);
    window->setMinimumSize(200, 210);
    window->show();

    return a.exec();
}

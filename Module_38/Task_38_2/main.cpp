/* Задание 2. Создание приложения для редактирования HTML-файла
 *  Что нужно сделать:
 *  Создайте приложение, в котором окно делится на две половины. В левой половине можно
 *  редактировать HTML-документ, а в правой — видеть результат WebView. Пример такого приложения:
 *  (на сайте).
 *
 *  Можете использовать Qt Creator и Qt Designer, чтобы быстро добавить два элемента:
 *  QPlainTextEdit для редактирования текста и QWebEngineView для отображения результата.
 *  Необходимо, чтобы каждый из виджетов занимал равное количество пространства по горизонтали и
 *  все по вертикали.
 *
 *  Выделите оба виджета. Зажмите Ctrl и щёлкните сначала по одному из виджетов, а затем по
 *  второму. Нажмите «Расположить по горизонтали» или Lay out horizontally.
 *
 *  Для каждого из виджетов найдите параметр Horizontal stretch и сделайте его равным единице.
 *  Можете выполнить те же действия без использования Qt Designer. Задайте sizePolicy.
 *
 *  Приложение должно реагировать на изменения текста слева, сразу полностью перестраивая
 *  представление HTML-документа справа.
 *
 *  Критерии оценки:
 *  Приложение отображает одно окно, в котором есть два текстовых виджета. Каждый виджет занимает
 *  свою половину экрана. Левый виджет содержит текстовое представление HTML-документа. Правый
 *  виджет — нарисованную web-страницу.
 *  При изменении исходного кода страницы в левом виджете представление в правом сразу меняется. */

#include <QApplication>

#include <QWebEngineView>
#include <QPlainTextEdit>
#include <QHBoxLayout>

#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto *wysiwigEditor = new QWidget;
    auto *sourceCode = new QPlainTextEdit;
    auto *watcher = new QWebEngineView;
    auto *hbox = new QHBoxLayout(wysiwigEditor);

    hbox->addWidget(sourceCode);
    hbox->addWidget(watcher);

    hbox->setStretch(0, 1);
    hbox->setStretch(1, 1);

    wysiwigEditor->setMinimumSize(500, 250);
    wysiwigEditor->resize(1000, 500);

    //
    QObject::connect(sourceCode, &QPlainTextEdit::textChanged, [sourceCode, watcher]()
    {
        QString htmlCode = sourceCode->toPlainText();
        watcher->setHtml(htmlCode);
    });

    wysiwigEditor->show();

    return a.exec();
}

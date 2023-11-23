#ifdef __MODULE_37__
/* Задание 2. Видеопроигрыватель на QML
 *  Что нужно сделать:
 *  Требуется составить интерфейс простого видеопроигрывателя на языке QML.
 *  Основную верхнюю зону интерфейса составляет сам экран проигрывателя. Снизу расположены средства
 *  управления воспроизведением, а именно: кнопка начала воспроизведения (Play), кнопка паузы
 *  воспроизведения (Pause), кнопка остановки воспроизведения (Stop), перемотка (Rewind), быстрое
 *  воспроизведение (Forward). Далее за ними расположен горизонтальный ползунок текущего места
 *  воспроизведения.
 *  
 *  Советы и рекомендации:
 *  Для отображения элементов управления вы можете использовать Unicode-символы: ▶️,⏸️,⏹,⏪️,⏩️.
 *  Ползунок воспроизведения вы можете реализовать с помощью элемента ProgressBar. */

#include <iostream>
#include "Module_37.hpp"

void Task_37_2(int argc, char **argv) {
    std::cout << equals;
    std::wcout << string_tasks[1];
    std::cout << equals;

    QApplication app(argc, argv);

    app.exec();
}

#include <Task_37_2.moc>

#endif

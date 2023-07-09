#ifdef __MODULE_08__
/* Задание 4. Убийца Steam
 *  Вы пишете программу-инсталлятор для компьютерной игры. Пока обновление скачивается,
 *  пользователю нужно показать прогресс загрузки, чтобы он мог решить, подождать ему у экрана
 *  компьютера или заварить чай.
 *  Напишите программу, принимающую на вход размер файла обновления в мегабайтах и скорость
 *  интернет-соединения в мегабайтах в секунду. В каждую секунду программа показывает, сколько
 *  процентов от общего объёма обновления уже скачано, до тех пор, пока файл не загрузится. После
 *  установки обновления программа выводит время в секундах, которое заняло скачивание. Обеспечьте
 *  контроль ввода. */

#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
#include "Module_08.hpp"

void Task_08_4() {
    std::cout << equals << string_tasks[3] << equals;

    float downloadSize_MB, speed_MBperSec;
    
    do {
        std::cout << "Введите размер загрузки (МБ): ";
        std::cin >> downloadSize_MB;
        if (downloadSize_MB <= 0.0f)
            std::cout << "ОШИБКА! Размер загрузки должен быть положительным!\n";
    } while (downloadSize_MB <= 0.0f);
    
    do {
        std::cout << "Введите скорость загрузки (МБ/сек): ";
        std::cin >> speed_MBperSec;
        if (speed_MBperSec < 0.0f)
            std::cout << "ОШИБКА! Скорость загрузки не должна быть отрицательной!\n";
    } while (speed_MBperSec <= 0.0f);

    if (speed_MBperSec == 0.0f)
        std::cout << "Загрузка не может быть продолжена, так как Вы не подключены к сети!\n";
    else {
        float downloaded = 0.0f;
        int t = 0;
        do {
            // добавлено для пущей визуализации
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            t++;
            downloaded += speed_MBperSec;
            if (downloaded > downloadSize_MB)
                downloaded = downloadSize_MB;
            std::cout << "Прошло " << t << " сек. Скачано " << downloaded << " из "
                      << downloadSize_MB << " МБ ("
                      << std::round(downloaded / downloadSize_MB * 100) << "%).\n";
        } while (downloaded < downloadSize_MB);

        std::cout << "Загрузка завершена! Спасибо за ожидание!\n";
    }
}
#endif

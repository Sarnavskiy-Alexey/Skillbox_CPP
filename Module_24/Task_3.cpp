#ifdef __MODULE_24__
/* Задание 3. Реализация программы таймера
 *  Что нужно сделать
 *  Реализуйте работу точного таймера с визуальной отдачей.
 *  В начале программы пользователь вводит количество минут и секунд, которые требуется засечь на
 *  таймере, и нажимает «Ввод».
 *  После этого начинается обратный отсчёт времени, о чём незамедлительно и последовательно
 *  сообщается пользователю. Формат вывода такой же, как и при вводе интервала: минуты и секунды.
 *  Как только отсчёт на таймере иссяк, программа сообщает об этом с помощью вывода в консоль
 *  специального сообщения. Сообщение вместо аудиосигнала может выглядеть так: DING! DING! DING!
 *  
 *  Советы и рекомендации:
 *  Для ввода значения для засекания времени используйте std::get_time, но в качестве формата
 *  запросите только минуты и секунды. Целевое время для остановки таймера вычислите сами с помощью
 *  манипуляции над текущим std::time. Количество оставшегося времени выводите в цикле и вычислите
 *  его самостоятельно с помощью обращения с типом std::time_t как с секундами. */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Module_24.hpp"

void Task_24_3() {
    std::cout << equals << string_tasks[2] << equals;

    std::time_t timer = std::time(nullptr);
    std::tm* p_timer = std::localtime(&timer);

    std::cout << "Введите время для засекания в формате \"ММ:СС\": ";
    std::cin >> std::get_time(p_timer, "%M:%S");
    int minutes = p_timer->tm_min;
    int seconds = p_timer->tm_sec;

    std::time_t now = std::time(nullptr);

    timer = now + minutes * 60 + seconds;
    
    while (now < timer) {
        now = std::time(nullptr);
        std::cout << "До окончания таймера осталось: " << timer - now << " сек.\n";
        _sleep(1000U);
    }
    for (int i = 0; i < 3; i++) {
        std::cout << "\aDING! ";
        _sleep(1000U);
    }
    std::cout << "\n";
}
#endif

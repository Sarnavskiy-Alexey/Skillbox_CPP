#ifdef __MODULE_08__
/* Задание 8. Биолаборатория 2.0* (дополнительное задание)
 *  Благодаря вашей помощи компания «Терран Биотех» вышла на финишную прямую в борьбе со всемирной
 *  эпидемией коринебактерий. Однако прошлая симуляция была недостаточно точной, да и новая версия
 *  антибиотика работает по-другому.
 *  В чашку Петри добавляется W капель воды, D капель чистого антибиотика и подселяется N
 *  коринебактерий. Известно, что каждую минуту количество бактерий изменяется прямо
 *  пропорционально концентрации антибиотика в растворе по формуле Nnew = 2 × Nold − Nold × D / W,
 *  где Nold — количество коринебактерий минуту назад, Nnew — их новое количество, а D / W —
 *  концентрация действующего антибиотика. При этом каждую минуту 20% от всего количества
 *  антибиотика разлагается и больше не действует.
 *  Напишите программу, которая получает на вход значения W, D и Nold и симулирует процесс в
 *  течение 20 минут, для каждой минуты выводя на экран текущую концентрацию антибиотика и
 *  количество живых коринебактерий в чашке Петри. Обеспечьте контроль ввода. */

#include <iostream>
#include "Module_08.hpp"

void Task_08_8() {
    std::cout << equals << string_tasks[7] << equals;

    int W, D, Nold, Nnew;
    float antibioticConcentration;
    int minutes;
    
    // безопасный ввод количества воды
    do {
        std::cout << "Введите количество воды (капли): ";
        std::cin >> W;
        if (W <= 0)
            std::cout << "ОШИБКА! Количество воды должно быть положительным!\n";
    } while (W <= 0);
    
    // безопасный ввод количества чистого антибиотика
    do {
        std::cout << "Введите количество чистого антибиотика (капли): ";
        std::cin >> D;
        if (D <= 0)
            std::cout << "ОШИБКА! Количество чистого антибиотика должно быть положительным!\n";
    } while (D <= 0);
    
    // безопасный ввод количества коринебактерий
    do {
        std::cout << "Введите количество коринебактерий (шт.): ";
        std::cin >> Nold;
        if (Nold <= 0)
            std::cout << "ОШИБКА! Количество коринебактерий должно быть положительным!\n";
    } while (Nold <= 0);

    // расчет
    for (minutes = 1; minutes <= 20; minutes++) {
        D = int((float)D * 0.8f);
        antibioticConcentration = (float)D / W;
        Nnew = 2.0f * Nold - Nold * antibioticConcentration;
        if (Nnew < 0) Nnew = 0;

        std::cout << "После " << minutes << " мин. концентрация антибиотика: "
                  << antibioticConcentration << ", количество коринебактерий: " << Nnew << "\n";

        if (Nnew == 0) 
            break;
        Nold = Nnew;
    }
    
    if (Nnew == 0)
        std::cout << "Коринебактерии повержены за " << minutes << " мин.! Человечество спасено!\n";
    else
        std::cout << "Человечество обречено...\n";
}
#endif

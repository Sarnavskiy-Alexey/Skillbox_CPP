/* Задание 6. Маятник
 *  Известно, что амплитуда качающегося маятника с каждым разом затухает на 8,4% от амплитуды
 *  прошлого колебания. Если качнуть маятник, он, строго говоря, никогда не остановится: его
 *  амплитуда будет уменьшаться до тех пор, пока мы не сочтём такой маятник остановившимся.
 *  Напишите программу, определяющую, сколько раз качнётся маятник, прежде чем он, по нашему
 *  мнению, остановится. Программа получает на вход начальную амплитуду колебания в сантиметрах и
 *  конечную амплитуду его колебаний, которая считается остановкой маятника. Обеспечьте контроль
 *  ввода. */

#include <iostream>
#include "Module_08.hpp"

void Task_08_6() {
    std::cout << equals << string_tasks[5] << equals;

    const float decreaseMultiplier = 0.084;
    float beginAmplitude, endAmplitude;
    float currentAmplitude;
    int countSwings = 0;

    // безопасный ввод начальной амплитуды
    do {
        std::cout << "Введите начальную амплитуду (см): ";
        std::cin >> beginAmplitude;
        if (beginAmplitude <= 0.0f)
            std::cout << "ОШИБКА! Начальная амплитуда должна быть положительной!\n";
    } while (beginAmplitude <= 0.0f);
    
    currentAmplitude = beginAmplitude;
    
    // безопасный ввод конечной амплитуды
    do {
        std::cout << "Введите конечную амплитуду (см): ";
        std::cin >> endAmplitude;
        if (endAmplitude <= 0.0f)
            std::cout << "ОШИБКА! Конечная амплитуда должна быть положительной!\n";
        else if (endAmplitude >= beginAmplitude)
            std::cout << "ОШИБКА! Конечная амплитуда должна быть меньше начальной!\n";
    } while (endAmplitude <= 0.0f || endAmplitude >= beginAmplitude);

    while (currentAmplitude > endAmplitude) {
        countSwings++;
        currentAmplitude -= (currentAmplitude * decreaseMultiplier);
        std::cout << "После " << countSwings << "-го качения амплитуда маятника составляет: "
                  << currentAmplitude << " см\n";
    }

    std::cout << "Маятник остановится через: " << countSwings << " кач.\n";
}

#ifdef __MODULE_07__
/* Задание 2. Кофемашина
 *  Инженеры компании «Спейс Инжиниринг» не могут продуктивно работать без кофе. Недавно в их
 *  кофемашину случайно попал космический луч и повредил программу-прошивку. Вас умоляют помочь.
 *  Кофемашина умеет готовить два напитка: американо и латте. Для американо требуется 300 мл
 *  воды, а для латте 30 мл воды и 270 мл молока.
 *  Напишите программу, которая спрашивает у пользователя (это действие программа делает один раз
 *  в начале работы), сколько всего миллилитров молока и воды залито в кофемашину, после чего
 *  начинает обслуживание, спрашивая, какой напиток хочет очередной посетитель. Пользователь
 *  выбирает один из двух напитков, программа отвечает одним из трёх вариантов: «Ваш напиток
 *  готов», «Не хватает воды» или «Не хватает молока», после чего переходит к обслуживанию
 *  следующего посетителя. Если молока и воды не хватает ни на один вид напитка, программа выдаёт
 *  отчёт и завершается. В отчёте должно быть написано, что ингредиенты подошли к концу, должен
 *  быть указан остаток воды и молока в машине, а также должно быть указано, сколько всего было
 *  приготовлено чашек американо и латте за эту смену. Выберите наиболее удобный для написания
 *  программы цикл. Обеспечьте контроль ввода. */

#include <iostream>
#include "Module_07.hpp"

void Task_07_2() {
    std::cout << equals << string_tasks[1] << equals;
    
    int waterMl, milkMl, coffeeChoice;
    const int americanoWaterMl = 100, latteWaterMl = 30, latteMilkMl = 70;
    int countLatte = 0, countAmericano = 0;
    std::cout << "Введите количество воды в мл: ";
    std::cin >> waterMl;
    std::cout << "Введите количество молока в мл: ";
    std::cin >> milkMl;
    if (waterMl < 0 || milkMl < 0) {
        std::cout << "Отрицательное количество ингредиентов? Что-то тут не так...\n";
    }
    else {
        while (true) {
            // выбор напитка пользователем
            std::cout << "Выберите напиток (0 - выход, 1 - американо, 2 - латте): ";
            std::cin >> coffeeChoice;

            // пользователь захотел выключить автомат
            if (coffeeChoice == 0) {
                break;
            }
            // пользователь выбрал американо
            else if (coffeeChoice == 1) {
                if (waterMl >= americanoWaterMl) {
                    waterMl -= americanoWaterMl;
                    countAmericano++;
                }
                else {
                    std::cout << "Ингредиентов для американо не хватает! Выберите другой напиток!\n";
                }
            }
            // пользователь выбрал латте
            else if (coffeeChoice == 2) {
                if (milkMl >= latteMilkMl && waterMl >= latteWaterMl) {
                    waterMl -= latteWaterMl;
                    milkMl -= latteMilkMl;
                    countLatte++;
                }
                else {
                    std::cout << "Ингредиентов для латте не хватает! Выберите другой напиток!\n";
                }
            }
            // пользователь выбрал несуществующую позицию
            else {
                std::cout << "Такого напитка в автомате не предусмотрено...\n";
            }

            // проверка на то, что для любого напитка не хватит ингредиентов
            // если не хватит, то кофемашина должна выключиться
            if (!(waterMl >= americanoWaterMl) &&
                !(milkMl >= latteMilkMl && waterMl >= latteWaterMl)) {
                std::cout << "Для приготовления любого напитка не хватает ингредиентов!\n"
                    << "Добавьте необходимые ингредиенты в емкости и запустите программу снова!\n";
                break;
            }
        }
        std::cout << "Кофемашина отключена! Приготовление кофе окончено!\n";
    }

    std::cout << "***Отчет***\n";
    std::cout << "Ингридиентов осталось:\n";
    std::cout << "\t\t\tВода: " << waterMl << " мл\n";
    std::cout << "\t\t\tМолоко: " << milkMl << " мл\n";
    std::cout << "Кружек американо приготовлено: " << countAmericano << '\n';
    std::cout << "Кружек латте приготовлено: " << countLatte << '\n';
}
#endif

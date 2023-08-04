#ifdef __MODULE_07__
#pragma once

#include <string>
const std::string string_tasks[] = {
    "\t\t\tЗадание 1. Запасы продовольствия\n  Ваш космический корабль потерпел крушение на пустынной планете. Еда здесь не растёт, но вы спасли из-под обломков 100-килограммовый мешок гречки. Из прошлого опыта вы знаете, что если будете экономно питаться, то у вас будет уходить по четыре килограмма гречки в месяц. Чтобы прикинуть гречневый бюджет, вы решили написать программу, которая выведет информацию о том, сколько килограммов гречки у вас должно быть в запасе через месяц, два и так далее, пока она не закончится.\n",
    "\t\t\tЗадание 2. Кофемашина\n  Инженеры компании «Спейс Инжиниринг» не могут продуктивно работать без кофе. Недавно в их кофемашину случайно попал космический луч и повредил программу-прошивку. Вас умоляют помочь. Кофемашина умеет готовить два напитка: американо и латте. Для американо требуется 300 мл воды, а для латте 30 мл воды и 270 мл молока.\n  Напишите программу, которая спрашивает у пользователя (это действие программа делает один раз в начале работы), сколько всего миллилитров молока и воды залито в кофемашину, после чего начинает обслуживание, спрашивая, какой напиток хочет очередной посетитель. Пользователь выбирает один из двух напитков, программа отвечает одним из трёх вариантов: «Ваш напиток готов», «Не хватает воды» или «Не хватает молока», после чего переходит к обслуживанию следующего посетителя. Если молока и воды не хватает ни на один вид напитка, программа выдаёт отчёт и завершается. В отчёте должно быть написано, что ингредиенты подошли к концу, должен быть указан остаток воды и молока в машине, а также должно быть указано, сколько всего было приготовлено чашек американо и латте за эту смену. Выберите наиболее удобный для написания программы цикл. Обеспечьте контроль ввода.\n",
    "\t\t\tЗадание 3. Красный Марс\n  В «Спейс Инжиниринг» были впечатлены тем, как вы справились с кофемашиной и решили отдать вам на аутсорс разработку программы для нового робота-разведчика поверхности Марса. Это первый прототип, поэтому он тестируется в прямоугольном помещении размером 15 на 20 метров. Марсоход высаживается в центре комнаты, после чего управление им передаётся оператору — пользователю вашей программы. Программа спрашивает, в какую сторону оператор хочет направить робота: север (клавиша W), юг (клавиша S), запад (клавиша A) или восток (клавиша D). Оператор делает выбор, марсоход перемещается на 1 метр в эту сторону и программа сообщает новую позицию марсохода. Если марсоход упёрся в стену, то он не должен пытаться перемещаться в сторону стены, в этом случае его позиция не меняется.\n",
    "\t\t\tЗадание 4. Рамка\n  Напишите программу, которая рисует с помощью символьной графики прямоугольную рамку. Для вертикальных линий используйте символ вертикального штриха «|», а для горизонтальных — дефис «-». Пусть пользователь вводит ширину и высоту рамки.\n",
    "\t\t\tЗадание 5. Координатные оси\n  Модифицируйте пример с координатными осями так, чтобы в точке их пересечения рисовался знак «+», на верхнем конце вертикальной оси была стрелка вверх «^», а на правом конце горизонтальной оси — стрелка вправо «>». Это сделает рисунок более красивым и точным.\n",
    "\t\t\tЗадание 6. Важные объявления\n  Напишите программу для печати важных объявлений. Сверху объявления должен располагаться вот такой колонтитул:\n~~~~~~~~~~~~~~~~~~~!!!!!!!!!!!~~~~~~~~~~~~~~~~~~~\n  Восклицательные знаки всегда располагаются по центру строки, причём в зависимости от важности объявления количество восклицательных знаков может быть разным. Напишите программу, которая спрашивает у пользователя сначала общую длину колонтитула в символах, потом желаемое количество восклицательных знаков, после чего выводит на экран готовую строку. Обеспечьте контроль ввода.\n",
    "\t\t\tЗадание 7. Биолаборатория* (дополнительное задание)\n  В борьбе со всемирной эпидемией коринебактерий исследователи компании «Терран Биотех» открыли новый антибиотик. Напишите программу, помогающую протестировать его.\n  В чашку Петри исследователи кладут N бактерий и добавляют X капель антибиотика. Известно, что число коринебактерий в чашке Петри увеличивается в два раза каждый час, а каждая капля антибиотика в первый час убивает 10 бактерий, во второй час — 9 бактерий, в следующий — 8 и так далее, пока антибиотик не перестанет действовать. Заметьте, что сначала число коринебактерий увеличивается, а затем действует антибиотик. Пользователь вашей программы вводит N и X, а программа печатает на экране, сколько бактерий останется в чашке Петри в конце каждого часа, до тех пор, пока не закончатся бактерии или антибиотик не перестанет действовать. Судьба человечества — в ваших руках. Обеспечьте контроль ввода.\n",
    "\t\t\tЗадание 8. Ёлочка* (дополнительное задание)\n  Напишите программу, которая выводит на экран равнобедренный треугольник, заполненный символами решётки «#». Пусть высота треугольника вводится пользователем. Обеспечьте контроль ввода.\n"
};

extern const std::string equals;

void Task_07_1();
void Task_07_2();
void Task_07_3();
void Task_07_4();
void Task_07_5();
void Task_07_6();
void Task_07_7();
void Task_07_8();
#endif

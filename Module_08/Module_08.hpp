#pragma once

const std::string string_tasks[] = {
    "\t\t\tЗадание 1. Космический симулятор\n  Вы пишете симулятор космических полётов. Ваш звездолёт массой m килограмм включает двигатель с силой тяги F ньютонов на t секунд. Напишите программу, которая по заданным F, m и t покажет, на каком расстоянии от первоначального положения окажется космический корабль через t секунд. Обеспечьте контроль ввода.\n  Примечание: космический корабль находится в открытом космосе.\n  Напоминаем, что расстояние можно рассчитать по формуле:\n  a * t ^ 2 / 2, где a = F / m\n",
    "\t\t\tЗадание 2. Immolate Improved!\n  Мы придумываем фэнтезийную онлайн-игру в жанре RPG. В орка стреляют огненными шарами разной степени мощности, но у него есть очки здоровья и показатель сопротивляемости магии. Очки здоровья, сопротивляемость магии и мощность огненного шара — это вещественные числа от нуля до единицы включительно. Чем больше мощность, тем больше урон здоровью, но чем больше сопротивляемость магии, тем урон меньше. Например, если сопротивляемость равна нулю (0%), то будет нанесён урон, равный мощности огненного шара. Если сопротивляемость равна единице (100%), урон будет равен нулю, даже если мощность заклинания максимальна.\n  Напишите программу, в которой пользователь сначала задаёт количество здоровья и сопротивляемость магии орка, а после стреляет в него огненными шарами разной мощности, пока орк не погибнет. Мощность удара вводится с клавиатуры с каждым выстрелом. После каждого заклинания программа выводит на экран итоговый урон от удара и оставшиеся очки здоровья орка. Показатель сопротивляемости магии не изменяется при попадании. Обеспечьте контроль ввода.\n  Обратите внимание, что сопротивляемость обозначает только долю от повреждения, которая приходится на орка. Пример:\n  Урон 0.1, сопротивляемость 0.5, по орку будет нанесено 0.05 урона;\n  Урон 0.2, сопротивляемость 0.5, по орку будет нанесено 0.1 урона;\n  Урон 1, сопротивляемость 0.2, по орку будет нанесено 0.8 урона.\n",
    "\t\t\tЗадание 3. Игрушечная история\n  Вы решили открыть бизнес по производству игровых деревянных кубиков для детей. Вы узнали, что лучше всего продаются кубики со стороной 5 см в наборах по несколько штук, причём кубиков в наборе должно быть достаточно, чтобы сложить из них один большой куб. Для изготовления кубиков к вам в мастерскую поступают деревянные бруски в форме прямоугольных параллелепипедов любых размеров.\n  Для оптимизации бизнес-процессов напишите программу, которая по заданным размерам исходного бруска определяет, сколько кубиков из него можно изготовить, можно ли из них составить набор для продажи и если можно, то максимальное число кубиков в этом наборе. Все кубики должны быть из цельного дерева без использования клея. Размеры бруска — вещественные числа. Обеспечьте контроль ввода.\n  Например:\n  Из бруска 20x35x5 можно изготовить 28 кубиков.\n  Из 28 кубиков можно собрать набор из 27 кубиков.\n",
    "\t\t\tЗадание 4. Убийца Steam\n  Вы пишете программу-инсталлятор для компьютерной игры. Пока обновление скачивается, пользователю нужно показать прогресс загрузки, чтобы он мог решить, подождать ему у экрана компьютера или заварить чай.\n  Напишите программу, принимающую на вход размер файла обновления в мегабайтах и скорость интернет-соединения в мегабайтах в секунду. В каждую секунду программа показывает, сколько процентов от общего объёма обновления уже скачано, до тех пор, пока файл не загрузится. После установки обновления программа выводит время в секундах, которое заняло скачивание. Обеспечьте контроль ввода.\n",
    "\t\t\tЗадание 5. Кенийский бегун\n  Самуэль родился в Кении, и когда он немного подрос, то решил сделать карьеру профессионального бегуна. Во время тренировок на стадионе он стал запоминать свой темп на каждом километре с помощью простых наручных часов с секундной стрелкой. После тренировки он хотел бы узнать свой средний темп бега, но не может этого сделать: в Кении дети, решившие стать бегунами, обычно не ходят в школу. Помогите Самуэлю.\n  Напишите программу для расчёта среднего темпа бега. Темп измеряется в секундах на километр и означает количество времени, которое бегун потратит на преодоление одного километра. Программа должна получить на вход количество километров, покрытое за тренировку, и темп в секундах на каждый из этих километров. На выходе программа выводит на экран средний темп в минутах и секундах за всю тренировку. Обеспечьте контроль ввода.\n",
    "\t\t\tЗадание 6. Маятник\n  Известно, что амплитуда качающегося маятника с каждым разом затухает на 8,4% от амплитуды прошлого колебания. Если качнуть маятник, он, строго говоря, никогда не остановится: его амплитуда будет уменьшаться до тех пор, пока мы не сочтём такой маятник остановившимся. Напишите программу, определяющую, сколько раз качнётся маятник, прежде чем он, по нашему мнению, остановится. Программа получает на вход начальную амплитуду колебания в сантиметрах и конечную амплитуду его колебаний, которая считается остановкой маятника. Обеспечьте контроль ввода.\n",
    "\t\t\tЗадание 7. Друзья Оушена* (дополнительное задание)\n  Банковский сейф оборудован механическим кодовым замком, состоящим из N крутящихся ручек, каждая из которых имеет K положений. Существует только одна комбинация положений всех N ручек, которая открывает сейф. Чтобы его открыть, достаточно перебрать все существующие комбинации. На проверку одной комбинации уходит в среднем T секунд, где T — вещественное число. Напишите программу, которая по заданным N, K и T определяет время, которое потребуется для перебора всех комбинаций и гарантированного открытия сейфа. Не используйте циклы. Обеспечьте контроль ввода.\n",
    "\t\t\tЗадание 8. Биолаборатория 2.0* (дополнительное задание)\n  Благодаря вашей помощи компания «Терран Биотех» вышла на финишную прямую в борьбе со всемирной эпидемией коринебактерий. Однако прошлая симуляция была недостаточно точной, да и новая версия антибиотика работает по-другому.\n  В чашку Петри добавляется W капель воды, D капель чистого антибиотика и подселяется N коринебактерий. Известно, что каждую минуту количество бактерий изменяется прямо пропорционально концентрации антибиотика в растворе по формуле Nnew = 2 × Nold − Nold × D / W, где Nold — количество коринебактерий минуту назад, Nnew — их новое количество, а D / W — концентрация действующего антибиотика. При этом каждую минуту 20% от всего количества антибиотика разлагается и больше не действует.\n  Напишите программу, которая получает на вход значения W, D и Nold и симулирует процесс в течение 20 минут, для каждой минуты выводя на экран текущую концентрацию антибиотика и количество живых коринебактерий в чашке Петри. Обеспечьте контроль ввода.\n",
    "\t\t\tЗадание 9. Яйца* (дополнительное задание)\n  В рамках программы колонизации Марса компания «Спейс Инжиниринг» вывела особую породу черепах, которые должны размножаться, откладывая яйца в марсианском грунте. Откладывать яйца слишком близко к поверхности опасно из-за радиации, а слишком глубоко опасно из-за давления грунта и недостатка кислорода. Вообще, факторов много, но специалисты проделали большую работу и предположили, что уровень опасности для черепашьих яиц рассчитывается по формуле D = x^3 − 3x^2 − 12x + 10, где x — глубина кладки в метрах, а D — уровень опасности в условных единицах. Для тестирования гипотезы нужно взять пробу грунта на безопасной, согласно формуле, глубине.\n  Напишите программу, находящую такое значение глубины х, при котором уровень опасности наиболее близок к нулю, учитывая допустимое отклонение. На вход программе подаётся максимально допустимое отклонение уровня опасности от нуля, а программа должна рассчитать приблизительное значение х, удовлетворяющее этому отклонению. Известно, что глубина точно больше нуля и меньше четырёх метров.\n  Обеспечьте контроль ввода.\n",
    "\t\t\tЗадание 10. Тяжело в учении, легко в бою* (дополнительное задание)\n  Вы встретились со своим старым другом, который тоже изучает программирование, правда, в другом учебном заведении. За чашкой кофе он пожаловался, что сумасбродный препод дал задание написать программу, которая из двух введённых чисел определяет наибольшее, не используя при этом условных операторов и циклов. Радуясь, что на вашем курсе такого не требуют, вы всё-таки решаете помочь своему другу. Напишите для него эту программу.\n"
};

extern const std::string equals;

void Task_08_1();
void Task_08_2();
void Task_08_3();
void Task_08_4();
void Task_08_5();
void Task_08_6();
void Task_08_7();
void Task_08_8();
void Task_08_9();
void Task_08_10();

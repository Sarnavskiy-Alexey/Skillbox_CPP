#ifdef __MODULE_21__
#pragma once

#include <string>
#include <cstring>
const std::string string_tasks[] = {
    "\t\t\tЗадание 1. Ведомость учёта\n  Что нужно сделать\n  Вы уже создавали программу чтения и записи ведомости. Теперь её нужно обобщить и дополнить использованием структур.\n  Формат ведомости прежний: \n  - сначала — имя и фамилия получателя денег,\n  - далее — дата выдачи в формате ДД.ММ.ГГГГ,\n  - затем — сумма выплаты в рублях.\n  Данные разделяются пробелами. В конце каждой записи должен быть перевод строки. Структура данных должна соответствовать этому формату.\n  При старте программы пользователь отправляет команду: list или add. Команда list осуществляет чтение из файла ведомости, как и прежде, только уже в структуры данных, и отображает их на экране.\n  Команда add добавляет новую запись в конец ведомости.\n\n  Советы и рекомендации:\n  - Чтобы определить, где заканчивается файл, используйте функцию file.eof().\n  - Из-за завершающего переноса строки при чтении данных из файла стоит отдельно прочитать имя получателя денег. Если после чтения имени получателя денег признак file.eof() принял значение true, значит, файл закончился.\n  - Используйте вектор структур. Для выбора команды потребуется подобная конструкция:\n      if (command == \"list\")\n      {\n      ...\n      }\n",
    "\t\t\tЗадание 2. Модель данных для посёлка\n  Что нужно сделать\n  Используя структуры данных, создайте подробную модель посёлка.\n  Что известно\n  - Посёлок состоит из участков, и у каждого участка есть свой номер.\n  - На любом участке может стоять жилой дом, а также могут быть и другие сооружения:\n    * гараж,\n    * сарай (бытовка),\n    * баня.\n  - У каждого здания есть информация о площади, которую оно занимает на участке.\n  - В доме может быть 1–3 этажа, на этаже — 2–4 комнаты:\n    * спальня,\n    * кухня,\n    * ванная,\n    * детская,\n    * гостиная.\n  - У каждого этажа есть информация о количестве комнат и высоте потолка на этаже.\n  - У каждой комнаты есть информация о занимаемой площади.\n  - В доме и бане может быть печь с трубой.\n\n  Для всех упомянутых сущностей нужно объявить структуры данных.\n  Обязательно для выполнения задания:\n  Опишите структуры данных для создания модели посёлка. Структуры должны быть:\n  - связными и легко расширяемыми,\n  - без дублирующих конструкций.\n\n  Дополнительно\n  Реализуйте заполнение структур данных.\n  Пользователь заполняет данные о посёлке: вводит общее количество участков, а потом детализирует каждый.\n  Сначала указывается количество построек на участке, а затем — информация, какие это постройки, сколько этажей в доме, какие комнаты на этажах.\n  После ввода данных можно рассчитать суммарный параметр, например процент земли, занимаемой постройками, от общей площади посёлка. Главное в этой задаче не операция подсчёта, а структуры данных.\n\n  Советы и рекомендации:\n  - Используйте свои знания о типах данных в C++.\n  - Можно применять перечисления и векторы, создавать структуры внутри структур и так далее.\n  - Перечислять комнаты и типы зданий нужно следующим образом:\n      enum room_type\n      {\n      living,\n      children,\n      ...\n      }\n  - Затем нужно использовать полученный тип внутри структуры. Алгоритм заполнения каждого объекта одинаковый:\n    * создать объект нужного типа,\n    * ввести с клавиатуры значения,\n    * добавить объект в вектор при помощи push_back.\n",
    "\t\t\tЗадание 3. Математический вектор\n  Что нужно сделать\n  Реализуйте структуру двумерного математического вектора и основные операции над ним. Обе координаты вектора (x и y) должны быть вещественными числами.\n  Начиная работу с программой, пользователь вводит команду. Затем в зависимости от команды пользователь вводит аргументы. Это могут быть как векторы, так и обычные скалярные значения. Результат помещается в стандартный вывод. Это тоже может быть или вектор, или скаляр.\n  Реализуйте в виде отдельных функций операции:\n  - сложение двух векторов — команда add;\n  - вычитание двух векторов — команда subtract;\n  - умножение вектора на скаляр — команда scale;\n  - нахождение длины вектора — команда length;\n  - нормализация вектора — команда normalize.\n\n  Советы и рекомендации\n  Для выбора команды используйте конструкцию вида if (operation == \"add\"). Тут так и напрашиваются отдельные функции для каждой операции.\n",
    "\t\t\tЗадание 4. Пошаговая ролевая игра (дополнительное задание)\n  Что нужно сделать\n  Реализуйте упрощённую версию пошаговой ролевой игры.\n  Действие разворачивается на карте размером 20 на 20 клеток. По клеткам перемещаются игрок и его противники.\n  После каждого хода игрока карта показывается вновь со всеми противниками на ней:\n  - игрок помечается буквой P,\n  - противники — буквой E,\n  - пустые места — точкой.\n  Каждый персонаж игры представлен в виде структуры с полями:\n  - «Имя»,\n  - «Жизни»,\n  - «Броня»,\n  - «Урон».\n  Сначала создаётся пять противников в случайных клетках карты:\n  - Имена противникам задаются в формате Enemy #N, где N — порядковый номер.\n  - Уровень жизни противников задаётся случайно — от 50 до 150.\n  - Уровень брони варьируется от 0 до 50.\n  - Урон тоже выбирается случайно — от 15 до 30 единиц.\n  - Игрок конструирует своего персонажа самостоятельно. Задаёт все его параметры, включая имя. Все персонажи появляются в случайных местах карты.\n  Игрок ходит с помощью команд: L, R, U, D (по первым буквам слов left, right, up, down). В зависимости от команды выбирается направление перемещения: влево, вправо, вверх, вниз.\n  Противники перемещаются в случайном направлении.\n  Если игрок перемещается в сторону, где уже кто-то находится, он наносит этому персонажу урон. Противники при этом никогда не бьют друг друга: они просто пропускают ход и остаются на своём месте. За пределы карты (20 на 20 клеток) ходить нельзя никому. Если кто-то выбрал направление за границами, ход пропускается.\n  Формула расчёта урона совпадает с той, что была в материале. Жизни уменьшаются на размер урона. При этом броня тоже сокращается на приведённый урон.\n  Игра заканчивается тогда, когда умирают либо все противники, либо игрок. В первом случае на экран выводится сообщение о победе, во втором — о поражении.\n  Если в начале хода игрок вводит команду save или load вместо направления перемещения, то игра либо сохраняет своё состояние в файл, либо загружает это состояние из файла.\n\n  Советы и рекомендации:\n  - Для определения команды персонажа можно внутри структуры данных о нём завести флаг.\n  - Для отображения координат персонажей можно использовать структуру вектора из другой задачи, но заменить типы координат.\n  - Для сохранения параметров игры и их загрузки можно работать с текстовыми данными. Однако записать всё в двоичном формате проще, главное — соблюдать последовательность полей:\n       std::ofstream file(\"save.bin\", std::ios::binary);\n       for (int i = 0; i < 6; ++i) {\n           file.write((char*)&(characters[i].position),\n                      sizeof(characters[i].position));\n       ...\n  - При загрузке используйте ifstream и ту же последовательность полей.\n\n  Задание необязательно сдавать на проверку. Но если хотите это сделать, куратор будет учитывать следующее:\n  - Корректно работает сохранение и загрузка в игре.\n  - После загрузки все атрибуты игрока, включая имя, восстанавливаются из файла.\n  - После загрузки количество противников на поле соответствует количеству противников при сохранении.\n  - Все игроки после загрузки появляются в местах, где они находились при сохранении.\n  - При ходе игрока не появляются новые противники.\n  - Перед загрузкой файла сохранения проверяется, есть ли он в операционной системе.\n"
};

extern const std::string equals;
const std::string CUR_DIR(__FILE__, strlen(__FILE__) - strlen("Module_21.hpp"));
const std::string DOCS_DIR = "docs\\";

void Task_21_1();
void Task_21_2();
void Task_21_3();
void Task_21_4();
#endif

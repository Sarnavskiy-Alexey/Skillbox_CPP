#ifdef __MODULE_21__
/* Задание 2. Модель данных для посёлка
 *  Что нужно сделать
 *  Используя структуры данных, создайте подробную модель посёлка.
 *  Что известно
 *  - Посёлок состоит из участков, и у каждого участка есть свой номер.
 *  - На любом участке может стоять жилой дом, а также могут быть и другие сооружения:
 *    = гараж,
 *    = сарай (бытовка),
 *    = баня.
 *  - У каждого здания есть информация о площади, которую оно занимает на участке.
 *  - В доме может быть 1–3 этажа, на этаже — 2–4 комнаты:
 *    = спальня,
 *    = кухня,
 *    = ванная,
 *    = детская,
 *    = гостиная.
 *  - У каждого этажа есть информация о количестве комнат и высоте потолка на этаже.
 *  - У каждой комнаты есть информация о занимаемой площади. 
 *  - В доме и бане может быть печь с трубой.
 *  Для всех упомянутых сущностей нужно объявить структуры данных.
 *  
 *  Обязательно для выполнения задания:
 *  Опишите структуры данных для создания модели посёлка. Структуры должны быть:
 *  - связными и легко расширяемыми,
 *  - без дублирующих конструкций.
 *  
 *  Дополнительно
 *  Реализуйте заполнение структур данных.
 *  Пользователь заполняет данные о посёлке: вводит общее количество участков, а потом детализирует
 *  каждый.
 *  Сначала указывается количество построек на участке, а затем — информация, какие это постройки,
 *  сколько этажей в доме, какие комнаты на этажах.
 *  После ввода данных можно рассчитать суммарный параметр, например процент земли, занимаемой
 *  постройками, от общей площади посёлка. Главное в этой задаче не операция подсчёта, а структуры
 *  данных.
 *  
 *  Советы и рекомендации
 *  - Используйте свои знания о типах данных в C++.
 *  - Можно применять перечисления и векторы, создавать структуры внутри структур и так далее.
 *  - Перечислять комнаты и типы зданий нужно следующим образом:
 *      enum room_type
 *      {
 *      living,
 *      children,
 *      ...
 *      }
 *  - Затем нужно использовать полученный тип внутри структуры. Алгоритм заполнения каждого объекта
 *    одинаковый:
 *    = создать объект нужного типа,
 *    = ввести с клавиатуры значения,
 *    = добавить объект в вектор при помощи push_back. */

#include <iostream>
#include <vector>
#include "Module_21.hpp"

// тип комнаты
enum class room_type {
    bedroom,  // спальня
    kitchen,  // кухня
    bathroom, // ванная
    children, // детская
    living,   // гостиная
    size      // количество элементов перечисления
};

// тип здания
enum class building_type {
    house,  // жилое здание
    garage, // гараж
    sauna,  // баня
    shed,   // сарай (бытовка)
    size    // количество элементов перечисления
};

static const std::vector<std::string> in_room = {"спальне", "кухне", "ванной", "детской", "гостиной"};
static const std::vector<std::string> in_building = {"жилом здании", "гараже", "бане", "сарае"};

// описание комнаты
struct Room {
    room_type type;
    float square;
};

// описание этажа
struct Floor {
    std::vector<Room> rooms;
    float ceilingHeight = 0.0f;
};

// описание здания
struct Building {
    float square = 0.0f;
    building_type type = building_type::house;
    std::vector<Floor> floors;
    bool oven = false;
};

// описание участка
struct Plot {
    unsigned short number = 0;
    std::vector<Building> buildings;
};

// описание поселка
struct Village {
    std::string name = "Summertown";
    std::vector<Plot> plots;
};

// безопасный ввод целого беззнакового числа
static unsigned int safe_enter(std::string invite_str, std::string error_str,
                               unsigned int left, unsigned int right) {
    unsigned int X;
    do {
        std::cout << invite_str;
        std::cin >> X;
        if (X < left || X > right)
            std::cout << error_str;
    } while (X < left || X > right);
    
    return X;
}

// безопасный ввод вещественного числа одинарной точности
static float safe_enter(std::string invite_str, std::string error_str) {
    float X;
    do {
        std::cout << invite_str;
        std::cin >> X;
        if (X <= 0.0f)
            std::cout << error_str;
    } while (X <= 0.0f);
    
    return X;
}

// функция ввода данных о комнате на этаже
static void add_room(Room& room) {
    std::cout << "Определите тип комнаты:\n";
    std::cout << "    0 - спальня;\n";
    std::cout << "    1 - кухня;\n";
    std::cout << "    2 - ванная;\n";
    std::cout << "    3 - детская;\n";
    std::cout << "    4 - гостиная.\n";

    room.type = (room_type)safe_enter("Ваш выбор: ",
                           "ОШИБКА! Тип комнаты должен быть выбран из выше перечисленных!\n",
                           0U, (unsigned int)room_type::size - 1U);
    
    // определяем площадь комнаты
    room.square = safe_enter("Введите площадь комнаты: ",
                             "ОШИБКА! Площадь комнаты должна быть положительной!\n");
}

// функция ввода данных об этаже в жилом доме
static void add_floor(Floor& floor) {
    unsigned int rooms;
    floor.ceilingHeight = safe_enter("Введите высоту потолка на этаже: ",
                                     "ОШИБКА! Высота потолка должна быть положительной!\n");
    
    rooms = safe_enter("Введите количество комнат на этаже: ",
                       "ОШИБКА! Количество комнат должно быть от 2 до 4!\n",
                       2U, 4U);
    for (unsigned i = 0; i < rooms; i++) {
        std::cout << "Введите данные о комнате #" << i + 1 << " текущего этажа!\n";
        Room room;
        floor.rooms.push_back(room);
        add_room(floor.rooms[i]);
    }
}

// функция ввода данных о здании на участке
static void add_building(Building& building) {
    unsigned int floors;
    std::cout << "Определите тип здания:\n";
    std::cout << "    0 - жилое;\n";
    std::cout << "    1 - гараж;\n";
    std::cout << "    2 - баня;\n";
    std::cout << "    3 - сарай.\n";
    
    building.type = (building_type)safe_enter("Ваш выбор: ",
                               "ОШИБКА! Тип здания должен быть выбран из выше перечисленных!\n",
                               0U, (unsigned int)building_type::size - 1U);

    // определяем площадь здания
    building.square = safe_enter("Введите площадь здания: ",
                                 "ОШИБКА! Площадь здания должна быть положительной!\n");

    // если тип здания определен жилым или баней, то определяем наличие печки с трубой
    if (building.type == building_type::house || building.type == building_type::sauna) {
        std::string answer;
        std::cout << "Есть ли в здании печь с трубой? (Y/N)";
        std::cin >> answer;
        if (answer == "Y" || answer == "y")
            building.oven = true;
    }

    // если тип здания определен жилым, то определяем количество этажей в здании
    if (building.type == building_type::house) {
        floors = safe_enter("Введите количество этажей: ",
                            "ОШИБКА! Количество этажей должно быть в пределах от 1 до 3!\n",
                            1U, 3U);
        // определяем каждый из этажей здания
        for (unsigned int i = 0; i < floors; i++) {
            std::cout << "Введите данные об этаже #" << i + 1 << " жилого здания!\n";
            Floor floor;
            building.floors.push_back(floor);
            add_floor(building.floors[i]);
        }
    }
}

// функция ввода данных об участке в поселке
static void add_plot(Plot& plot) {
    unsigned int buildingSize;

    // определяем номер участка
    plot.number = safe_enter("Введите номер участка: ",
                             "ОШИБКА! Номер участка должен быть положительным!\n",
                             1U, -1U);

    // определяем количество зданий на участке
    std::cout << "Сколько зданий на территории участка #" << plot.number << ": ";
    std::cin >> buildingSize;

    std::cout << "Введите данные обо всех зданиях на участке #" << plot.number << ":\n";
    for (unsigned int i = 0; i < buildingSize; i++) {
        Building building;
        plot.buildings.push_back(building);
        add_building(plot.buildings[i]);
    }
}

// функция вывода на экран комнаты
static void print_room(const Room& room) {
    std::cout << "\t\t\t\t";
    std::cout << "Площадь в " << in_room[(unsigned int)room.type]
              << " равна: " << room.square << "\n";
}

// функция вывода на экран этажа
static void print_floor(const Floor& floor) {
    std::cout << "\t\t\t";
    std::cout << "На этом этаже потолок имеет следующую высоту: " << floor.ceilingHeight << "\n";
    std::cout << "\t\t\t";
    std::cout << "На этом этаже расположено " << floor.rooms.size() << " комнаты\n";
    std::cout << "\t\t\t";
    std::cout << "Характеристика каждой комнаты:\n";
    for (const Room& room : floor.rooms) {
        print_room(room);
    }
}

// функция вывода на экран здания
static void print_building(const Building& building) {
    std::cout << "\t\t";
    std::cout << "В " << in_building[(unsigned int)building.type] << " "
              << (building.oven ? "есть" : "отсутствует")<< " печь с трубой.\n";
    std::cout << "\t\t";
    std::cout << "Это здание имеет следующую площадь: " << building.square << "\n";
    if (building.type == building_type::house) {
        std::cout << "\t\t";
        std::cout << "В этом здании следующее количество этажей: " << building.floors.size() << "\n";
        for (unsigned int i = 0; i < building.floors.size(); i++) {
            std::cout << "\t\t";
            std::cout << "Характеристика " << i + 1 << "-го этажа:\n";
            print_floor(building.floors[i]);
        }
    }
}

// функция вывода на экран участка
static void print_plot(const Plot& plot) {
    std::cout << "\t";
    std::cout << "На участке #" << plot.number << " находится следующее количество зданий: "
              << plot.buildings.size() << "\n";
    for (const Building& building : plot.buildings) {
        print_building(building);
    }
}

// функция вывода на экран поселка
static void print_village(const Village& village) {
    std::cout << "В поселке " << village.name << " находится следующее количество участков: "
              << village.plots.size() << "\n";
    for (const Plot& plot : village.plots) {
        print_plot(plot);
    }
}

void Task_21_2() {
    std::cout << equals << string_tasks[1] << equals;

    Village village;
    unsigned int villageSize;
    std::cout << "Введите название поселка: ";
    std::cin >> village.name;
    std::cout << "Укажите количество участков в поселке: ";
    std::cin >> villageSize;

    std::cout << "Введите данные обо всех участках в поселке:\n";
    for (unsigned int i = 0; i < villageSize; i++) {
        Plot plot;
        village.plots.push_back(plot);
        add_plot(village.plots[i]);
    }

    print_village(village);
}
#endif

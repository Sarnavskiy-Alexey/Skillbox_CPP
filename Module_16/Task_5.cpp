#ifdef __MODULE_16__
/* Задание 5. Умный дом
 *  Что нужно сделать
 *  Разработайте упрощённую модель умного дома для дачи. Выполните симуляцию его работы на
 *  протяжении двух дней. Стартовое время для симуляции умного дома 00:00. Есть несколько датчиков:
 *  датчик температуры снаружи, датчик температуры внутри дома. В доме расположен электронный умный
 *  щиток с автоматами. Каждый автомат отвечает за включение и отключение определённых устройств или
 *  групп устройств:
 *  1. отключение и включение питания всего дома;
 *  2. основные розетки дома;
 *  3. свет внутри дома;
 *  4. наружный свет в саду;
 *  5. отопление в помещении;
 *  6. отопление водопровода, идущего из скважины с насосом;
 *  7. кондиционер в помещении.
 *  
 *  Есть несколько условий по включению/отключению техники в доме и вне его.
 *  - Как только температура снаружи падает ниже 0 °С, надо включить систему обогрева водопровода.
 *    Если температура снаружи поднялась выше 5 °С, то систему обогрева водопровода нужно отключить.
 *  - Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) и снаружи есть какое-то движение,
 *    то необходимо включить садовое освещение. Если движения нет или время не вечернее, то света
 *    снаружи быть не должно.
 *  - Если температура в помещении упала ниже 22 °С, должно включиться отопление. Как только
 *    температура равна или поднимается выше 25 °С, отопление автоматически отключается.
 *    Если температура в помещении поднялась до 30 °С, включается кондиционер. Как только
 *    температура становится 25 °С, кондиционер отключается.
 *  - Всё освещение в доме также умное и поддерживает настройку цветовой температуры для комфортного
 *    нахождения. Каждый день начиная с 16:00 и до 20:00 температура цвета должна плавно изменяться с
 *    5000K до 2700К. Разумеется, это изменение должно происходить, если свет сейчас включён. В 00:00
 *    температура сбрасывается до 5000К.
 *  
 *  Все события по отключению и включению устройств должны выводиться в консоль явным образом. Если
 *  устройство не изменило своё состояние (осталось включённым или выключенным), событие
 *  генерироваться не должно! Если свет в доме включён, должна отображаться текущая цветовая
 *  температура.
 *  
 *  Программа выполняется следующим образом:
 *  - Каждый час пользователь сообщает состояние всех основных датчиков и света (температура
 *    снаружи, температура внутри, есть ли движение снаружи, включён ли свет в доме).
 *  - Данные параметры вводятся разом в одну строку через пробел, а потом парсятся в переменные из
 *    строкового буфера stringstream.
 *  - Информация о движении выводится в формате yes/no.
 *  - Включение и отключение света происходит с помощью on/off.
 *  
 *  Рекомендации:
 *  Состояние переключателей можно хранить в перечислении вида:
 *  enum switches 
 *  { 
 *      LIGHTS_INSIDE = 1, 
 *      LIGHTS_OUTSIDE = 2, 
 *      HEATERS = 4, 
 *      WATER_PIPE_HEATING = 8, 
 *      CONDITIONER = 16 
 *  };
 *  
 *  Чтобы включить обогреватель, нужно написать switches_state |= HEATERS; Чтобы выключить —
 *  switches_state &= ~HEATERS;
 *  
 *  Пример работы программы:
 *  
 *  Temperature inside, temperature outside, movement, lights:
 *  10 10 yes on
 *  Heaters ON!
 *  Lights ON!
 *  Color temperature: 5000K
 *  Temperature inside, temperature outside, movement, lights:
 *  10 10 yes on
 *  Color temperature: 5000K
 *  Temperature inside, temperature outside, movement, lights:
 *  30 30 yes on
 *  Heaters OFF!
 *  Conditioner ON!
 *  Color temperature: 5000K
 *  Temperature inside, temperature outside, movement, lights:
 *  30 30 yes on
 *  Color temperature: 5000K
 *  Temperature inside, temperature outside, movement, lights: */

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "Module_16.hpp"

// для включения и отключения автоматов
enum switches {
    ALL_HOME = 1,
    MAIN_SOCKETS = 2,
    LIGHTS_INSIDE = 4,
    LIGHTS_OUTSIDE = 8,
    HEATERS = 16,
    WATER_PIPE_HEATING = 32,
    CONDITIONER = 64
};

// безопасный ввод потока строки
static std::stringstream safe_enter_stream(std::string invite_str,     // приглашение к вводу
                                           std::string error_str,      // ошибка в строке
                                           std::string error_movement, // ошибка в движении
                                           std::string error_lights,   // ошибка в свете
                                           std::string error_long_str  // ошибка длинной строки
                                                                     ) {
    std::string buffer;
    std::stringstream buffer_stream;
    bool right_buf;
    
    do {
        int temperature_out, temperature_in;
        std::string movement, lights, error;
        
        // инициализация
        buffer_stream.str("");
        right_buf = true;

        // получение данных
        std::cout << invite_str;
        std::getline(std::cin, buffer);

        // обработка буферов
        std::stringstream tmp_buf_str(buffer);
        buffer_stream << tmp_buf_str.str();
        tmp_buf_str >> temperature_out >> temperature_in >> movement >> lights >> error;

        // проверка выполнения условий заполнения буфера
        if (movement.size() == 0 || lights.size() == 0) {
            std::cout << error_str;
            right_buf = false;
        } else if (movement != "yes" && movement != "no") {
            std::cout << error_movement;
            right_buf = false;
        } else if (lights != "on" && lights != "off") {
            std::cout << error_lights;
            right_buf = false;
        } else if (error.size()) {
            std::cout << error_long_str;
            right_buf = false;
        }
    } while (!right_buf);

    return buffer_stream;
}

// включение любого автомата
static void turn_on(int& switch_state, switches sw) {
    if (!(switch_state & sw)) {
        switch_state |= sw;
        switch (sw) {
            case ALL_HOME: std::cout << "Питание всего дома включено!\n"; break;
            case MAIN_SOCKETS: std::cout << "Основные розетки дома включены!\n"; break;
            case LIGHTS_INSIDE: std::cout << "Свет внутри дома включен!\n"; break;
            case LIGHTS_OUTSIDE: std::cout << "Наруженый свет в саду включен!\n"; break;
            case HEATERS: std::cout << "Отопление в помещении включено!\n"; break;
            case WATER_PIPE_HEATING: std::cout << "Отопление водопровода включено!\n"; break;
            case CONDITIONER: std::cout << "Кондиционер в помещении включен!\n"; break;
        }
    }
}

// отключение любого автомата
static void turn_off(int& switch_state, switches sw) {
    if (switch_state & sw) {
        switch_state &= ~sw;
        switch (sw) {
            case ALL_HOME: std::cout << "Питание всего дома отключено!\n"; break;
            case MAIN_SOCKETS: std::cout << "Основные розетки дома отключены!\n"; break;
            case LIGHTS_INSIDE: std::cout << "Свет внутри дома отключен!\n"; break;
            case LIGHTS_OUTSIDE: std::cout << "Наруженый свет в саду отключен!\n"; break;
            case HEATERS: std::cout << "Отопление в помещении отключено!\n"; break;
            case WATER_PIPE_HEATING: std::cout << "Отопление водопровода отключено!\n"; break;
            case CONDITIONER: std::cout << "Кондиционер в помещении отключен!\n"; break;
        }
    }
}

// проверка необходимости изменения состояния обогрева водопровода
static void check_water_heater(int& switch_state, int temperature_out) {
    if (temperature_out < 0)
        turn_on(switch_state, WATER_PIPE_HEATING);
    else if (temperature_out > 5)
        turn_off(switch_state, WATER_PIPE_HEATING);
}

// проверка необходимости изменения состояния садового освещения
static void check_lights_out(int& switch_state, int time, bool movements) {
    if ((time > 16 || time < 5) && movements)
        turn_on(switch_state, LIGHTS_OUTSIDE);
    else
        turn_off(switch_state, LIGHTS_OUTSIDE);
}

// проверка необходимости изменения состояния отопления
static void check_heaters(int& switch_state, int temperature_in) {
    if (temperature_in < 22)
        turn_on(switch_state, HEATERS);
    else if (temperature_in >= 25)
        turn_off(switch_state, HEATERS);
}

// проверка необходимости изменения состояния кондиционера
static void check_conditioner(int& switch_state, int temperature_in) {
    if (temperature_in >= 30)
        turn_on(switch_state, CONDITIONER);
    else if (temperature_in <= 25)
        turn_off(switch_state, CONDITIONER);
}

// проверка необходимости изменения освещения
static void check_lights_in(int& switch_state, int& light_temperature, int time, bool lights_on) {
    // сброс температуры света
    if (time == 0)
        light_temperature = 5000;
    // включен ли свет
    if (lights_on) {
        turn_on(switch_state, LIGHTS_INSIDE);
        if (time >= 16 && time <= 20)
            light_temperature = 5000.0 - (time - 16.0) * (5000.0 - 2700.0) / (20.0 - 16.0);
        std::cout << "Температура света: " << light_temperature << "\n";
    } else
        turn_off(switch_state, LIGHTS_INSIDE);
}

void Task_16_5() {
    std::cout << equals << string_tasks[4] << equals;

    // строковые константы ошибок в вводе пользователем значений
    const std::string invite_str = "Введите строку со следующими элементами через пробел:\n\t\t - <температура снаружи>\n\t\t - <температура внутри>\n\t\t - <есть ли движение снаружи (yes/no)>\n\t\t - <включен ли свет в доме (on/off)>:\n";
    const std::string error_str = "ОШИБКА! Строка введена неверно!\n";
    const std::string error_movement = "ОШИБКА! Движение снаружи задается словами yes и no!\n";
    const std::string error_lights = "ОШИБКА! Состояние света задается словами on и off!\n";
    const std::string error_long_str = "ОШИБКА! Введена слишком длинная строка!\n";

    // переменные, вводимые пользователем
    int temperature_out, temperature_in;
    std::string movement, lights;

    // переменные состояния
    int switch_state = 0;
    int light_temperature = 0;

    // инициализация симуляции
    std::cout << "\tСИМУЛЯЦИЯ НАЧАТА!\n";
    turn_on(switch_state, ALL_HOME);
    turn_on(switch_state, MAIN_SOCKETS);

    // очистка буфера ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // основная логика симуляции
    for (int time = 0; time < 48; time++) {
        std::cout << "\tДень " << time / 24 + 1 << "-й. " << "Текущее время: " << ((time % 24) < 10 ? "0" : "") + std::to_string(time % 24) << ":00\n";
        std::stringstream buffer_stream = safe_enter_stream(invite_str,
                                                            error_str,
                                                            error_movement,
                                                            error_lights,
                                                            error_long_str);
        
        // чтение данных из буфера в переменные
        buffer_stream >> temperature_out >> temperature_in >> movement >> lights;

        // проверка всех автоматов
        check_water_heater(switch_state, temperature_out);
        check_lights_out(switch_state, time % 24, movement == "yes");
        check_heaters(switch_state, temperature_in);
        check_conditioner(switch_state, temperature_in);
        check_lights_in(switch_state, light_temperature, time % 24, lights == "on");
    }

    // окончание симуляции
    turn_off(switch_state, MAIN_SOCKETS);
    turn_off(switch_state, ALL_HOME);
    std::cout << "\tСИМУЛЯЦИЯ ОКОНЧЕНА!\n";
}
#endif

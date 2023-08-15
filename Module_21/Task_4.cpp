#ifdef __MODULE_21__
/* Задание 4. Пошаговая ролевая игра (дополнительное задание)
 *  Что нужно сделать
 *  Реализуйте упрощённую версию пошаговой ролевой 
 *  Действие разворачивается на карте размером 20 на 20 клеток. По клеткам перемещаются игрок и его
 *  противники.
 *  После каждого хода игрока карта показывается вновь со всеми противниками на ней:
 *  - игрок помечается буквой P,
 *  - противники — буквой E,
 *  - пустые места — точкой.
 *  Каждый персонаж игры представлен в виде структуры с полями:
 *  - «Имя»,
 *  - «Жизни»,
 *  - «Броня»,
 *  - «Урон».
 *  Сначала создаётся пять противников в случайных клетках карты:
 *  - Имена противникам задаются в формате Enemy #N, где N — порядковый номер.
 *  - Уровень жизни противников задаётся случайно — от 50 до 150.
 *  - Уровень брони варьируется от 0 до 50.
 *  - Урон тоже выбирается случайно — от 15 до 30 единиц.
 *  Игрок конструирует своего персонажа самостоятельно. Задаёт все его параметры, включая имя. Все
 *  персонажи появляются в случайных местах карты.
 *  Игрок ходит с помощью команд: L, R, U, D (по первым буквам слов left, right, up, down). В
 *  зависимости от команды выбирается направление перемещения: влево, вправо, вверх, вниз.
 *  Противники перемещаются в случайном направлении.
 *  Если игрок перемещается в сторону, где уже кто-то находится, он наносит этому персонажу урон.
 *  Противники при этом никогда не бьют друг друга: они просто пропускают ход и остаются на своём
 *  месте. За пределы карты (20 на 20 клеток) ходить нельзя никому. Если кто-то выбрал направление
 *  за границами, ход пропускается.
 *  Формула расчёта урона совпадает с той, что была в материале. Жизни уменьшаются на размер урона.
 *  При этом броня тоже сокращается на приведённый урон.
 *  Игра заканчивается тогда, когда умирают либо все противники, либо игрок. В первом случае на
 *  экран выводится сообщение о победе, во втором — о поражении.
 *  Если в начале хода игрок вводит команду save или load вместо направления перемещения, то игра
 *  либо сохраняет своё состояние в файл, либо загружает это состояние из файла.
 *  
 *  Советы и рекомендации:
 *  - Для определения команды персонажа можно внутри структуры данных о нём завести флаг.
 *  - Для отображения координат персонажей можно использовать структуру вектора из другой задачи, но
 *    заменить типы координат.
 *  - Для сохранения параметров игры и их загрузки можно работать с текстовыми данными. Однако
 *    записать всё в двоичном формате проще, главное — соблюдать последовательность полей:
 *        std::ofstream file("save.bin", std::ios::binary);
 *        for (int i = 0; i < 6; ++i) {
 *            file.write((char*)&(characters[i].position),
 *                       sizeof(characters[i].position));
 *    ...
 *  - При загрузке используйте ifstream и ту же последовательность полей.
 *  Задание необязательно сдавать на проверку. Но если хотите это сделать, куратор будет учитывать
 *  следующее:
 *  - Корректно работает сохранение и загрузка в игре.
 *  - После загрузки все атрибуты игрока, включая имя, восстанавливаются из файла.
 *  - После загрузки количество противников на поле соответствует количеству противников при
 *    сохранении.
 *  - Все игроки после загрузки появляются в местах, где они находились при сохранении.
 *  - При ходе игрока не появляются новые противники.
 *  - Перед загрузкой файла сохранения проверяется, есть ли он в операционной системе. */

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include "Module_21.hpp"

#define SIZE 20

// состояния игры
enum Game_state {
    all_players_alive, // игрок и хотя бы один враг живы
    player_died,       // живой игрок не имеет hp
    all_enemies_died   // все враги побеждены
};

// структура для вывода в help
struct FAQ_type {
    std::string operation;   // название операции
    std::string description; // описание операции
};

// FAQ
const static std::vector<FAQ_type> FAQ = {
    { "help", "вывод FAQ на экран" },
    { "L", "ход влево (left)" },
    { "R", "ход вправо (right)" },
    { "U", "ход вверх (up)" },
    { "D", "ход вниз (down)" },
    { "save", "сохранение текущей игры" },
    { "load", "загрузка сохраненной игры" },
    { "exit", "окончание задания" }
};

// тип игрока
enum class Player_type {
    P, // живой игрок
    E  // компьютер
};

// описание персонажа
struct Person {
    std::string name; // имя персонажа
    int HP;           // жизни
    int armor;        // броня
    int damage;       // урон
};

// координата игрока
struct Coordinate {
    int x; // координата X
    int y; // координата Y
};

// описание игрока
struct Player {
    Person person;         // описание игрока
    Coordinate coordinate; // координаты игрока
    Player_type type;      // тип игрока
};

// общее описание игры
struct Game {
    Player player;               // живой игрок
    std::vector<Player> enemies; // вектор с врагами
    char field [SIZE][SIZE] = { 0 }; // поле игры
};

// ввод данных о живом игроке
static void cin_player(Player& player) {
    std::cout << "Введите имя игрока: ";
    std::cin >> player.person.name;
    std::cout << "Введите жизни игрока: ";
    std::cin >> player.person.HP;
    std::cout << "Введите броню игрока: ";
    std::cin >> player.person.armor;
    std::cout << "Введите урон игрока: ";
    std::cin >> player.person.damage;
    player.type = Player_type::P;
}

// рандомайзер данных о врагах
static void random_enemies(std::vector<Player>& enemies) {
    enemies.clear();
    enemies.resize(5);
    for (unsigned int i = 0; i < enemies.size(); i++) {
        enemies[i].person.name = "Enemy #" + std::to_string(i);
        enemies[i].person.HP = std::rand() % 101 + 50;
        enemies[i].person.armor = std::rand() % 51;
        enemies[i].person.damage = std::rand() % 16 + 15;
        enemies[i].type = Player_type::E;
    }
}

// рандомайзер координат
static void random_coordinates(Coordinate& coord) {
    coord.x = rand() % SIZE;
    coord.y = rand() % SIZE;
}

// проверка наличия одинаковых координат для исключения дубляжа
static bool check_coordinates(const Game& game) {
    for (unsigned int i = 0; i < game.enemies.size(); i++) {
        if (game.player.coordinate.x == game.enemies[i].coordinate.x &&
            game.player.coordinate.y == game.enemies[i].coordinate.y)
            return false;
        for (unsigned int j = i + 1; j < game.enemies.size(); j++)
            if (game.enemies[j].coordinate.x == game.enemies[i].coordinate.x &&
                game.enemies[j].coordinate.y == game.enemies[i].coordinate.y)
                return false;
    }
    return true;
}

// функция расположения игроков
static void fill_field(Game& game) {
    for (unsigned int i = 0; i < SIZE; i++) {
        for (unsigned int j = 0; j < SIZE; j++) {
            game.field[i][j] = '.';
        }
    }
    game.field[game.player.coordinate.y][game.player.coordinate.x] = 'P';
    for (const Player& enemy : game.enemies) {
        game.field[enemy.coordinate.y][enemy.coordinate.x] = 'E';
    }
}

// вывод на экран поля для игры
static void print_field(const char field[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << " " << field[i][j];
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// функция инициализации игры
static void init_game(Game& game) {
    cin_player(game.player);
    do {
        random_enemies(game.enemies);
        random_coordinates(game.player.coordinate);
        for (Player& enemy : game.enemies) {
            random_coordinates(enemy.coordinate);
        }
    } while (!check_coordinates(game));
    fill_field(game);
    print_field(game.field);
}

// функция атаки
static void attack(const Player& attacking, Player& attacked) {
    if (attacking.type == Player_type::P || attacking.type == Player_type::E) {
        attacked.person.armor -= attacking.person.damage;
        if (attacked.person.armor < 0) {
            attacked.person.HP += attacked.person.armor;
            attacked.person.armor = 0;
        }
    }
}

// функция выполнения хода врагами
static void enemies_turns(Game& game) {
    int x, y, r;
    bool change; // флаг для смены координат
    for (unsigned int i = 0; i < game.enemies.size(); i++) {
        change = true;
        r = rand() % 5 - 2;
        x = game.enemies[i].coordinate.x + (!r % 2 ? r / 2 : 0);
        y = game.enemies[i].coordinate.y + (r % 2 ? r : 0);
        
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
            if (game.player.coordinate.x == x && game.player.coordinate.y == y) {
                change = false;
                attack(game.enemies[i], game.player);
                break;
            }
            for (unsigned int j = 0; j < game.enemies.size(); j++) {
                if (j != i) {
                    if (game.enemies[j].coordinate.x == x && game.enemies[j].coordinate.y == y) {
                        change = false;
                        attack(game.enemies[i], game.enemies[j]);
                        break;
                    }
                }
            }
            
            if (change) {
                game.enemies[i].coordinate.x = x;
                game.enemies[i].coordinate.y = y;
            }
        }
    }
}

// функция выполнения хода игроком
static void player_turn(Game& game, std::string command) {
    int x = game.player.coordinate.x;
    int y = game.player.coordinate.y;

    if (command == FAQ[1].operation) {
        x--;
    } else if (command == FAQ[2].operation) {
        x++;
    } else if (command == FAQ[3].operation) {
        y--;
    } else if (command == FAQ[4].operation) {
        y++;
    }

    // если игрок не вышел за пределы поля
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
        bool change = true;
        for (unsigned int i = 0; i < game.enemies.size(); i++) {
            if (game.enemies[i].coordinate.x == x && game.enemies[i].coordinate.y == y) {
                change = false;
                attack(game.player, game.enemies[i]);
                break;
            }
        }
        if (change) {
            game.player.coordinate.x = x;
            game.player.coordinate.y = y;
        }
    }
}

/* функция проверки окончания игры (eog - end of game)
 * возвращает true - если живой игрок имеет HP больше нуля */
static Game_state check_eog(Game& game) {
    if (game.player.person.HP <= 0)
        return Game_state::player_died;
    else {
        for (const Player& enemy : game.enemies) {
            if (enemy.person.HP > 0) {
                return Game_state::all_players_alive;
            }
        }
        return Game_state::all_enemies_died;
    }
}

// сохранение игры
static bool save_game(const Game& game) {
    std::ofstream file;

    file.open(CUR_DIR + DOCS_DIR + "save.bin", std::ios_base::binary);
    if (file.is_open()) {
        unsigned int len = game.player.person.name.length();
        // запись имени игрока: сначала размер, затем c-строка
        file.write((char*)&len, sizeof(len));
        file.write(game.player.person.name.c_str(), len);

        // запись характеристик: жизнь, броня, урон
        file.write((char*)&game.player.person.HP, sizeof(game.player.person.HP));
        file.write((char*)&game.player.person.armor, sizeof(game.player.person.armor));
        file.write((char*)&game.player.person.damage, sizeof(game.player.person.damage));

        // запись координат игрока
        file.write((char*)&game.player.coordinate.x, sizeof(game.player.coordinate.x));
        file.write((char*)&game.player.coordinate.y, sizeof(game.player.coordinate.y));

        // запись количества врагов
        len = game.enemies.size();
        file.write((char*)&len, sizeof(len));

        // запись характеристик врагов
        for (unsigned int i = 0; i < game.enemies.size(); i++) {
            // запись имени врага: сначала размер, затем c-строка
            len = game.enemies[i].person.name.length();
            file.write((char*)&len, sizeof(len));
            file.write(game.enemies[i].person.name.c_str(), len);
            
            // запись характеристик врага: жизнь, броня, урон
            file.write((char*)&game.enemies[i].person.HP, sizeof(game.enemies[i].person.HP));
            file.write((char*)&game.enemies[i].person.armor, sizeof(game.enemies[i].person.armor));
            file.write((char*)&game.enemies[i].person.damage, sizeof(game.enemies[i].person.damage));
            
            // запись координат врага
            file.write((char*)&game.enemies[i].coordinate.x, sizeof(game.enemies[i].coordinate.x));
            file.write((char*)&game.enemies[i].coordinate.y, sizeof(game.enemies[i].coordinate.y));
        }
        file.close();

        return true;
    } else {
        std::cout << "File is not open!\n";
        return false;
    }
}

// загрузка игры
static bool load_game(Game& game) {
    std::ifstream file;

    file.open(CUR_DIR + DOCS_DIR + "save.bin", std::ios_base::binary);
    if (file.is_open()) {
        // запись имени игрока: сначала размер, затем c-строка
        unsigned int len;
        file.read((char*)&len, sizeof(len));
        file.read((char*)game.player.person.name.c_str(), len);

        // запись характеристик: жизнь, броня, урон
        file.read((char*)&game.player.person.HP, sizeof(game.player.person.HP));
        file.read((char*)&game.player.person.armor, sizeof(game.player.person.armor));
        file.read((char*)&game.player.person.damage, sizeof(game.player.person.damage));

        // запись координат игрока
        file.read((char*)&game.player.coordinate.x, sizeof(game.player.coordinate.x));
        file.read((char*)&game.player.coordinate.y, sizeof(game.player.coordinate.y));

        // запись количества врагов
        file.read((char*)&len, sizeof(len));
        game.enemies.resize(len);

        // запись характеристик врагов
        for (unsigned int i = 0; i < game.enemies.size(); i++) {
            // запись имени врага: сначала размер, затем c-строка
            file.read((char*)&len, sizeof(len));
            file.read((char*)game.enemies[i].person.name.c_str(), len);
            
            // запись характеристик врага: жизнь, броня, урон
            file.read((char*)&game.enemies[i].person.HP, sizeof(game.enemies[i].person.HP));
            file.read((char*)&game.enemies[i].person.armor, sizeof(game.enemies[i].person.armor));
            file.read((char*)&game.enemies[i].person.damage, sizeof(game.enemies[i].person.damage));
            
            // запись координат врага
            file.read((char*)&game.enemies[i].coordinate.x, sizeof(game.enemies[i].coordinate.x));
            file.read((char*)&game.enemies[i].coordinate.y, sizeof(game.enemies[i].coordinate.y));
        }
        file.close();

        return true;
    } else {
        std::cout << "File is not open!\n";
        return false;
    }
}

// функция основной игры
static void play_game(Game& game) {
    std::string command;
    Game_state game_state= Game_state::all_players_alive;
    while (true) {
        std::cout << "Введите команду (help - помощь): ";
        std::cin >> command;
        if (command == FAQ[0].operation) {
            std::cout << "Возможные операции:\n";
            for (const FAQ_type& f : FAQ) {
                std::cout << "\t" << f.operation << " - " << f.description << "\n";
            }
        } else if (command == FAQ[1].operation || command == FAQ[2].operation ||
                   command == FAQ[3].operation || command == FAQ[4].operation) {
            player_turn(game, command);
            enemies_turns(game);
            fill_field(game);
            print_field(game.field);

            // проверяем состояние игры
            game_state = check_eog(game);
            if (game_state == Game_state::player_died) {
                std::cout << "Игрок погиб! Вы проиграли!\n";
                break;
            } else if (game_state == Game_state::all_enemies_died) {
                std::cout << "Все враги побеждены! Поздравляю!\n";
                break;
            }
        } else if (command == FAQ[5].operation) {
            if (save_game(game))
                std::cout << "Данные сохранены!\n";
            else
                std::cout << "Данные не сохранены! Проверьте доступ к файловой системе\n";
        } else if (command == FAQ[6].operation) {
            if (load_game(game)) {
                std::cout << "Данные загружены!\n";
                fill_field(game);
                print_field(game.field);
            }
            else
                std::cout << "Файл сохранения не найден или нет доступа к файловой системе!\n";
        } else if (command == FAQ[7].operation) {
            std::cout << "Выполнение задания окончено!\n";
            break;
        } else {
            std::cout << "Неизвестная команда!\n";
        }
    }
}

void Task_21_4() {
    std::srand(std::time(nullptr));
    std::cout << equals << string_tasks[3] << equals;

    Game game;
    init_game(game);
    play_game(game);
}
#endif

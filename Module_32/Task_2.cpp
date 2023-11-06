// #ifdef __MODULE_32__
/* Задача 2. Анализ данных о фильмах
 *  Что нужно сделать:
 *  Используя модель данных из задачи №1, создайте JSON-документ, но теперь уже для пяти различных
 *  кинолент. Ключи в этой JSON-базе данных должны быть названиями фильмов, а значениями служить уже
 *  словари с информацией о картинах.
 *  
 *  Загрузите базу данных в C++-программу для последующего анализа. Предусмотрите следующий
 *  функционал: поиск актёра по имени (или фамилии) и вывод в консоль названий кинолент, в которых
 *  снимался актёр, и роль, которую он исполнял.
 *  
 *  Что оценивается:
 *  Валидность созданного JSON-документа с базой данных о фильмах. Корректность работы программы
 *  поиска актёра. */

#include <iostream>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>
#include "Module_32.hpp"
#include "Task_2.hpp"

static nlohmann::json make_json(const Movie& movie) {
    nlohmann::json result;
    nlohmann::json actors;

    result["country"] = movie.country;
    result["date"] = movie.date;
    result["distributed_by"] = movie.distributed_by;
    result["screenplay_by"] = movie.screenplay_by;
    result["directed_by"] = movie.directed_by;
    result["produced_by"] = movie.produced_by;
    for (const Actor& actor : movie.actors) {
        actors[actor.role] = actor.name;
    }
    result["actors"] = actors;

    return result;
}

static void cin_string(const std::string& comment, std::string& result) {
    std::cout << comment;
    std::getline(std::cin, result);
}

static void cin_movie(Movie& movie, std::string& name) {
    Actor actor;

    std::cout << "\tEnter the next data about your film:\n";
    cin_string("1) Name: ", name);
    cin_string("2) Country: ", movie.country);
    cin_string("3) Date of creation: ", movie.date);
    cin_string("4) Distributed by: ", movie.distributed_by);
    cin_string("5) Screenplay by: ", movie.screenplay_by);
    cin_string("6) Directed by: ", movie.directed_by);
    cin_string("7) Produced by: ", movie.produced_by);

    std::cout << "8) Actors (\"exit\" to finish):\n";
    while (true) {
        cin_string("  - Role: ", actor.role);
        if (actor.role == "exit") {
            break;
        }
        cin_string("  - Actor: ", actor.name);
        if (actor.name == "exit") {
            break;
        }
        movie.actors.push_back(actor);
    }
}

static void make_movies_file() {
    nlohmann::json movies;
    nlohmann::json single;
    Movie movie;
    std::string movieName;

    // // очистка буфера ввода
    // std::cin.clear();
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // для использования сначала очистить буфер ввода
    // cin_movie(movie, movieName);

    single = make_json(movie1);
    movies[movieName1] = single;
    single = make_json(movie2);
    movies[movieName2] = single;
    single = make_json(movie3);
    movies[movieName3] = single;
    single = make_json(movie4);
    movies[movieName4] = single;
    single = make_json(movie5);
    movies[movieName5] = single;

    std::ofstream record ("movies.json");
    if (record.is_open()) {
        record << movies;
        record.close();
    } else {
        std::cout << "Some troubles with json file...\n";
    }
}

static void find_movies_by_actor(const nlohmann::json& movies, std::string actor) {
    for (auto movie = movies.begin(); movie != movies.end(); movie++) {
        for (auto role = (*movie)["actors"].begin(); role != (*movie)["actors"].end(); role++) {
            std::string tmp = role.value();
            if (actor == tmp) {
                std::cout << "In movie " << movie.key() << " actor " << actor << " played ";
                std::cout << role.key() << "\n";
            }
        }
    }
}

void Task_32_2() {
    std::cout << equals << string_tasks[1] << equals;

    nlohmann::json movies;
    make_movies_file();
    std::ifstream file("movies.json");
    if (file.is_open()) {
        file >> movies;
        file.close();

        // очистка буфера ввода
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::string actor;
        std::cout << "Enter actor: ";
        std::getline(std::cin, actor);
        find_movies_by_actor(movies, actor);
    } else {
        std::cout << "Some troubles with json file...\n";
    }
}
// #endif

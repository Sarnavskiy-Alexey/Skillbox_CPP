#ifdef __MODULE_32__
/* Задача 1. Информация о фильме с кинопортала
 *  Что нужно сделать:
 *  Запишите подробную информацию о киноленте в виде JSON-файла. Выберите понравившуюся вам картину
 *  на любимом портале, проанализируйте информацию о ней и составьте JSON-словарь.
 *  
 *  В информации должны присутствовать: страна и дата создания киноленты, студия, которая вела
 *  съёмки, автор сценария, режиссёр и продюсер киноленты. Обязательно добавьте информацию обо всех
 *  главных действующих лицах и тех актёрах, которые их сыграли.
 *  
 *  Что оценивается:
 *  Валидность созданного JSON-документа. */

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "Module_32.hpp"

void Task_32_1() {
    std::cout << equals << string_tasks[0] << equals;

    nlohmann::json movie;
    nlohmann::json actors;
    movie["name"] = "Harry Potter and the Philosopher's Stone";
    // movie["country"] = "[ \"USA\", \"United Kingdom\" ]"_json;
    movie["country"] = "United Kingdom";
    movie["date"] = "2001-11-04T00:00:00Z";
    movie["distributed_by"] = "Warner Bros. Pictures";
    movie["screenplay_by"] = "Steve Kloves";
    movie["directed_by"] = "Chris Columbus";
    movie["produced_by"] = "David Heyman";
    {
        actors["Harry Potter"] = "Daniel Radcliffe";
        actors["Ron Weasley"] = "Rupert Grint";
        actors["Hermione Granger"] = "Emma Watson";
        actors["Nearly Headless Nick"] = "John Cleese";
        actors["Rubeus Hagrid"] = "Robbie Coltrane";
        actors["Filius Flitwick"] = "Warwick Davis";
        actors["Vernon Dursley"] = "Richard Griffiths";
        actors["Albus Dumbledore"] = "Richard Harris";
        actors["Quirinus Quirrell"] = "Ian Hart";
        actors["Mr. Ollivander"] = "John Hurt";
        actors["Severus Snape"] = "Alan Rickman";
        actors["Petunia Dursley"] = "Fiona Shaw";
        actors["Minerva McGonagall"] = "Maggie Smith";
        actors["Molly Weasley"] = "Julie Walters";
    }
    movie["actors"] = actors;
    std::ofstream file("movie.json");
    if (file.is_open()) {
        file << movie;
        file.close();
    } else {
        std::cout << "Some troubles with json file...\n";
    }

    std::cout << "Watch the file \"movie.json\" =)\n";
}
#endif

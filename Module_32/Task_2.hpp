// #ifdef __MODULE_32__

#pragma once
#include <string>
#include <vector>

struct Actor {
    std::string role;
    std::string name;
};

struct Movie {
    std::string country;
    std::string date;
    std::string distributed_by;
    std::string screenplay_by;
    std::string directed_by;
    std::string produced_by;
    std::vector<Actor> actors;
};

const std::string movieName1 = "Harry Potter and the Philosopher's Stone";
const Movie movie1 = {
    .country = "United Kingdom",
    .date = "2001-11-04T00:00:00Z",
    .distributed_by = "Warner Bros. Pictures",
    .screenplay_by = "Steve Kloves",
    .directed_by = "Chris Columbus",
    .produced_by = "David Heyman",
    .actors = {
        { "Harry Potter", "Daniel Radcliffe" },
        { "Ron Weasley", "Rupert Grint" },
        { "Hermione Granger", "Emma Watson" },
        { "Nearly Headless Nick", "John Cleese" },
        { "Rubeus Hagrid", "Robbie Coltrane" },
        { "Filius Flitwick", "Warwick Davis" },
        { "Vernon Dursley", "Richard Griffiths" },
        { "Albus Dumbledore", "Richard Harris" },
        { "Quirinus Quirrell", "Ian Hart" },
        { "Mr. Ollivander", "John Hurt" },
        { "Severus Snape", "Alan Rickman" },
        { "Petunia Dursley", "Fiona Shaw" },
        { "Minerva McGonagall", "Maggie Smith" },
        { "Molly Weasley", "Julie Walters" }
    }
};

const std::string movieName2 = "Harry Potter and the Chamber of Secrets";
const Movie movie2 = {
    .country = "United Kingdom",
    .date = "2002-11-03T00:00:00Z",
    .distributed_by = "Warner Bros. Pictures",
    .screenplay_by = "Steve Kloves",
    .directed_by = "Chris Columbus",
    .produced_by = "David Heyman",
    .actors = {
        { "Harry Potter", "Daniel Radcliffe" },
        { "Ron Weasley", "Rupert Grint" },
        { "Hermione Granger", "Emma Watson" },
        { "Gilderoy Lockhart", "Kenneth Branagh" },
        { "Nearly Headless Nick", "John Cleese" },
        { "Rubeus Hagrid", "Robbie Coltrane" },
        { "Filius Flitwick", "Warwick Davis" },
        { "Vernon Dursley", "Richard Griffiths" },
        { "Albus Dumbledore", "Richard Harris" },
        { "Lucius Malfoy", "Jason Isaacs" },
        { "Minerva McGonagall", "Maggie Smith" },
        { "Madame Pomfrey", "Gemma Jones" },
        { "Severus Snape", "Alan Rickman" },
        { "Petunia Dursley", "Fiona Shaw" },
        { "Molly Weasley", "Julie Walters" }
    }
};

const std::string movieName3 = "Harry Potter and the Prisoner of Azkaban";
const Movie movie3 = {
    .country = "United Kingdom",
    .date = "2004-05-23T00:00:00Z",
    .distributed_by = "Warner Bros. Pictures",
    .screenplay_by = "Steve Kloves",
    .directed_by = "Alfonso Cuaron",
    .produced_by = "David Heyman",
    .actors = {
        { "Harry Potter", "Daniel Radcliffe" },
        { "Ron Weasley", "Rupert Grint" },
        { "Hermione Granger", "Emma Watson" },
        { "Rubeus Hagrid", "Robbie Coltrane" },
        { "Albus Dumbledore", "Michael Gambon" },
        { "Vernon Dursley", "Richard Griffiths" },
        { "Sirius Black", "Gary Oldman" },
        { "Severus Snape", "Alan Rickman" },
        { "Petunia Dursley", "Fiona Shaw" },
        { "Minerva McGonagall", "Maggie Smith" },
        { "Peter Pettigrew", "Timothy Spall" },
        { "Remus Lupin", "David Thewlis" },
        { "Sybill Trelawney", "Emma Thompson" },
        { "Molly Weasley", "Julie Walters" }
    }
};

const std::string movieName4 = "Harry Potter and the Goblet of Fire";
const Movie movie4 = {
    .country = "United Kingdom",
    .date = "2005-11-06T00:00:00Z",
    .distributed_by = "Warner Bros. Pictures",
    .screenplay_by = "Steve Kloves",
    .directed_by = "Mike Newell",
    .produced_by = "David Heyman",
    .actors = {
        { "Harry Potter", "Daniel Radcliffe" },
        { "Ron Weasley", "Rupert Grint" },
        { "Hermione Granger", "Emma Watson" },
        { "Rubeus Hagrid", "Robbie Coltrane" },
        { "Lord Voldemort", "Ralph Fiennes" },
        { "Albus Dumbledore", "Michael Gambon" },
        { "Alastor \"Mad-Eye\" Moody", "Brendan Gleeson" },
        { "Lucius Malfoy", "Jason Isaacs" },
        { "Sirius Black", "Gary Oldman" },
        { "Severus Snape", "Alan Rickman" },
        { "Minerva McGonagall", "Maggie Smith" },
        { "Peter Pettigrew / Wormtail", "Timothy Spall" }
    }
};

const std::string movieName5 = "Harry Potter and the Order of the Phoenix";
const Movie movie5 = {
    .country = "United Kingdom",
    .date = "2007-06-28T00:00:00Z",
    .distributed_by = "Warner Bros. Pictures",
    .screenplay_by = "Michael Goldenberg",
    .directed_by = "David Yates",
    .produced_by = "David Heyman",
    .actors = {
        { "Harry Potter", "Daniel Radcliffe" },
        { "Ron Weasley", "Rupert Grint" },
        { "Hermione Granger", "Emma Watson" },
        { "Bellatrix Lestrange", "Helena Bonham Carter" },
        { "Rubeus Hagrid", "Robbie Coltrane" },
        { "Lord Voldemort", "Ralph Fiennes" },
        { "Albus Dumbledore", "Michael Gambon" },
        { "Alastor \"Mad-Eye\" Moody", "Brendan Gleeson" },
        { "Vernon Dursley", "Richard Griffiths" },
        { "Lucius Malfoy", "Jason Isaacs" },
        { "Sirius Black", "Gary Oldman" },
        { "Severus Snape", "Alan Rickman" },
        { "Petunia Dursley", "Fiona Shaw" },
        { "Minerva McGonagall", "Maggie Smith" },
        { "Dolores Umbridge", "Imelda Staunton" },
        { "Remus Lupin", "David Thewlis" },
        { "Sybill Trelawney", "Emma Thompson" },
        { "Molly Weasley", "Julie Walters" }
    }
};

// #endif

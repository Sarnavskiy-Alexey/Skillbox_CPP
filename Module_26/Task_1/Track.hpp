// #ifdef __MODULE_26__
/* Объявление класса Track */
#pragma once
#include <string>
#include <ctime>

class Track {
private:
    std::string m_name;           // название трека
    std::tm m_creationDate;       // дата создания трека
    unsigned int m_duration_sec;  // длительность трека в секундах
    bool m_played_in_shuffle;     // статус "трек проигран"
public:
    // конструктор
    Track(std::string name, std::tm creationDate, unsigned int duration_sec);

    bool        get_status() const; // функция получения статуса "трек проигран"
    std::string get_name()   const; // функция получения названия трека
    
    // функция смены статуса
    void change_status();

    // запуск трека
    void play_track();
};

// #endif

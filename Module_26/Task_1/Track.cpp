#ifdef __MODULE_26__
/* Определение класса Track */
#include <iostream>
#include "Track.hpp"

Track::Track(const std::string name, const std::tm creationDate, const unsigned int duration_sec) {
    this->m_name = name;
    this->m_creationDate = creationDate;
    this->m_duration_sec = duration_sec;
    this->m_played_in_shuffle = false;
}

// функция получения статуса "трек проигран"
bool Track::get_status() const {
    return this->m_played_in_shuffle;
}

// функция смены статуса
void Track::change_status() {
    this->m_played_in_shuffle = !this->m_played_in_shuffle;
}

// функция получения названия трека
std::string Track::get_name() const {
    return this->m_name;
}

// запуск трека
void Track::play_track() {
    std::cout << "Название трека: " << this->m_name << "\n";
    std::cout << " Дата создания: " << std::asctime(&this->m_creationDate);
    std::cout << "  Длительность: " << this->m_duration_sec << " сек.\n";
}

#endif

// #ifdef __MODULE_26__
/* Объявление класса Player */
#pragma once
#include <vector>
#include <string>
#include "Track.hpp"

class MusicPlayer {
private:
    std::vector<Track> m_tracks; // все треки в плеере

    int m_indexPlaying; // индекс текущего играемого трека; [-1] - по умолчанию
    unsigned int m_wasPlayed; // количество сыгранных треков (без повторов) [0] - по умолчанию
    
    bool m_playing; // признак того, что в данный момент проигрывается трек
    bool m_stoped;  // признак того, что проигрываемый трек был остановлен
    bool m_paused;  // признак того, что проигрываемый трек был поставлен на паузу

    // функция поиска песни по названию
    int search_track(std::string trackName);
public:
    // конструктор
    MusicPlayer();

    // функции плеера, требуемые по условию
    void play();
    void pause();
    void next();
    void stop();
};

// #endif

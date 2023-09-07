#ifdef __MODULE_26__
/* Определение класса Player */
#include <iostream>
#include <limits>
#include "MusicPlayer.hpp"

MusicPlayer::MusicPlayer() {
    this->m_indexPlaying = -1;
    this->m_wasPlayed = 0;
    this->m_playing = false;
    this->m_stoped = false;
    this->m_paused = false;

    // хардкодно подаются значения в вектор
    std::time_t today = std::time(nullptr);
    std::time_t creation_date = today;
    creation_date = today + std::rand() % 10000001 - 5000000;
    this->m_tracks.push_back(Track("Alla Pugachyova - Million Alyh Roz",
                             *std::localtime(&creation_date),
                             353U)); /* 0 */
    
    creation_date = today + std::rand() % 10000001 - 5000000;
    this->m_tracks.push_back(Track("Nayk Borzov - Loshadka",
                             *std::localtime(&creation_date),
                             304U)); /* 1 */
    
    creation_date = today + std::rand() % 10000001 - 5000000;
    this->m_tracks.push_back(Track("Lyapis Trubetskoy - Shut",
                             *std::localtime(&creation_date),
                             204U)); /* 2 */
    
    creation_date = today + std::rand() % 10000001 - 5000000;
    this->m_tracks.push_back(Track("Yorsh - Lyubov I Pank-hardkor",
                             *std::localtime(&creation_date),
                             179U)); /* 3 */
    
    creation_date = today + std::rand() % 10000001 - 5000000;
    this->m_tracks.push_back(Track("Potomuchto - Zhizn I Smert",
                             *std::localtime(&creation_date),
                             253U)); /* 4 */
    
    creation_date = today + std::rand() % 10000001 - 5000000;
    this->m_tracks.push_back(Track("F.P.G. - Stremitsya",
                             *std::localtime(&creation_date),
                             201U)); /* 5 */
    
    creation_date = today + std::rand() % 10000001 - 5000000;
    this->m_tracks.push_back(Track("Powerwolf - Army Of The Night",
                             *std::localtime(&creation_date),
                             201U)); /* 6 */
    
    creation_date = today + std::rand() % 10000001 - 5000000;
    this->m_tracks.push_back(Track("blink-182 - All The Small Things",
                             *std::localtime(&creation_date),
                             171U)); /* 7 */

    std::cout << "Плеер включен!\n";
}

void MusicPlayer::play() {
    if (!this->m_playing) {
        int found = -1;
        std::string trackName;
        if (!this->m_paused) {
            do {
                // очистка буфера ввода
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Введите название трека: ";
                std::getline(std::cin, trackName);
                found = this->search_track(trackName);
                if (found == -1) {
                    std::cout << "Такого трека в плейлисте нет!\n";
                }
            } while (found == -1);
            if (!this->m_tracks[found].get_status()) {
                this->m_tracks[found].change_status();
            }
            this->m_indexPlaying = found;
            this->m_wasPlayed++;
        } else {
            std::cout << "Возобновление трека!\n";
        }
        this->m_playing = true;
        this->m_stoped = false;
        this->m_paused = false;
        
        this->m_tracks[this->m_indexPlaying].play_track();
    }
}

void MusicPlayer::pause() {
    if (!this->m_paused && !this->m_stoped) {
        std::cout << "Трек поставлен на паузу!\n";
        this->m_playing = false;
        this->m_stoped = false;
        this->m_paused = true;
    }
}

void MusicPlayer::next() {
    unsigned int amount_of_tracks = this->m_tracks.size();
    if (amount_of_tracks) {
        unsigned int indexPlaying = std::rand() % amount_of_tracks;
        if (this->m_wasPlayed < amount_of_tracks) {
            // ищем неигравший трек
            while(this->m_tracks[indexPlaying].get_status()) {
                indexPlaying = std::rand() % amount_of_tracks;
            }
            this->m_tracks[indexPlaying].change_status();
        } else { // обнуляем статусы
            this->m_wasPlayed = 0;
            for (Track& track : this->m_tracks) {
                track.change_status();
            }
            this->m_tracks[indexPlaying].change_status();
        }
        if (this->m_playing) {
            this->m_tracks[indexPlaying].play_track();
        }
        this->m_wasPlayed++;
        this->m_indexPlaying = indexPlaying;
    } else {
        std::cout << "В плеере нет треков!\n";
    }
}

void MusicPlayer::stop() {
    if (!this->m_stoped) {
        std::cout << "Трек остановлен!\n";
        this->m_playing = false;
        this->m_stoped = true;
        this->m_paused = false;

        // при остановке - обнуляем статусы "трек проигран"
        for (Track& track : this->m_tracks) {
            if (track.get_status()) {
                track.change_status();
            }
        }

        // индекс текущего трека и количество проигранных треков ставим по умолчанию
        this->m_indexPlaying = -1;
        this->m_wasPlayed = 0;
    }
}

// функция поиска песни по названию
int MusicPlayer::search_track(std::string trackName) {
    for (unsigned int i = 0; i < this->m_tracks.size(); i++) {
        if (this->m_tracks[i].get_name() == trackName) {
            return i;
        }
    }
    
    // если не нашли трек, то возвращаем -1
    return -1;
}

#endif

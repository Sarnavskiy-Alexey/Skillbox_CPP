#ifdef __MODULE_19__
/* Задание 1. Разработка программы поиска слов в файле
 *  Что нужно сделать
 *  Составьте небольшой текстовый файл «words.txt», в котором последовательно, через пробелы и
 *  переносы строк расположены различные слова. Можете использовать любые англоязычные слова.
 *  Разработайте программу, которая искала бы среди этих слов нужное пользователю и выводила бы
 *  общее количество повторений этого слова. 0 — если слово вообще не присутствует в файле. */

#include <iostream>
#include <string>
#include <fstream>
#include "Module_19.hpp"

// функция для удаления лишних символов вокруг слова
static std::string correct_word(std::string old_word) {
    std::string corrected_word;
    unsigned int beg = 0;
    unsigned int end = old_word.length();

    // перемещение индекса начального правильного символа
    while (beg < old_word.length() && !((old_word[beg] >= 'a' && old_word[beg] <= 'z') ||
                                        (old_word[beg] >= 'A' && old_word[beg] <= 'Z')))
        beg++;
    
    // перемещение индекса конечного правильного символа
    while (end > 0 && !((old_word[end - 1] >= 'a' && old_word[end - 1] <= 'z') ||
                         (old_word[end - 1] >= 'A' && old_word[end - 1] <= 'Z')))
        end--;

    for (unsigned int i = beg; i < end; i++)
        corrected_word.push_back(old_word[i]);
    return corrected_word;
}

// функция поиска слова в файле
static int find_word(const std::string& word) {
    int copies = 0;
    std::string fileWord;
    std::ifstream file;
    file.open(CUR_DIR + DOCS_DIR + "words.txt", std::ios_base::in);

    if (file.is_open()) {
        while (!file.eof()) {
            file >> fileWord;
            fileWord = correct_word(fileWord);
            if (fileWord == word)
                copies++;
        }
        file.close();
    } else
        std::cout << "File " << CUR_DIR + DOCS_DIR + "words.txt" << " is not open!\n";

    return copies;
}

void Task_19_1() {
    std::cout << equals << string_tasks[0] << equals;

    std::string word;
    std::cout << "Введите слово для поиска в файле: ";
    std::cin >> word;

    int result = find_word(word);
    std::cout << "Количество повторений слова \"" << word << "\" в файле: " << result << "\n";
}
#endif

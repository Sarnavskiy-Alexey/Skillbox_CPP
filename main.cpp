#include "main.hpp"

int main() {
    setlocale(LC_ALL, "Russian");

    unsigned short userAnswer;

    do {
        std::cout << "\tВведите номер модуля для проверки ДЗ (0 - выход): ";
        std::cin >> userAnswer;
        std::cout << equals;
        switch(userAnswer) {
            case 0: std::cout << "До свидания!\n"; break;
            #ifdef __MODULE_02__
            case 2: Module_02(); break;
            #endif
            #ifdef __MODULE_03__
            case 3: Module_03(); break;
            #endif
            #ifdef __MODULE_04__
            case 4: Module_04(); break;
            #endif
            #ifdef __MODULE_05__
            case 5: Module_05(); break;
            #endif
            #ifdef __MODULE_06__
            case 6: Module_06(); break;
            #endif
            #ifdef __MODULE_07__
            case 7: Module_07(); break;
            #endif
            #ifdef __MODULE_08__
            case 8: Module_08(); break;
            #endif
            #ifdef __MODULE_09__
            case 9: Module_09(); break;
            #endif
            #ifdef __MODULE_10__
            case 10: Module_10(); break;
            #endif
            #ifdef __MODULE_11__
            case 11: Module_11(); break;
            #endif
            #ifdef __MODULE_12__
            case 12: Module_12(); break;
            #endif
            #ifdef __MODULE_13__
            case 13: Module_13(); break;
            #endif
            #ifdef __MODULE_14__
            case 14: Module_14(); break;
            #endif
            #ifdef __MODULE_15__
            case 15: Module_15(); break;
            #endif
            #ifdef __MODULE_16__
            case 16: Module_16(); break;
            #endif
            #ifdef __MODULE_17__
            case 17: Module_17(); break;
            #endif
            default: {
                std::cout << "ДЗ по модулю отсутствует либо выставлены неправильные флаги компиляции"
                          << ".\nВыберите другой модуль либо пересоберите проект!\n";
            }
        }
    } while (userAnswer != 0);
      
    return 0;
}

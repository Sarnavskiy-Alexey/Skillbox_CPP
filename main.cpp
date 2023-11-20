#include "main.hpp"

int main(int argc, char **argv) {
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
            #ifdef __MODULE_18__
            case 18: Module_18(); break;
            #endif
            #ifdef __MODULE_19__
            case 19: Module_19(); break;
            #endif
            #ifdef __MODULE_20__
            case 20: Module_20(); break;
            #endif
            #ifdef __MODULE_21__
            case 21: Module_21(); break;
            #endif
            #ifdef __MODULE_22__
            case 22: Module_22(); break;
            #endif
            #ifdef __MODULE_23__
            case 23: Module_23(); break;
            #endif
            #ifdef __MODULE_24__
            case 24: Module_24(); break;
            #endif
            #ifdef __MODULE_26__
            case 26: Module_26(); break;
            #endif
            #ifdef __MODULE_27__
            case 27: Module_27(); break;
            #endif
            #ifdef __MODULE_28__
            case 28: Module_28(); break;
            #endif
            #ifdef __MODULE_29__
            case 29: Module_29(); break;
            #endif
            #ifdef __MODULE_31__
            case 31: Module_31(); break;
            #endif
            #ifdef __MODULE_32__
            case 32: Module_32(); break;
            #endif
            #ifdef __MODULE_33__
            case 33: Module_33(); break;
            #endif
            #ifdef __MODULE_35__
            case 35: Module_35(); break;
            #endif
            #ifdef __MODULE_36__
            case 36: Module_36(argc, argv); break;
            #endif
            default: {
                std::cout << "ДЗ по модулю отсутствует либо выставлены неправильные флаги компиляции"
                          << ".\nВыберите другой модуль либо пересоберите проект!\n";
            }
        }
    } while (userAnswer != 0);
     
    return 0;
}

/*
// Раскомментировать для модуля №34:
#include <iostream>
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
    // QApplication a(argc, argv);
    // QPushButton button("Hello, world!", nullptr);
    // button.resize(200, 100);
    // button.show();
    // return QApplication::exec();
}

// какой-то важный файл, о котором не сказали на лекциях
#include <main.moc>

*/
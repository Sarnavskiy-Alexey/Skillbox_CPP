#include <iostream>

extern const std::string equals = "=======================================================\n\n";   

/* ********************************************************************************************* */
#ifdef __MODULE_02__
extern void Module_02();
#endif
#ifdef __MODULE_03__
extern void Module_03();
#endif
#ifdef __MODULE_04__
extern void Module_04();
#endif
#ifdef __MODULE_05__
extern void Module_05();
#endif
#ifdef __MODULE_06__
extern void Module_06();
#endif
#ifdef __MODULE_07__
extern void Module_07();
#endif
#ifdef __MODULE_08__
extern void Module_08();
#endif
#ifdef __MODULE_09__
extern void Module_09();
#endif
#ifdef __MODULE_10__
extern void Module_10();
#endif
#ifdef __MODULE_11__
extern void Module_11();
#endif
#ifdef __MODULE_12__
extern void Module_12();
#endif
#ifdef __MODULE_13__
extern void Module_13();
#endif
#ifdef __MODULE_14__
extern void Module_14();
#endif
#ifdef __MODULE_15__
extern void Module_15();
#endif
#ifdef __MODULE_16__
extern void Module_16();
#endif
#ifdef __MODULE_17__
extern void Module_17();
#endif

/* ********************************************************************************************* */

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
            case 16: Module_17(); break;
            #endif
            default: {
                std::cout << "ДЗ по модулю отсутствует либо выставлены неправильные флаги компиляции"
                          << ".\nВыберите другой модуль либо пересоберите проект!\n";
            }
        }
    } while (userAnswer != 0);
      
    return 0;
}

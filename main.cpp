#include <iostream>

extern const std::string equals = "=======================================================\n\n";   

/* ********************************************************************************************* */
extern void Module_02();
extern void Module_03();
extern void Module_04();
extern void Module_05();
extern void Module_06();
extern void Module_07();
extern void Module_08();
extern void Module_09();
extern void Module_10();
extern void Module_11();
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
            case 2: Module_02(); break;
            case 3: Module_03(); break;
            case 4: Module_04(); break;
            case 5: Module_05(); break;
            case 6: Module_06(); break;
            case 7: Module_07(); break;
            case 8: Module_08(); break;
            case 9: Module_09(); break;
            case 10: Module_10(); break;
            case 11: Module_11(); break;
            default: {
                std::cout << "ДЗ по модулю отсутствует или не выполнено. Выберите другой модуль!\n";
            }
        }
    } while (userAnswer != 0);
      
    return 0;
}

// Задача 26
// Напишете функция за шифриране на стринг с използването на Шифъра на Цезар:
// https://en.wikipedia.org/wiki/Caesar_cipher
// Пример 1:
// Вход: ABcd 1
// Изход: ZAbc
// Пример 2:
// Вход: The 3
// Изход: Qeb
#include <string>

void encodeCesaerCipher (std::string &s, int step){
    int firstCharBeforeUpperAlphabet {64};
    int firstCharBeforeLowerAlphabet {96};
    int charUpperZ{90};
    int charLowerZ{122};
    for (int i = 0; i < s.size(); i++)
    {
        if(std::isalpha(s[i])){
        if(std::isupper(s[i])){ 
            s[i] -= step; 
            if(s[i]<= firstCharBeforeUpperAlphabet){
                s[i] = charUpperZ - (firstCharBeforeUpperAlphabet -s[i]);
            }
        }else{
            s[i] -= step; 
            if(s[i]<= firstCharBeforeLowerAlphabet){
                s[i] = charLowerZ - (firstCharBeforeLowerAlphabet -s[i]);
            }
        }
        }
    }
    return;
}


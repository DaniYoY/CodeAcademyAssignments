// Задача 27
// Напишете функция за дешифриране на стринг с използването на Шифъра на Цезар, която прави обратното на предходната.

#include <string>

void decodeCesaerCipher (std::string &s, int step){
    int lastCharBeforeUpperAlphabet {91};
    int lastCharBeforeLowerAlphabet {123};
    int charUpperA{65};
    int charLowerA{97};
    for (int i = 0; i < s.size(); i++)
    {
        if(std::isalpha(s[i])){
        if(std::isupper(s[i])){ 
            s[i] += step; 
            if(s[i]<= lastCharBeforeUpperAlphabet){
                s[i] = charUpperA - (lastCharBeforeUpperAlphabet -s[i]);
            }
        }else{
            s[i] -= step; 
            if(s[i]<= lastCharBeforeLowerAlphabet){
                s[i] = charLowerA - (lastCharBeforeLowerAlphabet -s[i]);
            }
        }
        }
    }
    return;
}
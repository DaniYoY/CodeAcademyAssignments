// Задача 29
// Напишете функция за дешифриране на стринг с използването на Шифъра на Атбаш, която прави обратното на предходната.


#include <string>

void decodeAtbash(std::string & s){
    int sumOfFirstLastUpperChars{155};
    int sumOfFirstLastLowerChars{219};
    for (int i = 0; i < s.size(); i++)
    {
        if (std::isupper(s[i]))
        {
            s[i] = sumOfFirstLastUpperChars - s[i];
        }
        if (std::islower(s[i]))
        {
            s[i] = sumOfFirstLastLowerChars - s[i];
        } 
    }
    
    return;
}
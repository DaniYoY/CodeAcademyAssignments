// Задача 24
// Напишете функция която замества един символ с друг в стринг. Функцията трябва да приема двата символа и
// стринга като параметри

#include <string>

void replaceChar (char newChar, char oldChar, std::string & s){
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]== oldChar)
        {
            s[i] = newChar;
        }
    }
    return;
}
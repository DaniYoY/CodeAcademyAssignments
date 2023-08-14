// Задача 25
// Напишете функция която връща индекса на първия уникален символ в подаден стринг или размера на стринга ако
// такъв символ не е намерен.

#include <string>

int indexOfUniqueChar ( std::string & s){
    bool mappingOfRepeatedChars [s.size()];
    for (int i = 0; i < s.size(); i++)
    {
        if(mappingOfRepeatedChars[i]){
            continue;
        }

        for (int j = i+1; j <= s.size(); i++)
        {
            if(j == s.size()){
                break;
            }
            if(mappingOfRepeatedChars[j]){
                continue;
            }

            if(s[i] == s[j]){
                mappingOfRepeatedChars[i] = true;
                mappingOfRepeatedChars[j] = true;
            }
        }

        if(!mappingOfRepeatedChars[i]){
            return i;
        }
    }
    return s.size();
}
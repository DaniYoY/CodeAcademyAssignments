// Задача 22
// Напишете функция, която обръща подадения й като аргумент std::string наобратно

#include <string>

void reverse(std::string & s){
    std::string result{""};
    for (int i = 0; i < s.size(); i++)  
    {
        result += s[s.size() -1 -i];
    }
    s= result;
}
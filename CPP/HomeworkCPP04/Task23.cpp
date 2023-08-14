// Задача 23
// Напишете функция за преброяване на броя на срещанията да даден символ в стринг.

#include <string>

int countOccurances (char c,const std::string & s){
    int counter{0};
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]==c){
            counter++;
        }
    }
    return counter;
}
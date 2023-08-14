// Задача 07
// Напишете функция, която приема стринг и проверява дали всички отворени скоби са правилно затворени.

#include <string>
#include <vector>
#include <iostream>

bool isMatchingSet(char c1, char c2);

bool areBracketsClosed(std::string str){
    std::vector<char> interim;
    char curBracket = ' ';
    for (char c : str)
    {
        if (c == '{' || c == '[' || c== '(')
        {
            interim.push_back(c);
            curBracket = c;
        }
        if (c == '}' || c == ']' || c== ')'){
            if(isMatchingSet(curBracket,c)){
                interim.pop_back();
                curBracket = interim.back();
            }else{
                return false;
            }   
        }
    }
    
    if (interim.empty())
    {
    return true;
    }
    
    return false;
}

bool isMatchingSet(char c1, char c2){
    if ((c1 =='{' && c2 == '}')
    || (c1 =='[' && c2 == ']')
    || (c1 =='(' && c2 == ')')){
        return true;
    }
    return false;
}

int main (){
    std::string test{"(((()))){}}"};
    if (areBracketsClosed(test))
    {
        std::cout<< "Yes";
    }else{
        std::cout<< "No";
    }
    return 0;
}


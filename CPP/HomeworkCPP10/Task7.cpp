// Задача 07
// Дефинирайте две overloaded функции за преобразуване от стринг в цяло положително число и обратно.

#include <string>
#include <cmath>
unsigned long ston(std::string s){
    bool isOnlyDigits{true};
    unsigned long result{0};
    for (size_t i = 0; i < s.size(); i++)
    {
        if (!std::isdigit(s[i]))
        {
            isOnlyDigits = false;
        }
    }
    
    if (isOnlyDigits)
    {
        for (int i = s.size() - 1; i >= 0; i--)
        {
            result += std::pow(10,i)*s[i];
        }   
    }else{
        for (size_t i = 0; i < s.size(); i++)
        {
            result += s[i];
        } 
    }
    return result;
}

unsigned long ston(const std::string & s){
    bool isOnlyDigits{true};
    unsigned long result{0};
    for (size_t i = 0; i < s.size(); i++)
    {
        if (!std::isdigit(s[i]))
        {
            isOnlyDigits = false;
        }
    }
    
    if (isOnlyDigits)
    {
        for (int i = s.size() - 1; i >= 0; i--)
        {
            result += std::pow(10,i)*s[i];
        }   
    }else{
        for (size_t i = 0; i < s.size(); i++)
        {
            result += s[i];
        } 
    }
    return result;
}


std::string numToS(unsigned long num){
    std::string s{""};
    char c{' '};
    while (num>0)
    {
        c = num%10;
        s +=c;
        num /=10;
    }
    s.reserve(s.size());
    return s;
}

const std::string numToS(int num){
    std::string s{""};
    char c{' '};
    while (num>0)
    {
        c = num%10;
        s +=c;
        num /=10;
    }
    s.reserve(s.size());
    return s;
}
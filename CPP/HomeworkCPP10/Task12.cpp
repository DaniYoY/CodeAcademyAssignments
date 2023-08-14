// Задача 12
// Дефинирайте функция за премахване на елементи от std::array от стрингове по зададено от клиента предикатно
// условие за премахване на отделен елемент.
// Тествайте като премахнете всички елементи, които не са палиндроми, както и всички елементи, които не са
// съставени изцяло от буквени символи


#include<array>
#include<iostream>
#include<string>
using arrStr = std::array<std::string, 3>;
using func = bool(*)(const std::string&);

bool isPalindrome(const std::string & str){
    std::string::const_reverse_iterator rit = str.crbegin(); 
    for (std::string::const_iterator it = str.cbegin(); it != str.cend(); it++)
    {
        if (*it != *rit)
        {
            return false;
        }
        rit++;
    }
    return true;
}

bool isOnlyAlphas (const std::string & str){
    for (auto & s : str)
    {
        if (!std::isalpha(s))
        {
            return false;
        }
    }
    return true;
}
void removeElements(arrStr & elements, func f){
    for (std::string & s : elements)
    {  
        if (f(s))
        {
            s = "";
        }
    }
}


int main(int argc, char const *argv[])
{
    arrStr arr = {"adsda", "1234321", "asdfgh"};
    removeElements(arr, isPalindrome);
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i]<<' ';
    }
    return 0;
}

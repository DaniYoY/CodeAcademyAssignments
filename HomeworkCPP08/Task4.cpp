// Задача 04
// Напишете функция за проверяване на това дали един стринг е палиндром, използвайки итератори

#include <string>
#include <iostream>
 bool isPalindrome(const std::string & s){
    std::string::const_reverse_iterator rit = s.crbegin();
    for (std::string::const_iterator it = s.cbegin(); it != s.cend(); it++)
    {
        if (*rit != *it)
        {
            return false;
        }
        rit++;
    }
    return true;
 }

 int main(int argc, char const *argv[])
 {
    std::string s = "ad1dwa";
    std::cout<< isPalindrome(s)<<std::endl;
    return 0;
 }
 
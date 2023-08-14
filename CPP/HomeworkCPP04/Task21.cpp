// Задача 21
// Напишете функция, която проверява дали даден std::string е палиндром. Дефинирайте функцията с bool параметър,
// който указва дали да се игнорират символи, различни от букви.
#include <string>
bool isPalindromeOnlyAlphas (const std::string & s);
bool isPalindromeAllChars (const std::string & s);
bool isPalindrome(const std::string & s, bool checkOnlyAlpha){
    if(checkOnlyAlpha){
        return isPalindromeOnlyAlphas(s);
    }else{
        return isPalindromeAllChars(s);
    }
};

bool isPalindromeOnlyAlphas (const std::string & s)
{
         for (int i = 0, k = s.size()-1; i < s.size()/2;)
        {
            if(!std::isalpha(s[i])){
                i++;
                continue;
            }
            if(!std::isalpha(s[k])){
                k--;
                continue;
            }
            if(s[i] != s[k]){
                return false;
            }else{
                i++;
                k--;
            }
        }
        return true;
};
bool isPalindromeAllChars (const std::string & s)
{
    for (int i = 0; i < s.size()/2; i++)
    {
        if(s[i]!= s[s.size()-1 -i]){
            return false;
        }
    }
    return true;
}
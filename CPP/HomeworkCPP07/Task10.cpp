// Задача 10
// Напишете функция, която намира най-дългия подстринг в подаден стринг, който е палиндром.

#include <string>
#include <iostream>
#include <vector>
std::vector<std::string> getAllSubstrings(std::string & str);
bool isPalindrome(std::string & str);

std::string getLongestPalindromeSubstring(std::string text1){
    std::vector<std::string> substrings1, substrings2, matches;
    std::string result{""};
    int biggest{0};

    matches = getAllSubstrings(text1);
    for (int i = 0; i < matches.size(); i++)
    {
        if (matches[i].size() > biggest && isPalindrome(matches[i]))
        {
            biggest = matches[i].size();
            result = matches[i];
        }
    }
    return result;
}

std::vector<std::string> getAllSubstrings(std::string & str)
{
    std::vector<std::string> v;
    std::string interim{""};

    for (int endPnt = 1; endPnt <= str.length(); endPnt++)
    {   
        for (int startPnt = 0; startPnt <= str.size() - endPnt; startPnt++)
        { 
            int j = startPnt + (endPnt - 1);           
            for (int k = startPnt; k <= j; k++){
                interim += str[k];
            }
            v.push_back(interim);
            interim.clear();
        }
    }
    return v;
}

bool isPalindrome(std::string & str){
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != str[str.size()-1-i])
        {
            return false;
        }
    }
    return true;
}

int main(){
    std::cout<< getLongestPalindromeSubstring("48897aavaa") ;
    return 0;
}
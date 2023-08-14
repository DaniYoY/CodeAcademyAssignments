// Задача 09
// Напишете функция, която намира най-дългия общ под-стринг на два стринга, които приема като параметри

#include <string>
#include <iostream>
#include <vector>
std::vector<std::string> getAllSubstrings(std::string & str);
std::vector<std::string>  getMatchingStrings(std::vector<std::string> & substrings1,std::vector<std::string> & substrings2);

std::string getLongestMatch(std::string text1, std::string text2){
    std::vector<std::string> substrings1, substrings2, matches;
    std::string result{""};
    int biggest{0};

    substrings1 = getAllSubstrings(text1);
    substrings2 = getAllSubstrings(text2);
    matches = getMatchingStrings(substrings1, substrings2);
    for (int i = 0; i < matches.size(); i++)
    {
        if (matches[i].size() > biggest)
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

std::vector<std::string>  getMatchingStrings(std::vector<std::string> & substrings1,std::vector<std::string> & substrings2){
    std::vector<std::string> result;
    for (int i = 0; i <substrings1.size(); i++)
    {
        for (int j = 0; j < substrings2.size(); j++)
        {
            if (substrings1[i]== substrings2[j])
            {
                result.push_back(substrings1[i]);
            }   
        }
    }
    return result;
}

int main(){
    std::cout<< getLongestMatch("abv3456", "zxv345abpo");
    return 0;
}
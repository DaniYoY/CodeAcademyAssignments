// Задача 12
// Напишете програма, която принтира броя на срещанията на всяка дума от въведен от потребителя multiline
// string.
// За целта, използвайте поне две помощни функции - една за изчисляване на резултатите (преброяването на
// думите) и една за принтирането им.
// Вход:
// In C++, C++ coders code C++ code, causing curious C++ conundrums.
// Изход:
// In: 1
// C++: 4
// coders: 1
// code: 2
// causing: 1
// curious: 1
// conundrums: 1

#include <string>
#include<vector>
#include <map>
#include <iostream>

using vs = std::vector<std::string>;
using ms = std::map<std::string, int>;

vs getWords(std::string s){
    vs words;
    std::string word{""};
    for (long i = 0; i < s.size(); i++)
    {
        if(std::ispunct(s[i]) || std::isspace(s[i])){
            if(!word.empty()){
                words.push_back(word);
            }
            word.clear();
            continue;
        }
        word +=s[i];
        if(i == s.size()-1){
            words.push_back(word);
        }
    }
    return words;
}

ms calculateOccurances(vs & words){
   ms result;
   for (long i = 0; i < words.size(); i++)
   {
    result[words[i]]++;
   }
   return result; 
}

void printOccurances (std::string s){
    vs words;
    ms result;
    words = getWords(s);
    result = calculateOccurances(words);

    for (std::pair<const std::string, int> & pair : result)
    {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }
    
}

int main(){
    printOccurances("In C++, C++ coders \n \tcode C++ code, causing curious C++ conundrums");
    return 0;
}
// Задача 13
// Напишете програма, която принтира всички анаграми по категория, които са думи от въведен
// от потребителя multiline string.
// Вход:
// Teacher Hello Santa World Cheater Levi Code Satan Evil Vile
// Изход:
// 1. Teacher Cheater
// 2. Hello
// 3. Santa Satan
// 4. World
// 6. Levi Evil Vile
// 5. Code

#include <string>
#include<vector>
#include <map>
#include <iostream>

using vs = std::vector<std::string>;
using mivs = std::map<int, vs>;

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

bool isAnagram(std::string word1, std::string word2){
    if(word1.size() != word2.size()){
        return 0;
    }

    for (int i = 0; i < word1.size(); i++)
    {
        for (int j = 0; j < word2.size(); j++)
        {
            if (std::tolower(word1[i]) == std::tolower(word2[j]))
            {
                word2.erase(j,1);
            }
        }
    }
    if (word2.empty())
    {
        return true;
    }
    return false;
}
mivs groupAnagrams(vs & words){
    mivs result;
    std::vector<bool> mapCheck(words.size(), false);
    for (int i = 0; i < words.size(); i++)
    {
        if(mapCheck[i]){
            continue;
            } 
        for (int j = 0; j < words.size(); j++)
        {
            if(mapCheck[j]){
            continue;
            }       
            
            if(isAnagram(words[i], words[j])){
            result[i].push_back(words[j]);
            mapCheck[j]=true;
            } 
        }
        
    }
   return result; 
}
void printGroupedAnagrams(std::string s){
    vs words;
    mivs result;
    words = getWords(s);
    result = groupAnagrams(words);

     for (std::pair<const int, std::vector<std::string>> & pair : result)
    {
        std::cout << pair.first << ". : "; 
        for (int i = 0; i < pair.second.size(); i++)
        {
            std::cout<< pair.second[i]<<" ";
        }
        std::cout<< std::endl;
    }
}

int main(){
    printGroupedAnagrams("Teacher Hello Santa World Cheater Levi Code Satan Evil Vile");
    return 0;
}

// Задача 08
// Напишете функция, която проверява дали два стринга са анаграми един на друг
// (https://en.wikipedia.org/wiki/Anagram

#include <string>
#include <vector>
#include <iostream>

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

int main (){
    std::cout<< isAnagram("evil", "Vile");
    return 0;
}

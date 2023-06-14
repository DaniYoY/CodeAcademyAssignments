// Задача 10
// Напишете програма, която използва std::sort и std::unique за да принтира всички думи
// от текст, въведен от потребителя по веднъж (без повторения). Използвайте
// vector<string> за да съхраните думите от текста (в които първоначално има дублиращи
// се думи).

#include <algorithm>
#include <vector>
#include <iostream>
#include<string>
void print_list(std::vector<std::string> &v){
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << ' ';
    }
}

void enterText(std::vector<std::string> & v){
    std::string word{""};
    while (!std::cin.eof())
    {
        std::cin >> word;
        auto posToStartErasure = std::remove_if(word.begin(),word.end(), [](char a) { return std::ispunct(a);});
        word.erase(posToStartErasure,word.end());
        v.push_back(word);
    }
    
}

int main(int argc, char const *argv[])
{
    // std::vector<std::string> words{"pizza", "tomato", "chips", "chips", "tomato", "chips", "chips", "chips", "eggs", "pizza"};
    std::vector<std::string> words;

    enterText(words);

    std::sort(words.begin(),words.end());
    auto endOfUniques = std::unique(words.begin(), words.end());
    words.erase(endOfUniques, words.end());
    print_list(words);
    return 0;
}

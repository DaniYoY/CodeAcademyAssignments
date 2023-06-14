// Задача 11
// Напишете нова версия на предходната програма, която използва std::unique_copy за
// да запази финалния резултат в list<string>, който е празен в началото (unique_copy
// трябва да добавя елементи, не да променя съществуващи елементи).

#include <algorithm>
#include <vector>
#include <iostream>
#include<string>
#include<list>

void print_list(std::list<std::string> &v){
    for (auto it = v.begin(); it != v.end(); it++)
    {
        std::cout<< *it << ' ';
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
    std::list<std::string> result;
    std::sort(words.begin(),words.end());
    std::unique_copy(words.begin(),words.end(), std::back_inserter(result));
    
    print_list(result);
    return 0;
}

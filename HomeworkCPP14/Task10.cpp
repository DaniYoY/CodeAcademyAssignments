// Задача 10
// Напишете програма, която прочита дума, въведена от потребителя и принтира всички думи от речника, които могат да бъдат
// образувани, разменяйки местата на буквите от оригиналната дума. Използвайте файла (и евентуално функционалност) от
// предходната задача.
#include <string>
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
std::map<char,unsigned int> countChars(const std::string & source){
    std::map<char,unsigned int> result;
    for (char c : source)
    {
        result[c]++;
    }
    return result;
}
bool isProduced(const std::string & wordInQuestion,std::map<char,unsigned int> source){
    for (char c : wordInQuestion)
    {
        if(source[c] != 0){
            source[c]--;
        }else{
            return false;
        }
    }
    return true;
}
std::vector<std::string> produceListOfSubWords(const std::string & source){
    std::fstream dictionary;
    std::string dicWord{""};
    
    std::vector<std::string> results;
  
    dictionary.open("words.txt", std::ios::in);
    
    while (!std::getline(dictionary, dicWord).eof())
    {
        if (isProduced(dicWord, countChars(source)))
        {
            results.push_back(dicWord);
        }        
    }
    return results;
}

void printList(const std::vector<std::string> & vec){
    for (std::string word : vec)
    {
        std::cout<< word << std::endl;
    }
    
}
int main(int argc, char const *argv[])
{
    std::string word{""};
    std::cin >> word; 
    printList(produceListOfSubWords(word));
    return 0;
}
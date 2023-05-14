// Задача 08
// Напишете функция, която приема вектор от стрингове и принтира елемента (или елементите, ако са
// повече от един), който съдържа най-голямо разнообразие от символи (броя на елементите на
// множеството от различни символи, от които е съставен даден стринг елемент на контейнера)

#include <iostream>
#include <string>
#include <vector>
#include <map>

std::vector<int> determineDiversityOfChar(const std::vector<std::string> & s);
int calculateDiversChars(const std::string & s);

void printDiverseStrings(std::vector<std::string> & s){

    std::vector<int> diversityCharList;
    int maxDiverseCouner{0};
    diversityCharList = determineDiversityOfChar(s);
    
    for (int i = 0; i < s.size(); i++)
    {
        if(diversityCharList[i] > maxDiverseCouner){
            maxDiverseCouner = diversityCharList[i];
        }
    }

    for (int i =0; i < s.size(); i++){
        if(diversityCharList[i] == maxDiverseCouner){
            std::cout<< s[i]<< std::endl;
        }
    }
}

 std::vector<int> determineDiversityOfChar(const std::vector<std::string> & s){
    std::vector<int> diversityCharMapper;
    int diverseCharCounter{0};

    for (int i = 0; i < s.size(); i++)
    {
        diverseCharCounter=  calculateDiversChars(s[i]);
        diversityCharMapper.push_back(diverseCharCounter);
    }
    return diversityCharMapper;
 };

int calculateDiversChars(const std::string & s){
    std::map<char,int> charecters;
    for (int i = 0; i < s.size()-1; i++)
    {
        charecters[s[i]]++;
    }
    return charecters.size();    
}

int main(){
std::vector<std::string> srt {"aaaaaa", "abc", "ftg", "eee", "23"};
printDiverseStrings(srt);

}
// Задача 07
// Напишете функция, която приема текст и разбърква всички изречения в текста на произволен принцип.
// Допускайте текстове, съставени само от азбучни букви, whitespace и символи-точка ‘.’, които указват край на изречение.

#include<iostream>
#include<string>
#include <random>
#include <vector>

std::vector<std::string> shuffle(const std::vector<std::string> & s){
    std::vector<std::string> text{s};
    for (size_t i = 0; i < s.size(); i++)
    {
        std::swap(text[i], text[std::rand()%s.size()]);        
    }
    return text;
}

std::vector<std::string> separateInSentances(const std::string & s){
    std::vector<std::string> result;
    std::string interim{""};
    for (auto sentBegin = s.begin(), sentEnd = s.begin(); sentEnd != s.end(); sentEnd++)
    {
        interim += *sentEnd; 
        if (*sentEnd == '.' || sentEnd == s.end()-1)
        {
            result.push_back(interim);
            interim.clear();
            sentBegin = sentEnd+1;    
        } 
    }
    return result;
}

std::string mixSentances (const std::string & s){
    std::string result {""};
    std::vector<std::string> interim = shuffle(separateInSentances(s));
    for (auto it = interim.begin(); it != interim.end(); it++)
    {
        result += *it;
    }
    return result; 
}


int main(int argc, char const *argv[])
{
    std::cout<< mixSentances("As df. Bsdfd dfdg. Cre rtw. Dfwfw wer");
    return 0;
}
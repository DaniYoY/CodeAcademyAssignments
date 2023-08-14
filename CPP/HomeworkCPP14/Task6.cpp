// Задача 06
// Напишете функция, която приема текст и разбърква на произволен принцип всички думи в текста.
// Допускайте текстове, съставени само от азбучни букви и whitespace, без никакви други символи

#include<iostream>
#include<string>
#include <random>

std::string shuffle(const std::string & s){
    std::string str{s};
    for (size_t i = 0; i < s.length(); i++)
    {
        std::swap(str[i], str[std::rand()%s.length()]);        
    }
    return str;
}

int main(int argc, char const *argv[])
{
    std::cout<< shuffle("asdf");
    return 0;
}


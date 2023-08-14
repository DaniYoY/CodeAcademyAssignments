// Задача 09
// Напишете spell-checker, който приема като command line аргумент дума, за която проверява дали думата съществува в
// следния списък от думи: (програмата трябва да го прочита):
// https://github.com/dwyl/english-words/blob/master/words_alpha.txt
#include <string>
#include<iostream>
#include<fstream>

bool isSpelled(const std::string & word){
    std::fstream dictionary;
    std::string dicWord{""};
    dictionary.open("words.txt", std::ios::in);
    
    while (!std::getline(dictionary, dicWord).eof())
    {
        if (dicWord == word)
        {
            dictionary.close();
            return true;
        }        
    }
    dictionary.close();
    return false;
}

int main(int argc, char const *argv[])
{
    if(isSpelled(argv[1])){
        std::cout << "Word is found and correct";
    }else{
        std::cout << "Word is not found, hence it is incorrect";
    }
    return 0;
}

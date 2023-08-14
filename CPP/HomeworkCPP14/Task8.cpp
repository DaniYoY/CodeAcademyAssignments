// Задача 08
// Напишете програма, която приема като command-line аргументи цели числа, например:
// >>> myProgram.exe 1 2 -33 1 2 4 1 2 -33 -1 33 43
// и принтира хистограма, отразяваща броя срещания на всяко число от вида:
// 1: ***
// 2: ***
// -33: **
// 4: *
// -1: *
// 43: *
#include <iostream>
#include <map>
#include<string>
std::string createStars(int times){
    char star = '*';
    std::string resutl{""};
    for (size_t i = 0; i < times; i++)
    {
        resutl += star;
    }
    return resutl;
}
int main(int argc, char const *argv[])
{
    std::map<int,int> counter;   
    int interimKey{0};
    for (size_t i = 1; i < argc; i++)
    {
        interimKey = std::stoi(argv[i]);
        counter[interimKey]++;
    }
    
    for (auto i = counter.begin(); i != counter.end(); i++)

    {
        std::cout << (*i).first << ' ' << createStars((*i).second) << std::endl;
    }
    
    return 0;
}

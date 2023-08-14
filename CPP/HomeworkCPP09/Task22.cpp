// Задача 22
// Напишете програма, която моли потребителя да въведе текст на няколко реда до достигането на EOF. След това принтирайте целия текст, но обърнете реда на
// редовете (най-напред се принтира последния въведен ред, най-накрая - първият въведен ред)
// abc -> def
// def abc

#include<iostream>
#include<string>
#include<vector>

std::vector<std::string> getMultiLineInput(){
    std::vector<std::string> result; 
    std::string line{""};
    while (!(std::cin >>line).eof())
    {
        result.push_back(line);
    }
    return result;
}

void printInReverseOrder(std::vector<std::string> v){
    for (int i = v.size() - 1; i >= 0; i--, putchar('\n'))
    {
        for (int j = 0; j <v[i].size(); j++){
            std::cout << v[i][j];
        }
    }
    
}
int main(int argc, char const *argv[])
{
    printInReverseOrder(getMultiLineInput());
    return 0;
}
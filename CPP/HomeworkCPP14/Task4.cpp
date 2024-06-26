// Задача 04
// Напишете програма, която моли потребителя да въведе текст на няколко реда до достигането на EOF. След това принтирайте целия текст,
// но наобратно.
// abc -> fed
// def cba

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

void printReverseLines(std::vector<std::string> v){
    for (auto i = v.crbegin(); i != v.crend(); i++, putchar('\n'))
    {
        for (auto j = (*i).crbegin(); j != (*i).crend(); j++){
            std::cout << *j;
        }
    }
    
}
int main(int argc, char const *argv[])
{
    printReverseLines(getMultiLineInput());
    return 0;
}
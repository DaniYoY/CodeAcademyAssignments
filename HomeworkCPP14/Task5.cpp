// Задача 05
// Напишете програма, която моли потребителя да въведе текст на няколко реда до достигането на EOF. След това принтирайте целия текст,
// но обърнете реда на буквите на всеки ред
// abc -> cba
// def fed

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
    for (int i = 0; i<v.size(); i++, putchar('\n'))
    {
        for (int j = v[i].size() - 1; j >=0; j--){
            std::cout << v[i][j];
        }
    }
    
}
int main(int argc, char const *argv[])
{
    printReverseLines(getMultiLineInput());
    return 0;
}
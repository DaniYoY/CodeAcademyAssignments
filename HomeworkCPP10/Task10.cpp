// Задача 10
// Дефинирайте overload на функцията от предходната задача, която да използваме за писане в string елементите на
// vector. Дефинирайте функцията с trailing return type.
// Използвайте я за да обърнете наобратно всички низове във вектор и след това да ги промените всички главни
// букви на всеки стринг елемент в малки.

#include<iostream>
#include<string>
#include<vector>

// typedef void (*printingFun)(const std::string &);
typedef void (*printingFun)(std::string &);
void printStartToEnd(std::string & s){
    for (char i : s)
    {
        std::cout<<i;
    }
    std::cout<< std::endl;
}
void printReverseLoweing(std::string & s){
    for (std::string::reverse_iterator i = s.rbegin(); i !=s.rend(); i++)
    {    
        std::cout<< *i;
        *i = std::tolower(*i);
    }
    std::cout<< std::endl;
}

auto printString(std::string & s, printingFun order) -> void{
    order(s);
}

auto printString(std::vector<std::string> & vec, printingFun order) -> void{
    for (std::string & s : vec)
    {
        order(s);    
    }
}

int main(int argc, char const *argv[])
{
    std::string s1{"123456789"};
    std::string s2{"AbC"};
    std::string s3{"ZYx123456789"};
    std::vector<std::string> vec;
    vec.push_back(s1);
    vec.push_back(s2);
    vec.push_back(s3);
    
    printString(vec, printReverseLoweing);
    printString(s2, printStartToEnd);

    return 0;
}

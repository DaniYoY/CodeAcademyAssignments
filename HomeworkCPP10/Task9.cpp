// Задача 09
// Дефинирайте функция за обхождане на всеки елемент от vector от string обекти за четене. Дефинирайте функцията
// с trailing return type.
// Действието, което функцията извършва за всеки елемент трябва да се специфицира от клиента чрез указател към
// функция.
// Използвайте typedef за типа на указателя. Тествайте с принтиране на всички елементи, както и с принтиране на
// всички елементи наобратно.
#include<iostream>
#include<string>
typedef void (*printingFun)(const std::string &);
void printStartToEnd(const std::string & s){
    for (char i : s)
    {
        std::cout<<i;
    }
    std::cout<< std::endl;
}
void printReverse(const std::string & s){
    for (std::string::const_reverse_iterator i = s.crbegin(); i !=s.crend(); i++)
    {    
        std::cout<< *i;
    }
    std::cout<< std::endl;
}
auto printString(const std::string & s, printingFun order) -> void{
    order(s);
}

int main(int argc, char const *argv[])
{
    std::string s{"123456789"};
    printString(s, printReverse);

    return 0;
}

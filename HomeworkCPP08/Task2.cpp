// Задача 02
// Напишете функция за принтиране на стринг наобратно, използвайки итератори.

#include <string>
#include <iostream>

void printReverseString(const std::string & str){
   
    for (std::string::const_reverse_iterator it = str.rbegin(); it != str.rend(); it++)
    {
     std::cout << *it;
    }
}

int main(int argc, char const *argv[])
{
    std:: string s{"asdwert"};
    printReverseString(s);
    return 0;
}

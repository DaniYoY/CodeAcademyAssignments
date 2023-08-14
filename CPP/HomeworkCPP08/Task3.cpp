// Задача 03
// Напишете функция за обръщане на стринг наобратно, използвайки итератори.

#include <string>
#include <iostream>

void reverseString(std::string & str){
   std::string rstr;
   for (std::string::reverse_iterator it = str.rbegin(); it != str.rend(); it++)
   {
    rstr += *it; 
   }
   str = rstr;
    
}

int main(int argc, char const *argv[])
{
    std:: string s{"asdwert"};
    reverseString(s);
    std::cout<<s;
    return 0;
}
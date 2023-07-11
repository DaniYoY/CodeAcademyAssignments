#include "Addition.hpp"
#include "Substraction.hpp"
#include "Division.hpp"
#include "Multiplication.hpp"

#include <string>
#include <iostream>
#include <sstream>

int main()
{
    std:: string word{""};
    double a{0}, b{0}, res{0};
    std::string str{"add 1 1 subs 3 6 multi 4 5 div 10 2 "};
    std::stringstream s(str);
    while (!(s >> word >>a >> b).eof())
    // while (!(std::cin >> word >>a >> b).eof())
    {
        if(word == "add")
        {
            res = Addition(a,b).execute();
        }else if (word == "subs")
        {
            res = Substraction(a,b).execute();
        }else if (word == "multi")
        {
            res = Multiplication(a,b).execute();
        }else if (word == "div")
        {
            res = Division(a,b).execute();
        }
        std::cout << res << std::endl;
    }
    
    return 0;
}

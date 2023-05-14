// Задача 05
// Напишете програма, която принтира всички подстрингове на даден стринг, въведен от потребителя.

#include <string>
#include <iostream>

void printAllSubstrings(std::string str)
{
    for (int endPnt = 1; endPnt <= str.length(); endPnt++)
    {   
        for (int startPnt = 0; startPnt <= str.size() - endPnt; startPnt++)
        { 
            int j = startPnt + (endPnt - 1);           
            for (int k = startPnt; k <= j; k++){
                std::cout << str[k];
            }
            std::cout << std::endl;
        }
    }
}

int main (){
    printAllSubstrings("abcd");
    return 0;
}
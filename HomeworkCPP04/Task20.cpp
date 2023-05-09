// Задача 20
// Напишете функция за въвеждане на символен низ в обект от тип std::string от потребителя, който може да е на
// няколко реда

#include <iostream>
#include <string>

std::string multilineInput ()
{
    std::string line{""};
    std::string result{""};
    while (std::getline(std::cin, line))
    {
        result += line + "\n"; 
    }
    return result;
}
// Задача 06
// Напишете функция, която приема стринг и намира най-дългия под-стринг (substring), който е съставен от
// уникални символи (няма повтарящи се символи)

#include <string>
#include <iostream>

bool isMissing(std::string &str, char c);

std::string getSubstringMostUniqueChars(std::string str)
{
    std::string interim{""}, result{""};
    int counter{0}, biggestCounter{0};
    for (int i = 0; i < str.size(); i++)
    {
        if (isMissing(interim, str[i]))
        {
            interim += str[i];

            if (interim.size() > biggestCounter)
            {
                biggestCounter = interim.size();
                result.clear();
                result = interim;
            }
        }
        else
        {
            interim.clear();
        }
    }
    return result;
}

bool isMissing(std::string &str, char c)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == c)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::cout << getSubstringMostUniqueChars("asdaadfbb");
}
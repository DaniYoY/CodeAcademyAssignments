// Задача 10
// Напишете собствени версии на стандартната функция strchr от <cstring> със същия интерфейс и функционалност.
// const char* strchr( const char* str, int ch );
// char* strchr( char* str, int ch )

#include <iostream>

const char *strchr(const char *str, int ch)
{
    for (const char *it = str; *it != '\0'; it++)
    {
        if (*it == ch)
        {
            return it;
        }
    }
    return nullptr;
}

char *strchr2(char *str, int ch)
{
    for (char *it = str; *it != '\0'; it++)
    {
        if (*it == ch)
        {
            return it;
        }
    }
    return nullptr;
}

int main(int argc, char const *argv[])
{
    char arr[] = "aabaaab";
    std::cout<< strchr2(arr, 99);
    return 0;
}


// Задача 08
// Напишете собствена версия на стандартната функция strcmp от <cstring> със същия интерфейс и
// функционалност.
// int strcmp( const char *lhs, const char *rhs );

#include <iostream>

int strcmp( const char *lhs, const char *rhs ){
    while (*lhs == *rhs)
    {
        if (*lhs =='\0' && *rhs=='\0')
        {
            return 1;
        }
        lhs++;
        rhs++;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    std::cout<< strcmp("","");
    return 0;
}



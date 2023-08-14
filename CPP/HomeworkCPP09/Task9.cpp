// Задача 09
// Напишете собствена версия на стандартната функция strncmp от <cstring> със същия интерфейс и
// функционалност.
// int strncmp( const char *lhs, const char *rhs, std::size_t count );

#include <iostream>

int strcmp( const char *lhs, const char *rhs, std::size_t count  ){
    while (*lhs == *rhs)
    {
        if (count-- ==0 || (*lhs =='\0' && *rhs=='\0'))
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
    std::cout<< strcmp("asdfttt","asdfwwww",5);
    return 0;
}



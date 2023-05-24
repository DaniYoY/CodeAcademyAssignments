// Задача 11
// Напишете собствени версии на стандартната функция strrchr от <cstring> със същия интерфейс и функционалност.
// const char* strrchr( const char* str, int ch );
// char* strrchr( char* str, int ch );

#include<cstring>

const char*  cstrrchr (const char *str, int ch)
{  
    for (const char *it = str + std::strlen(str)-1; *it != *str; it--)
    {
        if (*it == ch)
        {
            return it;
        }
    }

    return nullptr;
}

char *strrchr(char *str, int ch)
{

    char *it = str+std::strlen(str)-1;
    for (; *it != '\0'; it--)
    {
        if (*it == ch)
        {
            return it;
        }
    }
    return nullptr;
}
// Задача 15
// Напишете собствена версия на стандартната функция strncmp от <cstring> със същия интерфейс и функционалност.
// char *strcat( char *dest, const char *src );

#include <iostream>
#include <cstring>

char *strcat( char *dest, const char *src ){
    size_t len = std::strlen(dest);
    while (true)
    {
        *(dest + len++) = *(src++);
        if (*src == '\0')
        {
            break;
        }
        
    }
    
    return dest;
}

int main(int argc, char const *argv[])
{
    char arr[20] ="qwerty";
    strcat(arr,"asdf");
    std::cout<< arr;
    return 0;
}

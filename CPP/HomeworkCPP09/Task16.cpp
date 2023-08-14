// Задача 16
// Напишете собствена версия на стандартната функция strncmp от <cstring> със същия интерфейс и функционалност.
// char *strncat( char *dest, const char *src, std::size_t count );

#include <iostream>
#include <array>
#include<string>
#include <cstring>
// char *strncat( char *dest, const char *src, std::size_t count ){
//     size_t destSize = std::strlen(dest);
//     size_t resultSize = destSize + count;
//     const size_t finalSize{resultSize};
//     char arr[finalSize];
//     for (size_t i = 0; i < destSize; i++)
//     {
//         *(arr + i) = *(dest+i);
//     }
//     for (size_t i = 0; i < count; i++)
//     {
//         *(arr+destSize +i) = *(src+ i); 
//     }
//     dest = arr;
//     return dest;
// }


char *strncat( char *dest, const char *src, std::size_t count ){
    size_t len = std::strlen(dest);
    for (size_t i = 0; i <= count; i++)
    {
        *(dest +len +i) = *(src+i);
    }
    
    return dest;
}

int main(int argc, char const *argv[])
{
    char arr[20] ="qwerty";
    strncat(arr,"asdf",4);
    std::cout<< arr;
    return 0;
}

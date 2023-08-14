
// Задача 14
// Напишете собствена версия на стандартната функция strcmp от <cstring> със същия интерфейс и функционалност.
// char *strncpy( char *dest, const char *src, std::size_t count );


#include <iostream>

char* strcpy( char* dest, const char* src, std::size_t count ){
    for (size_t i =0;*dest !='\0' && *src !='\0' && i<count; dest++, src++,i++)
    {
        *dest = *src;
    }
    return dest;
}

int main(int argc, char const *argv[])
{
    char arr[] = "absssssssbaaaa";
    char arr2[] = "bsssssssb";
    char arr3[7];
    strcpy(arr, arr2,2);
    std::cout<< arr;
    return 0;
}
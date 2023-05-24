// Задача 13
// Напишете собствена версия на стандартната функция strlen от <cstring> със същия интерфейс и функционалност.
// char* strcpy( char* dest, const char* src );

#include <iostream>

char* strcpy( char* dest, const char* src ){
    for (;*dest !='\0' && *src !='\0'; dest++, src++)
    {
        *dest = *src;
    }
    return dest;
}

int main(int argc, char const *argv[])
{
    char arr[] = "aaaaa";
    char arr2[] = "bb";
    char arr3[7];
    strcpy(arr, arr2);
    std::cout<< arr;
    return 0;
}



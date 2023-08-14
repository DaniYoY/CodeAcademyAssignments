// Задача 07
// Напишете собствена версия на стандартната функция strlen от <cstring> със същия интерфейс и
// функционалност.
// std::size_t strlen( const char* str );

#include<iostream>
#include<array>

std::size_t strlen( const char* str ){
    size_t result{0};
    // prefix increment operator does not work for len and I had to change the declaration to 1, not 0;
    for (size_t len = 1; *str !='\0'; ++len, str++)
    {
        result =len;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    std::cout<< strlen("");
    return 0;
}


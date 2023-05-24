// Задача 12
// Напишете собствени версии на стандартната функция strstr от <cstring> със същия интерфейс и функционалност.
// const char* strstr( const char* haystack, const char* needle );
// char* strstr( char* haystack, const char* needle );

#include <iostream>

char *strstr(char *haystack, const char *needle)
{

    bool isNotFound{false};
    for (; *haystack != '\0'; haystack++)
    {
        if (*haystack == *needle)
        {
            char *solution = haystack;
            const char *interim = needle;
            for (; *interim != '\0'; interim++, solution++)
            {
                if (*solution != *interim)
                {
                    isNotFound = true;
                    break;
                }
            }
            if (!isNotFound)
            {
                return haystack;
            }
        }
    }
    return nullptr;
}

const char *strstr(const char *haystack, const char *needle)
{
    bool isNotFound{false};
    for (; *haystack != '\0'; haystack++)
    {
        if (*haystack == *needle)
        {
            const char *solution = haystack;
            const char *interim = needle;
            for (; *interim != '\0'; interim++, solution++)
            {
                if (*solution != *interim)
                {
                    isNotFound = true;
                    break;
                }
            }
            if (!isNotFound)
            {
                return haystack;
            }
        }
    }
    return nullptr;
}

int main(int argc, char const *argv[])
{
    char arr[] = "aaaaa";
    char arr2[] = "bb";
    char arr3[7];
    strstr(arr, arr2);
    std::cout<< arr;
    return 0;
}

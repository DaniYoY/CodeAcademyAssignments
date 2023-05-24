// Задача 20
// Напишете функция, която приема 2д масив от указатели към c-string-ове и обръща реда на символите във всеки C-string

#include <iostream>
#include <cstring>
size_t arrLen(char* arr){
    size_t i {0};
    for (; *arr != '\0'; arr++)
    {
        i++;
    }
    return i;
}
void reverseArr(char* arr){
    size_t len = arrLen(arr);
    char* end = arr+ len-1;
    for (char* begin = arr; begin < end; begin++, end--)
    {
        char temp = *begin;
        *begin = *end;
        *end = temp;
    }
}
void reverseCStrInArr(char** arr, size_t rows, size_t lens){
    
    for (size_t row = 0; row < rows; row++)
    {    
        reverseArr(*(arr+row));
    }
}

int main(int argc, char const *argv[])
{
    char arr[]="123";
    char* arr2[20] ={
        arr,
        arr,
        arr
    };
    reverseCStrInArr(arr2,3,3);
    for (size_t i = 0; i < 3; i++, putchar('\n'))
    {
        for (size_t j = 0; j < 3; j++)
        {
            std::cout << arr2[i][j];
        }
    } 
    return 0;
}

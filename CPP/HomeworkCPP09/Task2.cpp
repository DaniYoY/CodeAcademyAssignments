// Задача 02
// Напишете функция, която обръща реда на елементите на масив от цели числа.

#include <string>
#include <iostream>
#include <array>

// template <std::size_t SIZE>

#define SIZE 6

void reverseIntArr(int arr[], size_t arrSize){
    
    for (int * end = arr + arrSize-1; arr < end; arr++,end--)
    {
        int temp = *arr;
        *arr = *end;
        *end =temp;
    }    
}

int main(int argc, char const *argv[])
{
    int arr[]= {1,2,3,4,5,6};
    reverseIntArr(arr, SIZE);
    for (auto num : arr)
    {
        std::cout << num<< ' ';
    }
     
    return 0;
}

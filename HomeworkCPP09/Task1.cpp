// Задача 01
// Напишете функция, която проверява дали масив от цели числа е сортиран.


#include <string>
#include <iostream>
#include <array>

#define SIZE 6

bool isSortedAcsending(int arr[], size_t size){
    bool isAcs{false};
    for (size_t i = 0; i < size; i++, arr++)
    {
        if (*arr > arr[1])
        {
            return false;
        }
    }
    return true;
}
bool isSortedDescending(int arr[], size_t size){
    bool isDes{false};
    for (int* end = arr+size; arr != end; arr++)
    {
        if (*arr < arr[1])
        {
            return false;
        }
        arr++;
    }
    return true;
}

bool isSorted(int arr[], size_t size){
    return isSortedAcsending(arr, size) || isSortedDescending(arr, size);
}

int main(int argc, char const *argv[])
{
    int arrA[SIZE] = {25,26,29,30,32,65};
    int arrD[] = {6,5,4,3,2,1};
    std::cout << isSorted(arrA, SIZE) << '\n' << isSorted(arrD, SIZE);

    return 0;
}

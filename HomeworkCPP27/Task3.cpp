// Задача 03
// Напишете function template, който връща размера на масив.

#include<iostream>
#include <array>
template <size_t T,  typename U>
int arrSize(std::array<U, T> arr)
{
    return T;
}


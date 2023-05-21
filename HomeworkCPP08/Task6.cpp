// Задача 06
// Напишете функция, която връща първата уникална стойност на елемент в std::array от цели числа.

#include <string>
#include <iostream>
#include <array>
#include <random>

template <std::size_t SIZE>

unsigned int getFirstUniqueNum(std::array<unsigned int, SIZE> arr){
    for (std::array<unsigned int, SIZE>::iterator it = arr.begin(); it != arr.end(); it++)
    {
        bool isUnique{false};
        for (std::array<unsigned int, SIZE>::iterator iter = arr.begin(); iter != arr.end(); iter++)
        {
            if (it == iter)
            {
                continue;
            }
            
            if (*iter == *it && iter != it)
            {
                isUnique = false;
                break;
            }
            isUnique = true;
        }
        if (isUnique)
        {
            return *it;
        }  
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    std::array<unsigned int, 9> arr ={5,2,2,3,4,3,5,143,2};
    std::cout<< getFirstUniqueNum(arr);
    return 0;
}

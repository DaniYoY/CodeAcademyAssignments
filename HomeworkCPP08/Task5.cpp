// Задача 05
// Напишете функция, която запълва std::array с произволни числа в подаден като аргументи интервал от допустими
// стойности

#include <string>
#include <iostream>
#include <array>
#include <random>

std::array<int, 10> fillArray(int randomEndNum){
    std::srand(1);
    std::array<int, 10> arr;
    randomEndNum++;
    for (size_t i = 0; i < arr.size(); i++)
    {
        arr[i] = std::rand() % randomEndNum;
    }
    return arr;
}

int main(int argc, char const *argv[])
{
    std::array<int,10> rr = fillArray(12);
    for (size_t i = 0; i < 10; i++)
    {
        std::cout<< rr[i] << " ";
    }
    
    return 0;
}

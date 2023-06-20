// Задача 02
// Разширете предходната програма, така че да създава копие на оригиналния масив, в което стойностите са отзад-
// напред.

#include <iostream>

int main()
{
    size_t size{0};
    std::cout << "Enter size of array and then enter numbers: "<< std::endl;
    std::cin >> size;
    int* numbers= new int[size];
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> numbers[i]; 
    }
    int* numbersInReverse = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        numbersInReverse[i] = numbers[size-1 -i];
    }
    delete[] numbers;
    numbers = nullptr;
    
    for (size_t i = 0; i < size; i++)
    {
        std::cout<< *(numbersInReverse +i) <<" ";
    }
    
    delete [] numbersInReverse;
    numbersInReverse = nullptr;
    return 0;
}
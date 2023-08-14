// Задача 01
// Напишете програма, в която потребителя въвежда брой на числа, след което въвежда числата. Принтирайте
// въведените числа и тяхната сума

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
    for (size_t i = 0; i < size; i++)
    {
        std::cout<< *(numbers +i) <<" ";
    }
    
    delete[] numbers;
    numbers = nullptr;
    return 0;
}

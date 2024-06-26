// Задача 03
// Напишете функция за реалокация на масив от int, която масива и нов размер и добавя елементи в масива открая,
// правейки необходимата реалокация на ново място в паметта.

#include <iostream>

int * addArrToCurrentArray(int *&currentArray, size_t size,const int*  values, size_t valuesSize)
{

    int *newArray = new int[size + valuesSize];
    for (size_t i = 0; i < size; i++)
    {
        newArray[i] = *(currentArray + i);
    }
    for (size_t i = 0; i < valuesSize; i++)
    {
        newArray[i +size] = values[i];
    }
    
    delete[] currentArray;
    currentArray = nullptr;
    return newArray;
}

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

    int addition[]{3,5,6,98,7};

    size_t valuesSize = sizeof(addition) / sizeof (*addition); 
    numbers = addArrToCurrentArray(numbers,size, addition, valuesSize);
    //  print numbers
    for (size_t i = 0; i < size+valuesSize; i++)
    {
        std::cout<< *(numbers +i) <<" ";
    }
    
    delete[] numbers;
    numbers = nullptr;
    return 0;
}

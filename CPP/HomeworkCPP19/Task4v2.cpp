// Задача 04
// Напишете програма, в която потребителя започва да въвежда цели положителни числа до грешни входни данни
// или EOF
// За целта, напишете логика за двойно уголемяване на текущата памет с числа, всеки път в който потребителя
// надвиши текущия “капацитет” (размер на динамично заделената памет в случая), подобно на vector, само че на
// място във функция, вместо в код на клас

#include <iostream>
#include <string>

int * updateArray(int *&currentArray, size_t &size)
{
    size *= 2;
    int *newArray = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        newArray[i] = *(currentArray + i);
    }
    delete[] currentArray;
    currentArray = nullptr;
    return newArray;
}

int main()
{
    size_t size{1};
    std::cout << "enter numbers: " << std::endl;
    int *numbers = new int[size];

    int temp{0};
    std::string line{""};
    int currentIndex{0};
    try
    {
        while (!std::getline(std::cin, line).eof())
        {

            temp = std::stoi(line);

            if (currentIndex == size)
            {
                numbers = updateArray(numbers, size);
            }

            numbers[currentIndex] = temp;
            currentIndex++;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    // print the result
    for (size_t i = 0; i < size; i++)
    {
        std::cout << *(numbers + i) << " ";
    }
    delete[] numbers;
    numbers = nullptr;
    return 0;
}
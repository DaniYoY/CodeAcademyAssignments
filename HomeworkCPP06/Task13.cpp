// Задача 13
// Напишете програма, която моли потребителя да въведе множество от целочислени стойности, след което принтира
// резултатите от прилагането на побитовите AND, OR и XOR оператори на цялото множество.

#include <iostream>
#include <vector>

std::vector<unsigned int> inputNumbers(){
    std::vector<unsigned int> numbers;
    unsigned int n{0};
    while (std::cin.eof())
    {
        std::cin >> n;
        numbers.push_back(n);
    }
    return numbers;
}

unsigned int applyBitOperation(std::vector<unsigned int> numbers, char oprtr){
    switch (oprtr)
    {
    case '^':
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            numbers[0] ^= numbers[i]; 
        }
        break;
    case '|':
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            numbers[0] |= numbers[i]; 
        }
        break;
    case '&':
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            numbers[0] &= numbers[i]; 
        }
        break;
    default:
        std::cout << "Selected operator is not correct. You can choose between ^,&,|"<<std::endl;
        break;
    } 
    return numbers[0];   
} 


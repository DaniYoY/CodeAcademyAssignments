// Задача 02
// Напишете функция, която приема три вектора от цели числа - един пълен и два празни.
// Функцията трябва да пълни единия празен с четните числа от пълния и другия празен - с
// нечетните.

#include <iostream>
#include <string>
#include <vector>

void divideInOddsAndEvens(std::vector<int> numbers, std::vector<int> & oddNumbers, std::vector<int> & evenNumbers){
    
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] %2 ==0)
        {
            evenNumbers.push_back(numbers[i]);
        }else{
            oddNumbers.push_back(numbers[i]);
        }
    }
    return; 
}
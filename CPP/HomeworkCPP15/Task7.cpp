// Задача 07
// С учебна цел, папишете функции за swap на две цифри (по позиция на цифрите) в положително число и за
// сортиране на цифрите на такова число

#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>

int swapDigits(long number, int firstNumPos, int secondNumPos)
{
    std::vector<int> v;
    int result {0}; 
    for (size_t i = number; i > 0; i/=10)
    {
        v.push_back(i%10);
    }
    std::swap(v[firstNumPos], v[secondNumPos]);

    for (size_t i = 0; i < v.size(); i++)
    {
        result += v[i]*std::pow(10,i);        
    }
    return result;
}

int main(int argc, char const *argv[])
{
    std::cout << swapDigits(365987410, 3,4);
    return 0;
}

// Задача 02
// Напишете функция, която приема контейнер от числа и десетична цифра и използва std::find_if за
// да намери първото число от контейнера, в което не се открива подадената цифра.

#include <algorithm>
#include <iostream>
#include <vector>

bool containsNot(int number, int digit){
    for (int i = number; i !=0; i /=10)
    {
        if (i%10 == digit)
        {
            return false;
        }
        
    }
    return true;
}
int firstNumWithoutDigit(std::vector<int> & numbers, int digit){
    auto lamdaPredicate = [& digit](int value){return containsNot(value, digit);};
    return *(std::find_if(numbers.begin(), numbers.end(), lamdaPredicate));
}

int main(int argc, char const *argv[])
{
    std::vector<int> v{1,11,1111,12111,1231,998798,6541};
    std::cout<< firstNumWithoutDigit(v, 1);
    return 0;
}

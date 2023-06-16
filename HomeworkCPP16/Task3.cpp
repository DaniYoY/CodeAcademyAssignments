// Задача 03
// Напишете функция, която приема контейнер от цели положителни числа и използва std::remove_if
// за да премахне тези от тях, в които има 0 в бинарната им репрезентация, т.е. да останат само тези
// числа, които са съставени само от 1ци, в бинарен формат.

#include <algorithm>
#include <iostream>
#include <list>

bool containsZeroInBinary(int number){
    while (number > 0)
    {
        if (~number&1) 
        {
            return true;
        }
        number >>= 1;
    }
    
    return false;
}
void removeIfBinaryHasZero(std::list<int> & numbers){
    auto lamdaPredicate = [](int value){return containsZeroInBinary(value);};
    auto lastIter = std::remove_if(numbers.begin(), numbers.end(), lamdaPredicate);
    numbers.erase(lastIter, numbers.end());
}

int main(int argc, char const *argv[])
{
    std::list<int> v{1,2,3,4,5,6,7,8,15}; //1 10 11 100 101 110 111 1000 1111
    removeIfBinaryHasZero(v);
    for (auto i = v.begin(); i !=v.end(); i++)
    {
        std::cout<< *i << ' ';
    }
    
    return 0;
}

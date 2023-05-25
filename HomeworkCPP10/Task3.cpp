// Задача 03
// Дефинирайте constexpr функция за повдигане на число на степен с два параметъра, втория, от които специфицира
// степента и има default стойност, равна на 2.
// Извикайте те я както по начин, по който бихме могли да използваме резултата й като constant expression (за размер
// на масив, например), както и по начин, по който не бихме могли.
#include <iostream>
constexpr unsigned int power(int num, int power =2){
    unsigned int result{1};
    if (power == 0)
    {
        return 1;
    }else 
    {
        for (size_t i = 1; i < power; i++)
        {
            result *= num;
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int arr[power(3)];
    int a{0};
    std::cin >>a;
    std::cout<< power(3, a);
    return 0;
}

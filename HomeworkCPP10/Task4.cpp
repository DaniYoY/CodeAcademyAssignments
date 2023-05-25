// Задача 04
// Дефинирайте constexpr функция за изчисляване на факториел на цяло, положително число.
#include <iostream>
constexpr unsigned long long factorial (unsigned long long num){
    for (unsigned long long i = num-1; i > 1; i--)
    {
        num *=i;
    }
    return num;
}

int main(int argc, char const *argv[])
{
    char arr[factorial(5)];
    std::cout << factorial(4);
    return 0;
}

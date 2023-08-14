// Задача 05
// Дефинирайте constexpr функция за изчисляване на число на фибоначи, отговарящо на даден индекс.
#include <iostream>
constexpr unsigned int fibonacci(unsigned int num){
    unsigned int a {1}, b{1}, c{0};
    if (num == 0)
    {
        return 0;
    }
    
    if (num == 1 || num == 2)
    {
        return 1;
    }
    
    for (size_t i = 3; i <= num; i++)
    {
        c =a+b;
        a =b;
        b = c;
    }
    return c;
}
int main(int argc, char const *argv[])
{
    int arr[fibonacci(5)];
    std::cout << fibonacci(6);
    return 0;
}

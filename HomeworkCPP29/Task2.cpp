// Задача 2
// Дефинирайте макроси IS_EVEN и IS_ODD за проверка на това дали цяло число е четно или нечетно.

#define IS_EVEN(x) ((x)%2==0 ? 1 : 0)
#define IS_ODD(x) ((x)%2==0 ? 0 : 1)

#include<iostream>

int main(int argc, char const *argv[])
{
    std::cout<< IS_EVEN(2);
    std::cout<< IS_EVEN(1);
    std::cout<< IS_ODD(2);
    std::cout<< IS_ODD(1);
    return 0;
}

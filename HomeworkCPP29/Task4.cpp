// Задача 4
// Дефинирайте макроси IS_IN_RANGE, който проверява дали дадено число се намира в даден интервал.

#define IS_IN_RANGE(x,a,b) ( (((x)>(a)) && ((x) < (b))) ? 1 : 0) 

#include<iostream>

int main()
{
    std::cout << IS_IN_RANGE(0,-10,5);
    std::cout << IS_IN_RANGE(1000,-10,5);
    return 0;
}

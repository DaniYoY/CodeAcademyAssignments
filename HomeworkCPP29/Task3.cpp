// Задача 3
// Дефинирайте макрос SWAP, който сменя стойностите на две променливи.



#define SWAP(a,b) std::swap((a),(b))

#include <iostream>
int main(int argc, char const *argv[])
{
    int a{2};
    int b{202};
    std::cout << a << ' ' << b << std::endl;
    SWAP(a,b); 
    std::cout << a << ' ' << b << std::endl; 
    return 0;
}

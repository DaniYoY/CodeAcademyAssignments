// Задача 07
// Използвайте std::binary_search за да откриете дали число, въедено от потребителя,
//  може да бъде открито в контейнер от числа, също въведен от потребителя.


#include <algorithm>
#include <iostream>
#include <vector>


int main(int argc, char const *argv[])
{
    std::vector<int> v1{1,2,3,4,5,6,7,8,15}; //1 10 11 100 101 110 111 1000 1111
    int number{0};
    std::cin >> number;
    std::cin.ignore();    
    if (std::binary_search(v1.begin(),v1.end(), number))
    {
        std::cout << "Found" << std::endl;
    }else{
        std::cout << "Not Found" << std::endl;
    }
    

    return 0;
}
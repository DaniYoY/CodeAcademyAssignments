// Задача 12
// Напишете функция, която използва std::partition за да премести всичките четни числа
// от контейнер с цели числа в началото на контейнера.
#include <algorithm>
#include <vector>
#include <iostream>

void print_vec(std::vector<int> &v){
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << ' ';
    }
}

void sortByPlacingEvenNumFirst (std::vector<int> & v){
    const int EVEN_SEPARATOR = 2;
    std::partition(v.begin(), v.end(), 
    [](int a){return a%EVEN_SEPARATOR == 0 ;});

}

int main(int argc, char const *argv[])
{
    std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
    sortByPlacingEvenNumFirst(v);
    print_vec(v);
    return 0;
}

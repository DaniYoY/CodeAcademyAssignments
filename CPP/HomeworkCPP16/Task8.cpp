// Задача 08
// Напишете нова версия на предходната задача, в която поддържаме
// контейнера с числа сортиран, в всяко новодобавено от потребителя число,
// използвайки std::lower_bound.


#include <algorithm>
#include <iostream>
#include <vector>

void print_vec(std::vector<int> &v){
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << ' ';
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> v; 
    int number{0};
    while(number >= 0){
        std::cin >> number;
        std::cin.ignore();
        auto placeForInsertion = std::lower_bound(v.begin(), v.end(), number);
        v.insert(placeForInsertion, number);
    }
    print_vec(v);
    return 0;
}
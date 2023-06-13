// Задача 04
// Напишете програма, в която използвате std::transform за да създадете копие на вектор от цели числа, което
// съдържа числата от оригиналния контейнер, повдигнати на квадрат.

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

void squares(std::vector<int> & source, std::vector<int> & destination){
    destination.resize(source.size());
    std::transform(source.begin(),source.end(), destination.begin(),[](int val) {return std::pow(val,2);});
}
void print_vec(std::vector<int> &v){
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << ' ';
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> v1{1,2,3,4,5,6,7,8,15}; //1 10 11 100 101 110 111 1000 1111
    std::vector<int> v2;
    squares(v1, v2);
    print_vec(v2);

    return 0;
}



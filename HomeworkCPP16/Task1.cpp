// Задача 01
// Напишете функция, която занулява всичките елементи на вектор от цели числа, които са съседни и
// имат еднаква стойност, използвайки std::fill_n.
// 9 9 1 2 3 4 1 1 1 1 1 1 1 1 1 2 2 2 3 4 5 4 4 4 4 4 4 5 6 7 8 8 8 9
// ->
// 0 0 1 2 3 4 0 0 0 0 0 0 0 0 0 0 0 0 3 4 5 0 0 0 0 0 0 5 6 7 0 0 0 9

#include <algorithm>
#include <iostream>
#include <vector>
bool areEquals(int a, int b)
{
    return a == b;
}
void nulifyNeighbours(std::vector<int> &v)
{
    int totalCountOfEquals{1};
    for (auto firstEqualMember = v.begin(); firstEqualMember != v.end();)
    {
        if (areEquals(*firstEqualMember, *(firstEqualMember + totalCountOfEquals)))
        {
            totalCountOfEquals++;
        }
        else
        {
            if (totalCountOfEquals != 1)
            {
                std::fill_n(firstEqualMember, totalCountOfEquals, 0);
                firstEqualMember += totalCountOfEquals;
                totalCountOfEquals = 1;
            }else{
                firstEqualMember++;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> v{9, 9, 1, 2, 3, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 4, 5, 4, 4, 4, 4, 4, 4, 5, 6, 7, 8, 8, 8, 9};
    nulifyNeighbours(v);
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << ' ';
    }

    return 0;
}

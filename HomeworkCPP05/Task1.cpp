// Задача 01
// Напишете функция, която приема два вектора от цели числа и добавя копие на числата от
// втория в края на първия.

#include <vector>

std::vector<int> join(std::vector<int> & v1, std::vector<int> & v2){
    for (int i = 0; i < v2.size(); i++)
    {
        v1.push_back(v2[i]);
    }
    return v1;
}
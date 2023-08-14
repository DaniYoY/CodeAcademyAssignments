// Задача 03
// Напишете функция, която проверява дали вектор от стрингове е сортиран лексикографски.

#include <string>
#include <vector>

bool isOrderedLexicographically(std::vector<std::string> v1){
    for (int i = 0; i < v1.size() -1; i++)
    {
        if (v1[i] > v1[i+1])
        {
            return false;
        }
    }
    return true;
}
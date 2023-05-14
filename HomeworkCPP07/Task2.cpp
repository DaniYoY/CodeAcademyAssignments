// Задача 02
// Напишете функция, която приема вектор от цели числа и проверява дали съществува под-вектор (последователност
// от елементи в оригиналния контейнер), чиято сума на елементите е равна на 0.

#include <vector>
bool equalsSequenceZero(std::vector<int> numbers){
    for (int i = 0; i < numbers.size()-1; i++)
    {
        if (numbers[i] + numbers[i+1]==0)
        {
            return true;
        }
    }
    return false;
}
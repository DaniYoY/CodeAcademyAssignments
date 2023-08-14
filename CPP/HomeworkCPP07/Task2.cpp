// Задача 02
// Напишете функция, която приема вектор от цели числа и проверява дали съществува под-вектор (последователност
// от елементи в оригиналния контейнер), чиято сума на елементите е равна на 0.

#include <vector>
#include <iostream>

bool equalsSequenceZero(const std::vector<int> & numbers){
    int sum{0};
    for (int i = 0; i < numbers.size(); i++)
    {
        sum +=numbers[i];
    }
    return sum == 0;
}

 std::vector<std::vector<int>> generteSubVectors (const std::vector<int> & numbers){
    std::vector<std::vector<int>> result;
    for (size_t start = 0; start < numbers.size(); start++)
    {
        for (size_t end = 0; end < numbers.size(); end++)
        {
            std::vector<int> subVector;
            for (size_t i = start; i <= end; i++)
            {
                subVector.push_back(numbers[i]);
            }
            result.push_back(subVector);
            subVector.clear();
        }
    }
    return result;    
 }

 void printNumVector (const std::vector<int> & nums){
    for (size_t i = 0; i < nums.size(); i++)
    {
        std::cout<< nums[i]<<", ";
    }
    std::cout<<std::endl;
 }

 int main(){
    std::vector<int> nums;
    std::vector<std::vector<int>> subs;
    nums = {1,-1,0,1,1,-2};
    subs = generteSubVectors(nums);
    for (const std::vector<int> v : subs)
    {
        if (equalsSequenceZero(v))
        {
            printNumVector(v);
        }
    }
 }
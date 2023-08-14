// Задача 03
// Напишете функция, която приема вектор от цели числа и връща под-вектор, чиято сума на елементите е равна на
// подаден на функцията параметър.

#include <vector>
#include <iostream>

bool equalsNumber(const std::vector<int> & numbers, int number){
    int sum{0};
    for (int i = 0; i < numbers.size(); i++)
    {
        sum +=numbers[i];
    }
    return sum == number;
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
    int target{0};
    target = 2;
    nums = {1,-1,0,1,1,-2};
    subs = generteSubVectors(nums);
    for (const std::vector<int> v : subs)
    {
        if (equalsNumber(v,target))
        {
            printNumVector(v);
        }
    }
 }
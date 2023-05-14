// Задача 04
// Напишете функция, която приема вектор от цели числа и връща най-дългия под-вектор (с най-много на брой
// елементи), чиито елементи са сортирани във възходящ ред.

#include <vector>
#include <iostream>

std::vector<int> getLongestAcsSubvector (std::vector<int> nums){
    std::vector<int> interim, result;
    int counter{0}, biggestCounter{0};
    for (int i = 0; i < nums.size()-1; i++)
    {
        if (nums[i]<nums[i+1])
        {
            counter++;
            interim.push_back(nums[i]);
            if(i+1 == nums.size()-1){
                interim.push_back(nums[i+1]);
            }
            if (counter > biggestCounter)
            {
                biggestCounter = counter;
                result.clear();
                for (int j = 0; j < interim.size(); j++)
                {
                    result.push_back(interim[j]);
                } 
            }
            
        }else{
            if ( i!=0 && nums[i] > nums[i-1])
            {
                counter++;
                interim.push_back(nums[i]);
                if (counter > biggestCounter)
            {
                biggestCounter = counter;
                result.clear();
                for (int j = 0; j < interim.size(); j++)
                {
                    result.push_back(interim[j]);
                } 
            }
            }
            
            interim.clear();
            counter =0;
        } 
    }
    return result;
}

int main(){
    std::vector<int> test;
    test = getLongestAcsSubvector({-1, 0, -1,2,3,0,2,4,5,-6,7,8,9});
    for (int i = 0; i < test.size(); i++)
    {
        std::cout<< test[i]<<" ";
    }
    
}
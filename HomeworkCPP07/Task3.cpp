// Задача 03
// Напишете функция, която приема вектор от цели числа и връща под-вектор, чиято сума на елементите е равна на
// подаден на функцията параметър.

// NOT WORKING

#include <vector>
#include <iostream>
bool equalsTarget(int target, std::vector<int>  numbers);
std::vector<int>::iterator positionItertor(int i, std::vector<int> vector);

std::vector<int> gatherSubvectorEaquals(int target, std::vector<int> numbers){
    std::vector<int> result(numbers.size());
    std::vector<int> endResult;
    
    if(equalsTarget(target, numbers)){
        for (int i = 0; i < numbers.size(); i++)
        {
            endResult.push_back(numbers[i]);
        }
    }else{
       result = numbers;
       for (int i = 0; i < result.size(); i++)
       {
        std::vector<int>::iterator it;
        it = positionItertor(i, result);
        result.erase(it);
        endResult = gatherSubvectorEaquals(target, result);
       }
       
       
    }
    return endResult;    
}

bool equalsTarget(int target, std::vector<int>  numbers){
    int interimSum{0}; 
    for (int i = 0; i < numbers.size(); i++)
    {
        interimSum += numbers[i];
    }
    return interimSum == target;
}

std::vector<int>::iterator positionItertor(int i, std::vector<int> vector){
    std::vector<int>::iterator it;
    it = vector.begin();
    for (int j = 0; j < i; j++)
    {
        it++;
    }
    return it;
}

int main(){
    std::vector<int> v;
   v = gatherSubvectorEaquals(2, {1,1,2,3,4,5});
   for (int i = 0; i < v.size(); i++)
   {
    std::cout << v[i];
   }
   
}
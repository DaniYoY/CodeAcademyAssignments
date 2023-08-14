// Задача 06
// Напишете функция, която приема вектор от стрингове и принтира всички дублиращи се елементи.


#include <iostream>
#include <string>
#include <vector>

void printDupes(const std::vector<std::string> & v1){
    int size = v1.size();
    std::vector<bool> map(size, false);  
    for (int i = 0; i < v1.size()-1; i++)
    {
        for (int j = i+1; j < v1.size(); j++)
        {
            if (map[i])
            {
                break;
            }
            if (map[j])
            {
                continue;
            }
            if (v1[i] == v1[j])
            {
                map[i] = true;
                map[j] = true;
            }  
        }
    }
    for (int i = 0; i < v1.size(); i++)
    {
        if (map[i])
        {
            std::cout << v1[i] << std::endl;
        }
    }
    
    return;
}


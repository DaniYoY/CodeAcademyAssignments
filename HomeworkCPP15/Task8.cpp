// Задача 08
// С учебна цел, напишете функция за binary search в цифрите на цяло положително число.

#include<algorithm>
#include<string>
#include<iostream>
#include<vector>

int bsDigit(long number,int digit)
{   
    std::vector<int> v;
    for (size_t i = number; i > 0; i/=10)
    {
        v.push_back(i%10);
    }
    
    std::sort(v.begin(),v.end());
    size_t highBorder = v.size();
    size_t lowBorder = 0;

    while (highBorder - lowBorder > 1)
    {
        size_t midIdx = (highBorder+lowBorder)/2;
        if (v[midIdx] == digit)
        {
            return digit;
        }
        
        if (v[midIdx] < digit)
        {
            lowBorder = midIdx;
        }else{
            highBorder = midIdx;
        }
    }

    if (v[highBorder] == digit)
    {
        return v[highBorder];
    }

    if (v[lowBorder] == digit)
    {
        return v[lowBorder];
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    std::cout<< bsDigit(18949648,8);
    return 0;
}


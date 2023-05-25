// Задача 11
// Дефинирайте функция за преброяване елементите във вектор от unsigned char, които отговарят на определен от
// клиента критерий, специфициран чрез указател към функция.
// Тествайте с преброяване на всички елементи, чиито бинарни целочислени репрезентации са:
// * с равен брой нули и единици
// * съставени от елтерниращи по стойности нули и единици (нямат два съседни бита с равна стойност)

#include<iostream>
#include<string>
#include<vector>
//  with issue by returning the bool pointer function
typedef bool (*check)(unsigned char& n);


bool areAlterningBits(unsigned char& n){
    int cur = n&1;
    n = n >> 1;
    while(n > 0){
        if(cur == (n&1)){
            return false;
        }
        cur = n&1;
        n = n >> 1;
    }
    return true;
}
bool areEqualsZeroesAndOnes(unsigned char& n){
    int ones{0}, zeroes{0};
    while (n >0)
    {
        if (n & 1)
        {
            ones++;
        }else{
            zeroes++;
        }
        n = n>>1;
    }
    return ones == zeroes;
}

auto count (std::vector<unsigned char> & vec, check) -> int{
    int result{0};
    for (unsigned char & i : vec)
    {
        bool ch = check(i); 
        if (ch)
        {
            result++;
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    std::vector<unsigned char> vec ={0b1110101,0b101,0b1010,0b1100,0b110100};
    std::cout<< count(vec, areEqualsZeroesAndOnes)<<'\n';
    std::cout<< count(vec, areAlterningBits)<<'\n';
    return 0;
}

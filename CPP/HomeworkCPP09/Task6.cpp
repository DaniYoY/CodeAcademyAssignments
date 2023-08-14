// Задача 06
// Напишете функция, която завърта масив от цели числа с N позиции наляво
#include <iostream>
#include <array>

void stir(int * arrBegin,int * arrEnd,size_t const pos){

   for (int* it = arrBegin; it != arrEnd -pos; it++)
   {
    int temp = *it;
    *it = *(it+pos);
    *(it+pos) = temp;
   }
}

int main(int argc, char const *argv[])
{
    
    std::array<int, 10> arr={1,2,3,4,5,6,7,8,9,10};
    stir(arr.begin(),arr.end(),3);
    for (auto num : arr)
    {
        std::cout<< num<<' ';
    }
    
    
    return 0;
}

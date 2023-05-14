// Задача 10
// Напишете функция, която приема цяло положително число и връща дали броя на битовете в бинарната му
// репрезентация, които са равни на 1, е четен.
#include <iostream>

int main (){
    int a{0}, counter{0};
    std::cin>> a;
    for (int i = a; i != 0; i/=2)
    {
        if(1 & i){
            counter++;
        }
    }
    if(counter %2==0){
        std::cout<< "1's are an odd number";
    }else{
        std::cout<< "1's are an even number";
    }
    return 0;
}
// Задача 09.
// Напишете функция, която приема цяло положително число и връща броя на битовете в бинарната му
// репрезентация, които са равни на 1.

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
    std::cout<< counter ;
    return 0;
}
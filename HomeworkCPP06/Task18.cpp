// Задача 18
// Напишете функция, която приема цяло положително число и връща броя на битовете в най-дългата
// последователност от битове, равни на 1 в числото.

#include <iostream>

int main (){
    unsigned long long a{0ull};
    int counter{0}, biggest{0};
    std::cin>> a;
    for (unsigned long long i = a; i != 0; i/=2)
    {
        if(1 & i){
            counter++;
        }else{
            if (biggest<counter)
            {
                biggest = counter;
            }
            counter =0;
        }
    }
    std::cout<< biggest;
    return 0;
}
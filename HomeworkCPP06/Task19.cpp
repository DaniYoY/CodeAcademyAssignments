// Задача 19
// Напишете функция, която приема цяло положително число и проверява дали бинарната му репрезентация е
// съставена изцяло от алтерниращи стойности на цифрите (дали в бинарната му репрезентация не може да се открие
// двойка съседни цифри с еднаква стойност)

#include <iostream>

int main (){
    unsigned long long a{0ull};
    int counterOnes{0}, biggestOnes{0},counterZeros{0}, biggestZeros{0};
    std::cin>> a;
    for (unsigned long long i = a; i != 0; i/=2)
    {
        if(1 & i){
            counterOnes++;
            if (biggestZeros<counterZeros)
            {
                biggestZeros = counterZeros;
            }
            counterZeros =0;
        }else{
            counterZeros++;
            if (biggestOnes<counterOnes)
            {
                biggestOnes = counterOnes;
            }
            counterOnes =0;
        }
    }

    if (biggestOnes == 1 && biggestZeros ==1)
    {
        std::cout << "The number binary represantation has ONLY alterning bits";
    }else{
        std::cout << "The number binary represantation has NOT ONLY alterning bits";
    }
    std::cout << biggestOnes <<biggestZeros;
    return 0;
}
// Задача 11
// Напишете функция, която приема цяло положително число и връща броя нулите в бинарната му репрезентация,
// които са в края на числото (най-отдясно - least significant)

#include <iostream>

int countLestSignificantZeros (int a){
    int counter{0}, pos{0};
    
    for (int i = a; i != 0; i/=2)
    {
        if(1 & i){
            break;
        }else{
            counter++;
        }
    }
    return counter;
}
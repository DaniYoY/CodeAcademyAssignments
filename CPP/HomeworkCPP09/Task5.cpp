// Задача 05
// Напишете функция, която приема масив от unsigned char целочислени стойности и копира тези от тях, които
// съдържат четен брой единици в побитовата бинарна репрезентация във втори масив, и копира тези с нечетен
// брой единици - в трети. Функцията трябва да допуска, че вторите два масива (в които пише числа с четен и
// нечетен брой битове) са достатъчно големи и да не прави проверки за това.

#include <string>
#include <iostream>

// template <std::size_t SIZE>

#define SIZE 6

void separateElementByBininaryOnes(unsigned char * srcBegin,unsigned char * srcEnd,unsigned char * evens, unsigned char * odds ){

    for (;srcBegin != srcEnd; srcBegin++)
    {
        int counter{0};
        for (unsigned int i = *srcBegin; i != 0; i/=2)
        {
            if(1 & i){
                counter++;
            }
        }

        if(counter %2==0){
            *evens = *srcBegin;
            evens++;
        }else{
            *odds  = *srcBegin;
            odds++;
        }
    }
}
int main(int argc, char const *argv[])
{
    unsigned char c1{0b00001}; /*odd*/
    unsigned char c7{0b00111}; /*odd*/
    unsigned char c10{0b01010}; /*even*/
    unsigned char c6{0b00110}; /*even*/
    unsigned char c5{0b00101}; /*even*/
    unsigned char c3{0b00011}; /*odd*/
    unsigned char arr[] = {c1,c7,c3,c10,c5,c6};
    unsigned char evens[3];
    unsigned char odds[3];
    separateElementByBininaryOnes(std::begin(arr), std::end(arr), evens,odds);
    return 0;
}

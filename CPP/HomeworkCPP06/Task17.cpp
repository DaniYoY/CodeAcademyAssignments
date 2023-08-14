// Задача 17
// Напишете програма, принтира общия брой на битове в бинарните репрезентации на числата от 1 до N (N се въвежда
// от потребителя), равни на 1

#include <iostream>

int main (){
    int a{0}, counter{0};
    std::cin>> a;
 for (int i = 1; i <= a; i++)
 {
     for (int j = i; j != 0; j/=2)
    {
        if(1 & j){
            counter++;
        }
    }
 }
    std::cout<< counter ;
    return 0;
}
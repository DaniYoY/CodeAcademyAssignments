// Задача 01
// Напишете функция, която връща произволно число в подаден от потребителя интервал, използвайки std::rand.

#include <iostream>
#include <random>

    static unsigned int State = 1804289383;
unsigned int generateRandomNumber( unsigned int lower, unsigned int upper){
    unsigned int num = State;
    num ^= num << 13;
    num ^= num >> 17;
    num ^= num << 5;
    State = num;
    return (num % (upper - lower)) + lower;
}




void printRandomNumber(){
    unsigned int a{0},b{0};
    std::cout << "enter numbers"<<std::endl;
    std::cin >> a>>b;
    std::srand(a); 
    if (a > b)
    {
        unsigned int temp = a;
        a= b;
        b=temp;
    }
    
    std::cout << std::rand() % b << std::endl;
    std::cout << generateRandomNumber(a,b);
    return;
}

int main(int argc, char const *argv[])
{
    printRandomNumber();
    return 0;
}

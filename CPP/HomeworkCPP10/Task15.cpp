// Задача 15
// Напишете илюстративна програма, в която демонстрирате последната стъпка от процеса по
// function argument matching за извикването на множество overloaded функции.
// Покажете примери, в които се открива най-добър кандидат на последната стъпка от процеса,
// комбинирайки следните категории (разпишете примери за всяка възможна двойка от категории):
// 1. Изцяло съвпадащ тип
// 2. const reference преобразуване
// 3. Преобразуване посредством промотиране на тип
// 4. Преобразуване на аритметичен тип или на указател

// Not started

#include <iostream>
typedef void (*example)(int a);
// double sum(double a, double b, double c){
//     return a+b+c;
// }
double sum(double a, double b){
    return a+b;
}
// int sum(int a, int b){
//     return a+b;
// }
// double sum(const double a,const double b){
//     return a+b;
// }
void matchingOverload(){
    std::cout<< "Matching overload ";
    double a{2.0}, b{3.0};
    std::cout<< a << '+' << b << '='<<sum(a,b)<< std::endl;
}

void constRefOverload(){
    std::cout<< "Const ref overload ";
    const double a = 3.6f;
    std::cout<< a << '+' << 5.0f << '='<<sum(5.0f,a)<< std::endl;
}

void promoOverload(){
    std::cout<< "Promotion overload ";
    char a{2};
    bool b{true};
    std::cout<< a << '+' << b << '='<<sum(a,b)<< std::endl;
}

void aritmeticOverload(){
    std::cout<< "Aritmetic overload ";
    int a{2};
    int b{3};
    std::cout<< a << '+' << b << '='<<sum(a,b)<< std::endl;
}

int main(int argc, char const *argv[])
{
    matchingOverload();
    constRefOverload();
    aritmeticOverload();
    promoOverload();
    return 0;
}

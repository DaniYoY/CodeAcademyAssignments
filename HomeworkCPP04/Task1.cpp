// Задача 01
// Напишете програма, в която имаме една глобална и една локална променлива с едно и също име, но с различни
// начални стойности. Принтирайте стойностите на двете променливи от тялото на функцията, в която е дефинирана
// локалната променлива.

#include <iostream>

int globalVar {2};
int main(){
    int globalVar{0};
    std::cout << globalVar << std::endl;
    std::cout << ::globalVar << std::endl;

return 0;
}
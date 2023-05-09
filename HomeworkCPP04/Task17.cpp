// Задача 17
// Дефинирайте функция, която принтира на стандартния изходен поток редицата на Фибоначи до зададен от потребителя
// индекс на число от редицата.
#include <iostream>
int fibionacciIndex(int x);

void printFibValueByIndex (int x)
{
    std::cout << fibionacciIndex(x);
} 

int fibionacciIndex(int x){
    if(x == 1 || x ==2){
        return 1;
    }
    return fibionacciIndex(x-1) + fibionacciIndex(x-2);
}
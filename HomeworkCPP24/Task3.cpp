// Задача 03
// Дефинирайте custom deleter функционалност за shared pointer класа.

#include <iostream>
#include <memory>
#include <functional>

int main(int argc, char const *argv[])
{
    auto customDeleter = [&](int* number) 
    {
        std::cout << *number << " destroyed \n";
        delete number;
        number = nullptr;    
    };
    
    {
        std::shared_ptr<int> ptr (new int(45), customDeleter);
    }
    return 0;
}
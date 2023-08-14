// Задача 02
// Дефинирайте custom deleter функционалност за unique pointer класа


#include <iostream>
#include <memory>
#include <functional>

int main(int argc, char const *argv[])
{
    auto customDeleter = [](int* number) 
    {
        std::cout << *number << " destroyed \n";
        delete number;
        number = nullptr;    
    };
    
    {
        std::unique_ptr<int, decltype(customDeleter)> ptr {new int(3), customDeleter};
    }
    return 0;
}

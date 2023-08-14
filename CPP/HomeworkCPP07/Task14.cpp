// Задача 14
// Напишете функция, за делене на две цели числа, която хвърля std::exception ако делимото е
// равно на 0. Прихванете exception-а в main.
#include <stdexcept>
#include <iostream>

float divide(float num, float divisor){
    
    if(divisor == 0){
        throw std::runtime_error("you can't divide on 0");
    }
    return num/divisor;
}

int main(){
    float a{0.0f},b{0.0f};
    std::cin >> a >>b;

    try
    {
        std::cout << divide(a,b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
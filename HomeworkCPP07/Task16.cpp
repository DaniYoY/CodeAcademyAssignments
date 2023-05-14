// Задача 16
// Напишете нова версия на предходната задача, в която хвърляте и std::invalid_argument ако
// аргументите имат различни знаци.


#include <stdexcept>
#include <iostream>

class ExceptionDivOnZero : public std::runtime_error
{
public:
    ExceptionDivOnZero() : runtime_error("You cannot divide by 0"){};
};


float divide(float num, float divisor){
    
    if(divisor == 0){
        throw ExceptionDivOnZero();
    }
    if(num*divisor < -1){
        throw std::invalid_argument("differently signed numbers");
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
    catch(ExceptionDivOnZero& e)
    {
        std::cerr << e.what() << '\n';
    }catch(std::invalid_argument & e){
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
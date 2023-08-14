// Задача 15
// Дефинирайте собствен тип за exception-a от предходната задача и използвайте него.
// Използвайте член данна за error съобщението, която се инициализира при хвърлянето и се
// принтира при прихващането на изключението.

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
    }
    
    return 0;
}
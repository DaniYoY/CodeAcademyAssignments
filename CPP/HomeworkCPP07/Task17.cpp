// Задача 17
// Напишете допълнителна функция за предходната задача, в която потребителят въвежда
// двойки делимо-делител и програмта извършва операцията в цикъл до грешка или въвеждане
// на EOF, използвайки функцията за делене.
// Прихванете exception-ите, хвърлени във функцията за делене от функцията с цикъла,
// принтирайте съобщение за грешка и rethrow-нете прихванатия exception, като добавите
// добълнителна информация.
// Прихванете rethrow-натия exception в main и принтирайте модифицираното съобщение за
// грешка.

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

bool processDivision(){
    float a{0.0f},b{0.0f};
    std::cin >> a >>b;

    try
    {
        std::cout << divide(a,b);
        return true;
    }
    catch(ExceptionDivOnZero& e)
    {
        std::cerr << e.what() << '\n';
    }catch(std::invalid_argument & e){
        std::cerr << e.what() << '\n';
    }
    
    return false;
}

int main(){
    while (processDivision() || std::cin.fail())
    {
        std::cout << std::endl;
    }
    
    return 0;
}
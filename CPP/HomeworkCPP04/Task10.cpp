// Задача 10
// Дефинирайте собствена версия на библиотечната функция pow от <cmath>, за повдигане на цяло число на дадена степен.

double power(int number, int exponent)
{
    double result  = number;
    if(exponent == 0) return 1;
    if(exponent < 0) {
        exponent *= -1;
        result = 1/result;    
    } 
    for (int i = 0; i < exponent; ++i)
        {
            result *= result; 
    }
    return result;    
}

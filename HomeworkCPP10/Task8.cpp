// Задача 08
// Дефинирайте функция за търсене на първата стойност в initializer_list от int, отговаряща на определен от клиента
// признак.
// Използвайте параметър от тип указател към функция. Използвайте using alias declaration за типа му.
// Тествайте с претърсване за първото четно и за първото отрицателно число в initializer_list обект.
#include <stdarg.h>
#include <iostream>
#include<initializer_list>
auto findFirstOcc(int targetNum,int numNextElements,...) -> bool{
    va_list list;
    va_start(list, numNextElements);
    
    for (size_t i = 0; i < numNextElements; i++)
    {
     if (va_arg(list,int) == targetNum)
    {
        return true;
    }
    }
    va_end(list);
    return false;
}

int main(int argc, char const *argv[])
{
    std::cout<< findFirstOcc(1,4,6,5,4,2,1);
    return 0;
}

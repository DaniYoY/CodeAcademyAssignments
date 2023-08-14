// Задача 11
// Напишете функция, която приема вектор от числа с плаваща запетая и втори параметър - число с плаваща
// запетая и размества стойностите в контейнера, така че всички елементи, които са равни на втория
// параметър да са открая, а редът на останалите елементи да не се променя.
// Примерни входни данни:
// {1.0, 2.0, 0.0, 1.0, 0.0, 3.0} , 0.0
// Очакван изход:
// {1.0, 2.0, 1.0, 3.0, 0.0, 0.0}
#include <vector>
#include <iostream>

std::vector<float> push_backElement(std::vector<float> & v, float num, int precision){
    std::vector<float> result;
    float epsilon {0.1f};
    for (int i = 0; i < precision; i++)
    {
        epsilon /= 10;
    }
    
    int counter{0}; 
    for (int i = 0; i < v.size(); i++)
    {

        if ((v[i]-num) < epsilon)
        {
            counter++;
        }else{
            result.push_back(v[i]);
        }
    }
    for (int i = 0; i < counter; i++)
    {
        result.push_back(num);
    }
    return result;
}

int main(){
    std::vector<float> test;
    test = {1.0, 2.0, 0.0, 1.0, 0.0, 3.0};
    test = push_backElement( test, 0.0, 2);
    for (float a : test)
    {
        std::cout << a<<" ";
    }
    
    return 0;
}
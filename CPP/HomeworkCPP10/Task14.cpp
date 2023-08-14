// Задача 14
// Пренапишете функцията от предходната задача, така че да работи с подмасиви с
// всякакъв брой елементи, както и да връща референция към "максималния" елемент на
// масива, където клиента може да дефинира какво значи "максимален", посредством
// указател към функция за сравняване на два елемента.
// Използвайте default стойност за указателя към финкция-параметър, равен на nullptr, в
// който случай под максимален се разбира този с най-голяма сума на елементите.
// C упражнителна цел, недейте да използвате alias declarations, а използвайте decltype.

#include<iostream>
#include<vector>

using func = double(*)(double * arr);

inline auto getBiggerNum(double a, double b) ->decltype(a < b){
    if (a > b)
    {
        return a;
    }
    return b;
}

double getBiggestNumer(double* arr) {
    double biggest{0}, interim{0};
    for (size_t i = 0; i < sizeof(arr)-1; i++)
    {
        interim = getBiggerNum(arr[i], arr[i+1]);
        biggest = getBiggerNum(interim, biggest); 
    }
    return biggest;
}


inline double sumArr(double* arr){
    double sum{0};

    for (int it = 0; it < sizeof(arr); it++)
    {
        sum += *(arr + it);
    }
    return sum;
}

double * getArrWithMax( double* arr[], int size, func f){
   
    double* result = nullptr;
    double* interim = nullptr;
    for (int i = 0; i<size-1; i++){
        double surCur = f(arr[i]);
        double surNxt = f(arr[i+1]);
        
        surCur > surNxt ? interim = arr[i] : interim = arr[i+1];
        
        if(result == nullptr) result = interim;

        if(f(result)< f(interim))  result = interim;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    double ar1[] = {1.0,1.0,10.0,1.0,1.0,1.0,1.0,1.0};
    double ar2[] = {1.1,1.1,1.1,1.1,1.1,1.1,1.1};
    double ar3[] = {4.0,8.0,8.0,8.0,4.0,4.0,4.0,4.0, 6.0};
    double ar4[] = {1.0,-1.0,-61.0};
    double* arr2[] = {ar1,ar2,ar3,ar4};

    int size1 = std::end(arr2) - std::begin(arr2);
    std::cout<< sumArr(getArrWithMax(arr2,size1, getBiggestNumer));    
    std::cout<< sumArr(getArrWithMax(arr2,size1, sumArr));    
    return 0;
}
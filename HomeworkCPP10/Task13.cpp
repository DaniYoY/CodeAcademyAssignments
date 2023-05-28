// Задача 13
// Напишете функция, която приема масив от подмасиви с по точно осем на брой
// елемента от тип double и връща референция към подмасива с най-голяма сума на
// елементите.

#include<iostream>

inline double sumArr(double* arr){
    double sum{0};
    for (int it = 0; it < 8; it++)
    {
        sum += *(arr + it);
    }
    return sum;
}

double * getArrWithMaxSum( double* arr[8], int size){
    double* result = nullptr;
    double* interim = nullptr;
    for (int i = 0; i<size-1; i++){
        double surCur = sumArr(arr[i]);
        double surNxt = sumArr(arr[i+1]);
        
        surCur > surNxt ? interim = arr[i] : interim = arr[i+1];
        
        if(result == nullptr) result = interim;

        if(sumArr(result)< sumArr(interim))  result = interim;
    }
    // for (double ** it = arr; *(*(it+2)) != 0; it++)
    // {
    //     sumArr(*it) > sumArr(*(it+1)) ? interim = *it : interim = *(it+1);
        
    //     if(result == nullptr) result = interim;

    //     if(sumArr(result)< sumArr(interim))  result = interim;
        
    // }
    return result;
}

int main(int argc, char const *argv[])
{
    double ar1[] = {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};
    double ar2[] = {1.1,1.1,1.1,1.1,1.1,1.1,1.1,1.1};
    double ar3[] = {4.0,4.0,4.0,4.0,4.0,4.0,4.0,4.0};
    double ar4[] = {1.0,1.0,1.0,1.0,4.0,4.0,4.0,4.0};
    double* arr2[8] = {ar1,ar2,ar3,ar4};
    std::cout<< sumArr(getArrWithMaxSum(arr2, 4));    
    return 0;
}


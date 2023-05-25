// Задача 01
// Напишете програма за сравняване на два двумерни масива от float с еднакви размери. Използвайте параметър за
// допустимата грешка при сравнение с default аргумент.

#include <iostream>
#include<cmath>
#include<vector>

int compare(float n1, float n2,unsigned int precision){
     float epsilon {0.1f};
    for (int i = 0; i < precision; i++)
    {
        epsilon /= 10;
    }
    
    if (std::abs(n1 -n2) < epsilon)
    {
        return 0;
    }
    if (n1>n2)
    {
        return 1;
    }
    
    return -1;
}

void compFloatArrs(const float (&arr1)[3][3],const  float (&arr2)[3][3],size_t rows, size_t cols, int precision =3){
    bool result{false};
   
    for (size_t i =0; i<rows; i++)
    {
        for (size_t j =0; j<cols; j++)
        {
            std::cout << compare(arr1[i][j],arr2[i][j], precision);
        }
        std::cout<<std::endl;
    }
}

int main(int argc, char const *argv[])
{        
    float arr1[3][3] = { {0.005f,0.3f,0.06f},
                        {8.005f,2.3f,0.7f},
                        {0.009f,0.03f,0.00006f}};
    float arr2[3][3] = { {0.004f,0.8f,0.06f},
                       {8.005f,1.3f,2.7f},
                       {0.0009f,7.03f,0.00009f}};

    compFloatArrs(arr1,arr2,3,3);
    return 0;
}


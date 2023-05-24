// Задача 19
// Напишете функция, която приема 2д масив от указатели към c-string-ове и проверява дали индекса на колоната на всеки стринг е равен на броя на
// символите му (без нул терминатора) - 1

#include <iostream>

bool isIndxEqualToLen(const char** arr, size_t rows, size_t cols){
    
    for (size_t row = 0; row < rows; row++)
    {
        for (size_t col = 0;col <cols ; col++)
        {
            if (arr[row][col+1] == '\0')
            {
                if (row != col)
                {
                    return false;
                }
                break;          
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    const char* arr[20] ={
        "0",
        "01",
        "012"
    };
    std::cout << isIndxEqualToLen(arr,3,3);
    return 0;
}


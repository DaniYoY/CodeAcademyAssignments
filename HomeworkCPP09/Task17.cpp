// Задача 17
// Напишете функция, която принтира спираловиден шаблон n x n в конзолата с цифрите от 0 до 9, като след 9 следва 0. Спиралата трябва да
// започва от горния ляв ъгъл и да се движи по посока на часовниковата стрелка. Приемайте n по командния ред (като аргумент на main).
// Например, при n = 4:
// 0123
// 1234
// 0545
// 9876

#include <iostream>
#include <vector>

int getUpdatedDigit(int & digit, const int & base){
    digit++;
    digit %= base;
    return digit;
}

std::vector<std::vector<int>> createFilledArrOnInput()
{
    int n{0};
    std::cout << "Please enter n to generate n x n square" << std::endl;
    std::cin >> n;
    std::vector<int> temp(n,0);
    std::vector<std::vector<int>> arr(n,temp);
    size_t rowBeg{0}, rowEnd{0}, colBeg{0}, colend{0};
    rowEnd = static_cast<size_t>(n-1);
    colend =static_cast<size_t>(n-1);
    int direction{3}, digit{9};
    int numberOfDigits{10};
    int numberOfDirections{4};

    for (int i = 0; i < (n*n);)
    {
        switch (getUpdatedDigit(direction, numberOfDirections))
        {
            // left to right
        case 0:
            for (size_t l2r = colBeg; l2r <= colend; l2r++,i++)
            {
                arr[rowBeg][l2r] = getUpdatedDigit(digit, numberOfDigits);
            }
            rowBeg++;
            break;
            // up to down
        case 1:
            for (size_t u2d = rowBeg; u2d <= rowEnd; u2d++,i++)
            {
                arr[u2d][colend] = getUpdatedDigit(digit, numberOfDigits);
            }
            colend--;
            break;
            // right to left
        case 2:
            for (size_t r2l = colend; r2l != colBeg; r2l--,i++)
            {
                arr[rowEnd][r2l] = getUpdatedDigit(digit, numberOfDigits);
            }
                arr[rowEnd][colBeg] = getUpdatedDigit(digit, numberOfDigits);
            rowEnd--;
            i++;
            break;
            // down to up
        case 3:
            for (size_t d2u = rowEnd; d2u != rowBeg; d2u--,i++)
            {
                arr[d2u][colBeg] = getUpdatedDigit(digit, numberOfDigits);
            }
                arr[rowBeg][colBeg] = getUpdatedDigit(digit, numberOfDigits);
            colBeg++;
            i++;
            break;
        }
    }
    return arr;
}

void printCharMatrix(std::vector<std::vector<int>> v){
    for (size_t i = 0; i < v.size(); i++, putchar('\n'))
    {
        for (size_t j = 0; j < v[i].size(); j++)
        {
            std::cout << v[i][j];
        }   
    }  
}

int main(int argc, char const *argv[])
{
    printCharMatrix(createFilledArrOnInput());
    return 0;
}


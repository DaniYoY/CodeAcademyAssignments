// Задача 18
// Напишете функция, която принтира спираловиден шаблон n x n в конзолата със '*', където n е нечетно число, по-голямо от 3. Спиралата трябва да
// започва от горния ляв ъгъл и да се движи по посока на часовниковата стрелка. Приемайте n по командния ред (като аргумент на main).
// Например, при n = 5:
// *****
// *
// *** *
// * *
// *****

#include <iostream>
#include <vector>

int getUpdatedDigit(int &digit, const int &base)
{
    digit++;
    digit %= base;
    return digit;
}

 int setNumberFromConsole(){
    int n{0};
    std::cout << "Please enter n to generate n x n square" << std::endl;
    std::cin >> n;
    if (n % 2 == 0 || n < 3)
    {
        std::cout << "n can'y be even nor less than 3 and not it will be 3" << std::endl;
        n = 3;
    }
    return n;
}

std::vector<std::vector<char>> createFilledArrOnInput()
{
    int n{0};
    n= setNumberFromConsole();

    std::vector<char> temp(n, ' ');
    std::vector<std::vector<char>> arr(n, temp);
    size_t rowBeg{0}, rowEnd{0}, colBeg{0}, colend{0};
    rowEnd = static_cast<size_t>(n - 1);
    colend = static_cast<size_t>(n - 1);
    // starts at max value - 3, because called function will set it to 0 
    int direction{3};
    // left, right, up, down
    int numberOfDirections{4};

    for (int i = 0; i < (n * n);)
    {
        switch (getUpdatedDigit(direction, numberOfDirections))
        {
            // left to right
            
        case 0:
         //after the first 2 cycles, colBeg (index for begin of columns) is 2, but we need to link it to prev cycle, hence decrementing 
            for (size_t l2r = (colBeg == 0 ? 1 : colBeg)-1; l2r <= colend; l2r++, i++)
            {
                if (rowBeg % 2 == 0)
                {
                    arr[rowBeg][l2r] = '*';
                }
            }
            rowBeg++;
            break;
            // up to down
        case 1:
            for (size_t u2d = rowBeg; u2d <= rowEnd; u2d++, i++)
            {
                if (colend % 2 == 0)
                {
                    arr[u2d][colend] = '*';
                }
            }
            colend--;
            break;
            // right to left
        case 2:
            for (size_t r2l = colend; r2l >= colBeg; r2l--, i++)
            {
                if (rowEnd % 2 == 0)
                {
                    arr[rowEnd][r2l] = '*';
                    //  check due to overflow issue and requirement to break at 0, this will happen on 1st cycle
                    if (r2l ==0)
                    {
                        break;
                    }
                }
            }
            rowEnd--;
            i++;
            break;
            // down to up
        case 3:
            for (size_t d2u = rowEnd; d2u > rowBeg; d2u--, i++)
            {
                if (colBeg % 2 == 0)
                {
                    arr[d2u][colBeg] = '*';
                }
            }
            colBeg++;
            i++;
            break;
        }
    }
    return arr;
}

void printCharMatrix(std::vector<std::vector<char>> v)
{
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
#include <iostream>

unsigned long long int conversionToMax(int digitsCount, int baseNum, int decimalNumber){

    unsigned long long int result{decimalNumber};
    if (digitsCount == 0){
        return 0;
    }
    
    // result = decimalNumber;
    for (size_t i = 2; i <= digitsCount; i++)
    {
        result += (unsigned long long int) decimalNumber*baseNum;
        decimalNumber *= baseNum; 
    }
    return result;
}

int main (){
using namespace std;
    char base{' '};
    int digitsCount{0}, decimalNumber{0}, baseNum{0};
    unsigned long long int number;
    cout << "Please intert base as a letter (b,d,o,x) and number of digits ";
    cin >> base >>digitsCount;
    switch (base)
    {
    case 'b':
    case 'B':
        decimalNumber = 1;
        baseNum = 2;
        break;
    case 'o':
    case 'O':
        decimalNumber = 7;
        baseNum = 8;
        break;
    case 'd':
    case 'D':
        decimalNumber = 9;
        baseNum = 10;
        break;
    case 'x':
    case 'X':
        decimalNumber = 15;
        baseNum = 16;
        break;
    default:
        cout << "Invalid input" << endl;
        break;
    }
    number = conversionToMax(digitsCount, baseNum, decimalNumber);
    cout << "Biggest number of " << base <<" base with " << digitsCount << " digits is " << number << endl;
    return 0;
}
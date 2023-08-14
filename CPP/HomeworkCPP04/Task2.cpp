// Задача 02
// Напишете функция swap, която сменя стойностите на двата си аргумента от тип int.

void swapValues(int numA, int numB)
{
    int temp{numA};
    numA = numB;
    numB = temp;
    return;
}
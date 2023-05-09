// адача 19
// Дефинирайте функция, която може да пресметне шансовете да спечелим от тотото, например 6 от 49 (6 и 49 трябва
// да могат да се подават като аргументи). Използвайте factorial функцията за да пресметнете шанса да спечелите по
// формулата за комбинация (всяка топка има уникален номер и поредността на теглене няма значение):
//  C = n!/r!(n-r)! 
//  C - number of combinations, n - total number of objects, r - number of choosing objects from the set


long long factorial (int x);

double calculateChance(int numOfChoosings, int numOfObjects){

    return (double) factorial(numOfObjects)/(factorial(numOfChoosings)*factorial(numOfObjects - numOfChoosings));
}

long long factorial (int x){
    long long result = x;
    for (int i = x; i >= 1; --i)
    {
         result *=i;
    }
    return result;
}

// Задача 16
// Дефинирайте функция, която по зададен индекс в редицата на Фибоначи, връща числото от редицата, съответстваща на
// подадения индекс. Използвайте итеративен алгоритъм (ползвайте цикъл, вместо рекурсия).

int fibonacciIndex (int x)
{
    int result {1};
    int previous {1};
    int secondPrevious {1};
    for (int i = 3; i <= x; i++)
    {
        result = previous + secondPrevious;
        secondPrevious = previous;
        previous = result; 
    }
    return result;
    
}
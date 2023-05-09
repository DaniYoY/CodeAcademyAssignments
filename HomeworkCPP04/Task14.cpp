// Задача 14
// Дефинирайте функция за ограничаване на float число отдолу и отгоре (range), използвайки функциите от предходните задачи

float clampHigh (float x, float upperBorder)
{
    return x > upperBorder ? upperBorder : x;
}

float clampLow (float x, float lowerBorder)
{
    return x < lowerBorder ? lowerBorder : x;
}

float clampInRange (float x, float lowerBorder, float upperBorder)
{
   return clampHigh(clampLow(x, lowerBorder), upperBorder); 
}
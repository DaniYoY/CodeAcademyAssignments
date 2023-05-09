// Задача 13
// Дефинирайте функция за ограничаване (clamp-ване) на float число отдолу, работеща по сходен принцип на функцията от
// предходната задача.

float clampLow (float x, float lowerBorder)
{
    return x < lowerBorder ? lowerBorder : x;
}
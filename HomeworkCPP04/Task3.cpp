// Задача 03
// Дефинирайте функция за сравняване на две float стойности дали са “равни” (достатъчно близки по стойност).
// Използвайте библиотечната функция std::abs от <cmath>:
// https://en.cppreference.com/w/cpp/numeric/math/fabs

#include <cmath>

bool equalsFloatAbsoluteValue(float numA, float numB)
{
    return std::abs(numA) == std::abs(numB);
}
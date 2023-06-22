// Задача 05
// Напишете функция, преброява множествата точки в равнината, които са близо една до
// друга. Приемайте всички точки с iterator range. Използвайте параметър с default стойност,
// специфициращ допустимата грешка.

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

struct Point
{
    float x;
    float y;
    Point(float xVal, float yVal): x{xVal},y{yVal}{};
};

int countInRange (Point startingPoint, std::vector<Point>& points, int range =5){
    return std::count_if(points.begin(),points.end(),
    [&](Point a){
        float absX{0.0f}, absY{0.0f};
        absX = abs(a.x) - abs(startingPoint.x);
        absY = abs(a.y) - abs(startingPoint.y);
        return sqrt(pow((absX),2) + pow(absY,2))<= range;
    });
}

int main(int argc, char const *argv[])
{
     std::vector<Point> points{Point(0.0,0.0),Point(-1.0,6.0),Point(-6.0,-10.0),Point(4.0,-5.0),Point(0.7,0.5),Point(10.0,20.0),Point(-50.0,-90.0)
     ,Point(10.0,10.0),Point(11.0,11.0),Point(11.0,12.0),Point(10.0,13.0),Point(10.0,15.0)};
    Point p{10,10};
     std::cout<< countInRange(p,points,90);
    return 0;
}

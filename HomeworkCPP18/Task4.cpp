// Задача 04
// Напишете програма, която сортира списък с точки в равнината (клас с 2 член данни: float
// x и float у за координатите на точката) по дистанция от точката с координати (0,0). Съвет:
// сортирайте по дистанцията, повдигната на квадрат, за да избегнете sqrt.

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

int main(int argc, char const *argv[])
{
    std::vector<Point> points{Point(0.0,0.0),Point(-1.0,6.0),Point(-6.0,-10.0),Point(4.0,-5.0),Point(0.7,0.5),Point(10.0,20.0),Point(-50.0,-90.0)};
    std::sort(points.begin(),points.end(),
    [](Point a, Point b){
        float distanceA{0.0f}, distanceB{0.0f};
        distanceA = sqrt(pow(a.x,2) + pow(a.y,2));
        distanceB = sqrt(pow(b.x,2) + pow(b.y,2));
        return distanceA < distanceB;
    });
    for (Point iter : points)
    {
        std::cout << iter.x << ' ' << iter.y << std::endl;
    }
    
    return 0;
}


// Задача 04
// Напишете template функция за сравнение на двa Point2d обекта, която сравнява техните x и y членове.
// Напишете специализации сравняване на floating-point инстанции на членовете.a

#include<iostream>
template <class T> class Point2d{
    static float floatingPointPrecision;
public:
    static void setPrecision(int num){ for (size_t i = 0; i < num; i++) { floatingPointPrecision /= 10;}}
    T x;
    T y;
    Point2d() : x{0}, y{0} {};
    Point2d(T a, T b) : x{a}, y{b} {};
    static int compare(const Point2d& p1,const Point2d& p2)
    {
        if ((p1.x < p2.x && p1.y <= p2.y) || (p1.x <= p2.x && p1.y < p2.y))
        {
            return -1;
        }
        if (p2.x < p1.x && p2.y <= p1.y)
        {
            return 1;
        }
        return 0;
    }
};
template<typename T> float Point2d<T>:: floatingPointPrecision {1.0f};
template<> int Point2d<float>::compare(const Point2d& p1,const Point2d& p2)
{
    float epsilon = 0.1 * floatingPointPrecision;
    float epsilonX = p2.x - p1.x;
    float epsilonY = p2.y - p1.y;
    if (epsilonX < epsilon && epsilonY <= epsilon)
    {
        return 0;
    }
    if ((p1.x < p2.x && p1.y <= p2.y) || (p1.x <= p2.x && p1.y < p2.y))
        {
            return -1;
        }    
    return 1;
}

int main(int argc, char const *argv[])
{
    int a{1};
    int b{2};
    int c{3};
    int d{4};
    float q{0.1f};
    float q1{0.0001f};
    float w{0.2f};
    float w1{0.0002f};
    float e{0.3f};
    float e1{0.0003f};
    float r{0.4f};
    float r1{0.0004f};
    std::cout << Point2d<int>::compare(Point2d(c,d), Point2d(a,b)) << std::endl; //1
    std::cout << Point2d<float>::compare(Point2d(q,w), Point2d(e,r)) << std::endl;//-1
    std::cout << Point2d<float>::compare(Point2d(q1,w1), Point2d(e1,r1)) << std::endl;//0
    Point2d<float>::setPrecision(6);
    std::cout << Point2d<float>::compare(Point2d(q1,w1), Point2d(e1,r1)) << std::endl;//-1
    return 0;
}

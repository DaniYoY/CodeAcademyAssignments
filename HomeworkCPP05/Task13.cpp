// Задача 13
// Дефинирайте клас за координати на точка в равнината.
// Дефинирайте клас за правоъгълник в равнината.
// Дефинирайте функции за следните операции:
// ● Въвеждане и принтиране на данните за правоъгълник.
// ● Изчисляване на лицето и периметъра на правоъгълника.

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Point
{
public:
    int x;
    int y;
    Point();
    Point(int a,int b);
    ~Point();
};

Point::Point(int a, int b)
{
    x = a;
    y = b;
};
Point::Point(){
    x=0;
    y=0;
};
Point::~Point()
{
};

class Rect
{
public:
    Point a;
    Point b;
    Point c;
    Point d;
    Rect(int x1, int x2, int y1, int y2);
    ~Rect();
};

Rect::Rect(int x1, int x2, int y1, int y2)
{
    Point p1 = Point(x1,y1);
    Point p2 = Point(x1,y2);
    Point p3 = Point (x2,y2);
    Point p4 = Point (x2,y1);
    a = p1;
    b = p2;
    c = p3;
    d = p4;
};

Rect::~Rect()
{
};

Rect makeRect(){
    int x1{0};
    int x2{0};
    int y1{0};
    int y2{0};
    std::cout << "Please enter lower X axis"<<std::endl;
    std::cin >> x1;
    std::cout << "Please enter upper X axis"<<std::endl;
    std::cin >> x2;
    std::cout << "Please enter left Y axis"<<std::endl;
    std::cin >> y1;
    std::cout << "Please enter right Y axis"<<std::endl;
    std::cin >> y2;
    Rect r = Rect(x1, x2, y1, y2);
    std::cout<< "Rectangular ABCD was created with coordinates A(" <<r.a.x<<", "<<r.a.y<<") and C("<<r.c.x<<", "<<r.c.y<<")"<<std::endl;  
    return r;
};

void calculatePerAndArea(const Rect & rect){
    int xSide{0};
    int ySide{0};
    if((rect.a.x >= 0 && rect.c.x >=0) ||(rect.a.x <= 0 && rect.c.x <=0) ){
        xSide = std::abs(rect.a.x - rect.c.x);
    }else{
        xSide = std::abs(rect.a.x) + std::abs(rect.a.x); 
    }

    if((rect.a.y >= 0 && rect.b.y >=0) ||(rect.a.y <= 0 && rect.b.y <=0) ){
        ySide = std::abs(rect.a.y - rect.b.y);
    }else{
        ySide = std::abs(rect.a.y) + std::abs(rect.b.y); 
    }

    std::cout<< "Perimeter is " << 2*(ySide + xSide) << " and area is "<< ySide*xSide<< std::endl;
    return;
};
int main(){
    Rect r =makeRect();
    calculatePerAndArea(r);
    return 0;
}



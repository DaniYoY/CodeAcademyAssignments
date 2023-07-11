#include "Triangle.hpp"
#include "Square.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"

#include<vector>
#include<iostream>
#include<algorithm>

int main()
{
    Triangle a(2,3,5,6);
    Rectangle b(9,8);
    Square c(6);
    Circle d(7);

    std::vector<Shape*> vec;
    vec.push_back(&a);
    vec.push_back(&b);
    vec.push_back(&c);
    vec.push_back(&d);

    std::for_each(vec.begin(), vec.end(), [](Shape* ptr)
    
    {std::cout << "Area is " << ptr->calculateArea() << " and parameter is " << ptr->calculateParameter() << std::endl;});

  std::for_each(vec.begin(), vec.end(), [](Shape* ptr)
    
    { ptr->deserialize(std::cout);});

    return 0;
}

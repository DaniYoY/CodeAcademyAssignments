#ifndef CIRCLE_H
#define CIRCLE_H

#include"Shape.hpp"

class Circle : public Shape
{
private:
    const double  PI = 3.14;
    double m_radius;
public:
    Circle() : m_radius{0} {};
    Circle(double radius) : m_radius{radius} {};
    ~Circle(){};
    double calculateParameter() override { return m_radius *2 * PI; };
    double calculateArea() override {return m_radius*m_radius*PI;};
    void serialize(std::istream& s) override { s >> m_radius;};
    void deserialize(std::ostream& s) override { s << m_radius << ' ';};
};


#endif
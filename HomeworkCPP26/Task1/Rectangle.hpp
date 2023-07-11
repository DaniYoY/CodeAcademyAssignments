#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.hpp"

class Rectangle : public Shape
{
private:
    double m_side_a;
    double m_side_b;

public:
    Rectangle() : m_side_a{0}, m_side_b{0} {};
    Rectangle(double a, double b) : m_side_a{a}, m_side_b{b} {};
    ~Rectangle(){};
    double calculateParameter() override { return (m_side_a + m_side_b) * 2; };
    double calculateArea() override { return m_side_a * m_side_b; };
    void serialize(std::istream &s) override { s >> m_side_a >> m_side_b; };
    void deserialize(std::ostream &s) override { s << m_side_a << ' ' << m_side_b << ' '; };
};


#endif
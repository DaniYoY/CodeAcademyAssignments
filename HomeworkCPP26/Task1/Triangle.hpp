#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.hpp"

class Triangle : public Shape
{
private:
    double m_side_a;
    double m_side_b;
    double m_side_c;
    double m_side_ha;

public:
    Triangle() : m_side_a{0}, m_side_b{0}, m_side_c{0}, m_side_ha{0} {};
    Triangle(double a, double b, double c, double ha) : m_side_a{a}, m_side_b{b},m_side_c{c}, m_side_ha{ha}  {};
    ~Triangle(){};
    double calculateParameter() override { return m_side_a + m_side_b + m_side_c; };
    double calculateArea() override { return m_side_a * m_side_ha /2; };
    void serialize(std::istream &s) override { s >> m_side_a >> m_side_b >> m_side_c >> m_side_ha; };
    void deserialize(std::ostream &s) override { s << m_side_a << ' ' << m_side_b << ' ' << m_side_c << ' ' << m_side_ha << ' '; };
    };

#endif
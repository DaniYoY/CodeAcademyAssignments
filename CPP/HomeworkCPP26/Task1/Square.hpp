#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.hpp"

class Square :public Shape
{
private:
    double m_side;
public:
    Square() : m_side{0} {};
    Square(double side) : m_side{side} {};
    ~Square(){};
    double calculateParameter() override { return m_side *4; };
    double calculateArea() override {return m_side*m_side;};
    void serialize(std::istream& s) override { s >> m_side;};
    void deserialize(std::ostream& s) override { s << m_side << ' ';};
};

#endif
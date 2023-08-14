#ifndef SUBSTRACTION_H
#define SUBSTRACTION_H

#include "Command.hpp"

class Substraction : public Command
{
private:
    double a, b;
public:
    Substraction(): a{0},b{0} {};
    Substraction(double num): a{num},b{0} {};
    Substraction(double x, double y): a{x},b{y} {};
     ~Substraction() = default;
    double execute() override {return a - b;};
    void serialize(std::istream& s) override { s >> a >> b; };
    void deserialize(std::ostream& s) override { s << a << ' ' << b << ' '; };
};

#endif
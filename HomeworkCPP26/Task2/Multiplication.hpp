#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "Command.hpp"

class Multiplication : public Command
{
private:
    double a, b;
public:
    Multiplication(): a{0},b{1} {};
    Multiplication(double num): a{num},b{1} {};
    Multiplication(double x, double y): a{x},b{y} {};
     ~Multiplication() = default;
    double execute() override {return a*b;};
    void serialize(std::istream& s) override { s >> a >> b; };
    void deserialize(std::ostream& s) override { s << a << ' ' << b << ' '; };
};

#endif
#ifndef ADDITION_H
#define ADDITION_H

#include "Command.hpp"

class Addition : public Command
{
private:
    double a, b;
public:
    Addition(): a{0},b{0} {};
    Addition(double num): a{num},b{0} {};
    Addition(double x, double y): a{x},b{y} {};
     ~Addition() = default;
    double execute() override {return a + b;};
    void serialize(std::istream& s) override { s >> a >> b; };
    void deserialize(std::ostream& s) override { s << a << ' ' << b << ' '; };
};

#endif
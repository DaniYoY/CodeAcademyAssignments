#ifndef DIVISION_H
#define DIVISION_H

#include "Command.hpp"

class Division : public Command
{
private:
    double a, b;
public:
    Division(): a{0},b{1} {};
    Division(double num): a{num},b{1} {};
    Division(double x, double y): a{x},b{y} {};
     ~Division() = default;
    double execute() override {return a/b;};
    void serialize(std::istream& s) override { s >> a >> b; };
    void deserialize(std::ostream& s) override { s << a << ' ' << b << ' '; };
};

#endif
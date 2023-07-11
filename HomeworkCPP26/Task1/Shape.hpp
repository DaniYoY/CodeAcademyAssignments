#ifndef SHAPE_H
#define SHAPE_H

#include "Serializable.hpp"

class Shape : public Serializable
{   
public:
    Shape(){};
    virtual ~Shape() = default;
    virtual double calculateParameter() = 0;
    virtual double calculateArea() = 0;
};

#endif

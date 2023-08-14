#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <iostream>

class Serializable
{
private:
    
public:
    Serializable(){};
    virtual ~Serializable() = default;
    virtual void serialize(std::istream&) = 0;
    virtual void deserialize(std::ostream&) = 0;
};

#endif
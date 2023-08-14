#ifndef COMMAND_H
#define COMMAND_H

#include "Serializable.hpp"

class Command : public Serializable
{
private:
    
public:
    Command(){};
    virtual ~Command() = default;
    virtual double execute() =0;
};



#endif
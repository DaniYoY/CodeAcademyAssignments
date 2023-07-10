#ifndef GAME_HPP
#define GAME_HPP
#include "Serializable.hpp"
class Game : public Serializable
{
private:
    /* data */
public:
    Game(){};
    virtual ~Game() {};
    virtual void run() = 0;
};



#endif
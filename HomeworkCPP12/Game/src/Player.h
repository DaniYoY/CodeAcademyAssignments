#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>

class Player
{
private:
    char m_playSign;  
    int m_moves;  
    std::string m_name;
public:
    Player();
    Player(const std::string & name);
    Player(const std::string & name, char sign);
    const std::string & getName() const;
    const int getMoves() const;
    const char getPlaySign() const;
    void setMoves(int m);
    void setName(const std::string & newName);
    void setPlaySign(char c);
};

#endif

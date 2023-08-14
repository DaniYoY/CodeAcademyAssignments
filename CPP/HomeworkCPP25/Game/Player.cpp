#include "Player.hpp"

#include <iostream>
#include <vector>
#include <string>

// constructirs

    Player::Player() : m_moves(0), m_name("newName"), m_playSign(' ')
    {
    }
    Player::Player(const std::string & name) : m_moves(0), m_name(name), m_playSign(' ')
    { 
    }
    Player::Player(const std::string & name, char sign) : m_moves(0), m_name(name), m_playSign(sign)
    {
    }

// getters

const std::string & Player::getName() const{
    return this->m_name;
}

const int Player::getMoves() const{
    return this->m_moves;
}
const char Player::getPlaySign() const{
    return this->m_playSign;
}

// setters

void Player::setMoves(int m){
    this->m_moves = m;
}

void Player::setName(const std::string & newName){
    this->m_name = newName;
}
void Player::setPlaySign(char c){
    this->m_playSign = c;
}

std::ostream& operator<<(std::ostream& s,const Player & p)
{
    s << p.m_playSign << ' ' << p.m_moves << ' ' << p.m_name << ' ';
}

std::istream& operator>>(std::istream& s, Player & p)
{
    s >> p.m_playSign >> p.m_moves >> p.m_name;
}
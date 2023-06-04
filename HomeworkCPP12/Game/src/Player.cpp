#include "Player.h"

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

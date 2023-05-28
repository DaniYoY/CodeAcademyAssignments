// #pragma once

#include<string>
#include<iostream>

class Hangman{
   private: 
    static const unsigned int m_RegLives = 10;
   
   private:
    unsigned int m_lives;
    bool m_isEnded;
    std::string m_description;
    std::string m_word;
    std::string m_attempts;
    std::string m_info;
public:
    Hangman();
    
    // getters

    unsigned int getLives() const;
    const bool hasEnded() const;
    const std::string & getDescription() const;
    const std::string & getWord() const;
    const std::string & getAttempts() const;
    const std::string & getInfo() const;
    
    // setters

    void setLives(unsigned int newLives = m_RegLives);
    void setDescription(const std::string & newDescription);
    void setAttemps(const std::string & newAttempts);
    void setAttemps(const char & a);
    void setInfo(const std::string & newInfo);
    void updateInfo(int i, char a);
    void setWord(const std::string & newWord);
    void setStatus(const bool a);
    // related to game logic 

    void setHangmanan();
    void printInfo();
    void checkTrial(const std::string & trial);
    void play();
    void playNew();
    bool checkWin();
};

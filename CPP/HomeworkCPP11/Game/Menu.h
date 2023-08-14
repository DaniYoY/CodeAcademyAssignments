

#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "TicTacToe.h"
#include "Hangman.h"

class Menu
{
private:
    bool m_isClosing;
    bool m_StartFromBegin;
    std::vector<TicTacToe> tttGames;
    std::vector<Hangman> hmGames;
    Player m_player;
    
public:
    Menu();
    
    void run();

private:

    void greetPlayer();
    void accessTTTgame(std::vector<TicTacToe> & allGames);
    void accessHMgame(std::vector<Hangman> & allGames);
    void printMainMenu();
    void startMainMenu();
    
};



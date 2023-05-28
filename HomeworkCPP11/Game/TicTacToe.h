// #pragma once

#include "Player.h"
#include <iostream>
#include <vector>
#include <string>

class TicTacToe
{
private:
    inline static const char loserChar = {' '};
    inline static const int standardSize = 3;
private:
    bool m_isEnded;
    std::vector<Player> m_players;
    std::vector<std::vector<int>> m_gameMap;
    std::vector<std::vector<char>> m_gameProgress;
    
public:
    TicTacToe();
    void createGameTable();
    void play();
    void get();
    void playNew();

    // getters
    
    const std::vector<Player> & getPlayers() const;
    const std::vector<std::vector<int>> & getGameMap() const;
    const std::vector<std::vector<char>> & getGameProgress() const;
    const bool hasEnded() const;

    // setters

    void setPlayers();
    void setGameMap(int n = standardSize);
    void setGameProgress(int n = standardSize);
    void updateGameProgress(int row, int col, char c);
    void setStatus(bool status);
    void addPlayer(Player p);
private:

// methods for making moves

    void printProgressTable();
    Player & determineNextPlayer();
    bool takeWinningPosition();

 // methods for checking game state (won or continuing)  

    bool checkForWinningRow(int row, int col);
    bool checkForWinningCol(int row, int col);
    bool checkForWinningDioganalUL2DR(int row, int col);
    bool checkForWinningDioganalDL2UR(int row, int col);
    bool checkForWin(int row, int col);
    bool isStaleEnd();

};

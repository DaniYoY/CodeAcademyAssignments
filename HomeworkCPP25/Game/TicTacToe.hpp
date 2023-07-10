#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>
#include <string>
#include"Player.hpp"
#include"Game.hpp"


class Player;
class TicTacToe : public Game
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
    
    void run() override;
    void serialize(std::istream& s) override;
    void deserialize(std::ostream& s) override;

    friend std::ostream& operator<<(std::ostream& s,const TicTacToe & h);
    friend std::istream& operator>>(std::istream& s, TicTacToe & h);

private:
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

#endif

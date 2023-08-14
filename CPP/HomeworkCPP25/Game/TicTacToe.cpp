#include "TicTacToe.hpp"
#include "Player.hpp"

TicTacToe::TicTacToe()
{
    this->m_isEnded = false;
}
    
// getters

    const std::vector<Player> & TicTacToe::getPlayers() const{
        return this->m_players;
    }
    const std::vector<std::vector<int>> & TicTacToe::getGameMap() const{
        return this->m_gameMap;
    }
    const std::vector<std::vector<char>> & TicTacToe::getGameProgress() const{
        return this->m_gameProgress;
    }
    const bool TicTacToe::hasEnded() const{
        return this->m_isEnded;
    }

// setters

    void TicTacToe::addPlayer(Player p){
        m_players.push_back(p);
    }
    void TicTacToe::setPlayers(){
        for (int i = 1; i <= 2; i++)
        {
            std::string name{""};
            char sign{' '};
            std::cout << "please enter player  " << i <<" details :\n Name: ";
            std::cin >> name;
            std::cout << std::endl << "And now a sign for playing: "<< std::endl;
            std::cin >> sign;
            Player p = Player(name, sign);
            std::cout << p.getName() << " will play with char "<< p.getPlaySign()<< std::endl;
        
            if (!getPlayers().empty() && (p.getPlaySign() == getPlayers()[0].getPlaySign() || p.getName() == getPlayers()[0].getName()))
            {
                std::cout<< "player cannot have same sign nor name as the first! Please choose another." << std::endl;
                --i;
                continue;
            }
        addPlayer(p);
    }
    }
    void TicTacToe::setGameMap(int n){
    std::vector<std::vector<int>> gameMap(n);
        int pos{0};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cout<< "| " << ++pos <<" |";
                gameMap[i].push_back(pos); 
            }
            std::cout << std::endl;
        }

        this->m_gameMap = gameMap;
    }
    void TicTacToe::setGameProgress(int n){
        std::vector<std::vector<char>> gameProgress(n);
        for (int i = 0; i < n; i++)
        {
            std::vector<char> lines (n, loserChar);
            gameProgress[i] =lines;
        }
        this->m_gameProgress = gameProgress;
    }
    void TicTacToe::updateGameProgress(int row, int col, char c){
        this->m_gameProgress[row][col] = c;
    }
    void TicTacToe::setStatus(bool status){
        this->m_isEnded = status;
    }

// methods for boards and game creation
void TicTacToe::createGameTable(){
    int n{0};
    std::cout << "Please choose how big the square should be (submit number)" <<std::endl;
    std::cin >> n;
    setGameMap(n);
    setGameProgress(n);
    return;
}

// methods for making moves

void TicTacToe::printProgressTable(){
    for (int i = 0; i < getGameMap().size(); i++)
    {
        for (int j = 0; j < getGameMap().size(); j++)
        {
            if (getGameProgress()[i][j] != loserChar)
            {
                 std::cout<< getGameProgress()[i][j] <<" | ";
            }else{
                 std::cout<< getGameMap()[i][j] <<" | ";
            }
        }
        std::cout<< std::endl;
    }
};
Player & TicTacToe::determineNextPlayer() {
    if (getPlayers()[0].getMoves() == getPlayers()[1].getMoves())
    {
        return const_cast<Player &> (getPlayers()[0]);
    }
    return const_cast<Player &> (getPlayers()[1]);
 }
bool TicTacToe::takeWinningPosition(){
    int pos{0}, row{0}, col{0};
    Player & p = determineNextPlayer();
    //  making move
     while(true){
        std::cout<< "By choosing -1 will stop the game" << std::endl;
        std::cout<< p.getName() <<" is on the move, choosing position : " << std::endl;
        std::cin >> pos;
        if(pos == -1){
            return true;
        }
        // positions start from 1, but positions in vectors start from 0
        row = --pos / getGameMap().size();
        col = pos - getGameMap().size()*row; 
        if(getGameProgress()[row][col] == loserChar){
            updateGameProgress(row, col, p.getPlaySign());
            break;
        }else{
            std::cout<<"This position is taken. Choose another" << std::endl;
        }
    }
    p.setMoves(p.getMoves()+1);
    printProgressTable();
    // checking for win
    if (checkForWin(row, col))
    {
        std::cout<< "Winner is "<< p.getName() << " with " << p.getMoves() <<" moves"
        <<std::endl;
        setStatus(true);
        return true;
    }
    if (isStaleEnd())
    {
        setStatus(true);
        return true;
    }
    return false;
}
 
 // methods for checking game state (won or continuing)  

bool TicTacToe::checkForWinningRow(int row, int col){
        for (size_t i = 0; i < getGameProgress().size(); i++)
        {
            if (getGameProgress()[row][i]== loserChar || getGameProgress()[row][i] != getGameProgress()[row][col])
            {
                return false;
            }
        }
    return true;
}
bool TicTacToe::checkForWinningCol(int row, int col){
    for (size_t i = 0; i < getGameProgress().size(); i++)
    {
        if (getGameProgress()[i][col] == loserChar || getGameProgress()[i][col] != getGameProgress()[row][col])
        {
            return false;
        }
    }
    return true;
}
bool TicTacToe::checkForWinningDioganalUL2DR(int row, int col){
    if (row != col)
    {
        return false;
    }
    for (size_t i = 0; i < getGameProgress().size(); i++)
    {
        if (getGameProgress()[row][col] != getGameProgress()[i][i] )
        {
            return false;
        }
    }
    return true;
}
bool TicTacToe::checkForWinningDioganalDL2UR(int row, int col){
    for (size_t i = 0; i < getGameProgress().size(); i++)
    {
        if (getGameProgress()[row][col] != getGameProgress()[i][getGameProgress().size()-1 -i]
        || getGameProgress()[i][getGameProgress().size()-1 -i] == loserChar)
        {
            return false;
        }
    }
    return true;
}
bool TicTacToe::checkForWin(int row, int col){
    if(checkForWinningCol(row, col)
    || checkForWinningRow(row, col)
    || checkForWinningDioganalDL2UR (row, col)
    || checkForWinningDioganalUL2DR(row,col)){
        return true;
    }
    return false;
 }
 bool TicTacToe::isStaleEnd(){
    bool isFilled{true};
    isFilled = (getPlayers()[0].getMoves() + getPlayers()[1].getMoves())
     ==( getGameProgress().size()*getGameProgress().size()); 
    
    if (isFilled){
        std::cout<< "There is no winner "<< std::endl;
        return true;
    }
    return false;
 }

// game Menu management 

void TicTacToe::play(){
    
    while (!this->takeWinningPosition())
    { 
        continue;
    }
    return; 
}
void TicTacToe::playNew(){
    
    this->setPlayers();
    this->createGameTable();
    this->play();
}

// for getting already created games;
void TicTacToe::get(){
    printProgressTable();
};

void TicTacToe::run()
{
    play();
}


void TicTacToe::serialize(std::istream& s)
{
    s >> *this;
}

void TicTacToe::deserialize(std::ostream& s)
{
    s << *this;
}

    std::ostream& operator<<(std::ostream& s,const TicTacToe & t)
    {
        s<< t.m_isEnded << t.m_players.size() << ' ';
        for (size_t i = 0; i < t.m_players.size(); i++)
        {
            s << t.m_players[i] << ' ';
        }
        s << t.m_gameProgress.size() << ' ';
        s << t.m_gameProgress[0].size() << ' '; 

        for (size_t i = 0; i < t.m_gameProgress.size(); i++)
        {
            for (size_t j = 0; j < t.m_gameProgress[i].size(); j++)
            {
                s << t.m_gameProgress[i][j] << ' ';
            }
        }

         s << t.m_gameMap.size() << ' ';
        s << t.m_gameMap[0].size() << ' '; 

        for (size_t i = 0; i < t.m_gameMap.size(); i++)
        {
            for (size_t j = 0; j < t.m_gameMap[i].size(); j++)
            {
                s << t.m_gameMap[i][j] << ' ';
            }
        }  
    }

    std::istream& operator>>(std::istream& s, TicTacToe & t)
    {
        size_t sizeMainVec{0}, sizeSubVec{0};
        s>> t.m_isEnded >> sizeMainVec ;
        for (size_t i = 0; i < sizeMainVec; i++)
        {
            s >> t.m_players[i];
        }
        s >> sizeMainVec;
        s >> sizeSubVec; 

        for (size_t i = 0; i < sizeMainVec; i++)
        {
            for (size_t j = 0; j < sizeSubVec; j++)
            {
                s >> t.m_gameProgress[i][j];
            }
        }

         s >> sizeMainVec;
        s >> sizeSubVec; 

        for (size_t i = 0; i < sizeMainVec; i++)
        {
            for (size_t j = 0; j < sizeSubVec; j++)
            {
                s >> t.m_gameMap[i][j];
            }
        }  
    }

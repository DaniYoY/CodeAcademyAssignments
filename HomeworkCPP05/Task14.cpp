// Задача 14
// Напишете конзолен морски шах с n x n дъска за двама играча. Програмата трябва да позволява игра на
// множество игри докато потребителя не пожелае да я затвори.
// В началото на програмата се въвеждат имената на играчите.
// В началото на всяка игра, потребителя избира размера на дъската, след което се провежда една игра.
#include <iostream>
#include <vector>
#include <string>


class Player
{
public:
    char playSign;  
    int moves;  
    std::string name;
    Player();
    ~Player();
};

Player::Player()
{
    playSign = ' ';
    moves = 0;
    name ="";
}

Player::~Player()
{
}

class Game
{
public:
    std::vector<Player> players;
    std::vector<std::vector<int>> gameMap;
    std::vector<std::vector<char>> gameProgress;
    Game();
    ~Game();
};

Game::Game ()
{
    players= {};
    gameMap = {};
    gameProgress = {};
}

Game::~Game()
{
}

std::vector<std::vector<int>> createGameTable(){
    int n{0};
    int pos{0};
    std::cout << "Please choose how big the square should be (submit number)" <<std::endl;
    std::cin >> n;
    std::vector<std::vector<int>> gameMap(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout<< ++pos <<" | ";
            gameMap[i].push_back(pos); 
        }
        std::cout << std::endl;
    }
    return gameMap;
}

std::vector<std::vector<char>> createGameProgress(const std::vector<std::vector<int>> & gameMap){
    std::vector<std::vector<char>> gameProgress(gameMap.size());
    for (int i = 0; i < gameMap.size(); i++)
    {
        std::vector<char> lines (gameMap.size(),' ');
        gameProgress[i] =lines;
    }
    return gameProgress;
}

Game createNewGame(std::vector<Game> & allGames){
    Game game;
    Player p;
    for (int i = 1; i <= 2; i++)
    {
        std::cout << "please enter player  " << i <<" details (name and playing charecter)" << std::endl;
        std::cin >> p.name >> p.playSign;
        std::cout << p.name << " will play with char "<< p.playSign<< std::endl;
        
        if (!game.players.empty() && (p.playSign == game.players[0].playSign || p.name == game.players[0].name))
        {
            std::cout<< "player cannot have same sign nor name as the first! Please choose another." << std::endl;
            --i;
            continue;
        }
        
        game.players.push_back(p);
    }
    game.gameMap = createGameTable();
    game.gameProgress = createGameProgress(game.gameMap);
    allGames.push_back(game);
    return game;
}

void printProgressTable(const Game & game){
    for (int i = 0; i < game.gameMap.size(); i++)
    {
        for (int j = 0; j < game.gameMap.size(); j++)
        {
            if (game.gameProgress[i][j] != ' ')
            {
                 std::cout<< game.gameProgress[i][j] <<" | ";
            }else{
                 std::cout<< game.gameMap[i][j] <<" | ";
            }
        }
        std::cout<< std::endl;
    }
    
};
Player determineNextPlayer(Game & game){
    if (game.players[0].moves == game.players[1].moves)
    {
        return  game.players[0];
    }
    return game.players[1];
 }
bool playMove(Game & game){
    Player p = determineNextPlayer(game);
    int pos{0};
    int row{0};
    int col{0};
 while(true){
    std::cout<< "By choosing -1 will stop the game" << std::endl;
    std::cout<< p.name <<" is on the move, choosing position : " << std::endl;
    std::cin >> pos;
    if(pos == -1){
        return false;
    }
    // positions start from 1, but positions in vectors start from 0
    row = --pos / game.gameMap.size();
    col = pos - game.gameMap.size()*row; 
    if(game.gameProgress[row][col] == ' '){
        game.gameProgress[row][col] = p.playSign;
        break;
    }else{
        std::cout<<"This position is taken. Choose another" << std::endl;
    }
}
    
    if(p.name == game.players[0].name){
        game.players[0].moves++;
    }else{
        game.players[1].moves++;
    }
    printProgressTable(game);
    return true;
}

char checkForWinningRow(const std::vector<std::vector<char>> & vectorsVec){
    for (std::vector<char> charVec : vectorsVec)
    {
        bool isCharSame {true};
        char winner {' '};
        for (int i = 0; i < charVec.size() -1; i++)
        {
            if (charVec[i]== ' ')
            {
                break;
            }
            winner = charVec[i];
            if (charVec[i] != charVec[i+1])
            {
                isCharSame = false;
                break;
            }
        }
        if(isCharSame){
            return winner;
        }
    }
    return ' ';
}
char checkForWinningCol(const std::vector<std::vector<char>> & vectorsVec){
    for (int col = 0; col < vectorsVec.size(); col++)
    {
        bool isCharSame {true};
        char winner {' '};
        for (int row = 0; row < vectorsVec.size()-1; row++)
        {
            if (vectorsVec[row][col]== ' ')
            {
                break;
            }
            winner = vectorsVec[row][col];
            if (vectorsVec[row][col] != vectorsVec[row+1][col])
            {
                isCharSame = false;
                break;
            }
        }
        if(isCharSame){
            return winner;
        }
    }
    return ' ';
}
char checkForWinningDioganalUL2DR(const std::vector<std::vector<char>> & vectorsVec){
    
        bool isCharSame {true};
        char winner {' '};
        for (int i = 0; i < vectorsVec.size()-1; i++)
        {
            if (vectorsVec[i][i]== ' ')
            {
                break;
            }
            winner = vectorsVec[i][i];
            if (vectorsVec[i][i] != vectorsVec[i+1][i+1])
            {
                isCharSame = false;
                break;
            }
        }
        if(isCharSame){
            return winner;
        }
    
    return ' ';
}
char checkForWinningDioganalDL2UR(const std::vector<std::vector<char>> & vectorsVec){
    
        bool isCharSame {true};
        char winner {' '};
        for (int i = 0, j = vectorsVec.size() -1; i < vectorsVec.size()-1; i++, j--)
        {
            if (vectorsVec[j][i]== ' ')
            {
                break;
            }
            winner = vectorsVec[i][i];
            if (vectorsVec[j][i] != vectorsVec[j-1][i+1])
            {
                isCharSame = false;
                break;
            }
        }
        if(isCharSame){
            return winner;
        }
    
    return ' ';
}
 char checkForWin(const Game & game){
    char winningChar {' '};
    // horizontally
    winningChar = checkForWinningRow(game.gameProgress);
    if (winningChar != ' ')
    {
        return winningChar;
    }
    
    // vertically
    winningChar = checkForWinningCol(game.gameProgress);
    if (winningChar != ' ')
    {
        return winningChar;
    }
    // dioganally i=i
    winningChar = checkForWinningDioganalUL2DR(game.gameProgress);
    if (winningChar != ' ')
    {
        return winningChar;
    }
    // dioganally 0=i
    winningChar = checkForWinningDioganalDL2UR(game.gameProgress);
    if (winningChar != ' ')
    {
        return winningChar;
    }
    return ' ';
 }

 bool isEnd(const Game & game){
    char ch{' '};
    std::string winnerName{""};
    ch = checkForWin(game);
    if (ch != ' ' )
    {
        for (int i = 0; i < game.players.size(); i++)
        {
            if (ch == game.players[i].playSign)
            {
                std::cout<< "Winner is "<< game.players[i].name<<std::endl;
            }   
        }
        return true;
    }
    return false;
 }
 
Game accessGame(std::vector<Game> & allGames){
    int gameNumber{0};
    std::cout << "Please see list of games and choose the game number" << std::endl;
    for(int i = 0; i < allGames.size(); i++){
        std::cout<< "Game # " << i << " between "<< allGames[i].players[0].name << " and " << allGames[i].players[1].name << std::endl;
    }
    std::cin >> gameNumber;
    printProgressTable(allGames[gameNumber]);
    return allGames[gameNumber];
}

Game startMenu(std::vector<Game> & allGames){
    Game g{};
    char nextStep {' '};
    bool isToEndMenu{false};
    while(true){
        if(allGames.empty()){
            g =  createNewGame(allGames);
            break;
        }else{
            std::cout<< "Do you want to access another game (press A) or create a new game(press N)" << std::endl;
            std::cin >>nextStep;
        }

        switch (std::toupper(nextStep))
        {
            case 'N':
                g=  createNewGame(allGames);
                isToEndMenu = true;
                break;
            case 'A':
                g =  accessGame(allGames);
                isToEndMenu = true;
                break;
            default:
                std::cout<< "Wrong Char! Do you want to access another game (press A) or create a new game(press N)?" << std::endl;
                break;
        }

        if (isToEndMenu)
        {
            break;
        }
        
    }
    return g;
}

int main(){
    std::vector<Game> allGames{};
    Game currentGame{};
    Player currentPlayer{};
    currentGame = startMenu(allGames);
    while (true)
    {
        if (isEnd(currentGame))
        {
            currentGame = startMenu(allGames);   
        }
        currentPlayer = determineNextPlayer(currentGame);
        if( !playMove(currentGame)){
            currentGame = startMenu(allGames);
        };
    }
    
    return 0;
}
// Задача 19
// Напишете програма с меню и функционалност за връщане назад със следните менюта (състояния на приложението и
// транзиции м/у тях, използвайте команда "back" от потребителя за връщане назад от меню. ):
// Intro Greetings State - показва се веднъж при стартиране. Моли потребителя за име, поздравява го и запазва името му за
// следващите менюта, след което води до Main Menu.
// Main Menu - показва 3 възможни подменюта - Едно за стартиране на морски шах, бесеница и "Богъл":
// https://en.wikipedia.org/wiki/Boggle
// https://en.wikipedia.org/wiki/Hangman_(game)
// От Main Menu можем да изберем една от трите игри, което води в Стартовото меню на съответната игра.
// Ако дадем back от Main Menu, приложението терминира.
// Всяко Стартово меню за игра ще работи различно (при морския шах си избираме размери на дъската, например), но общото м/у
// всички стартови менюта е че водят до стартиране на съответната игра, а back води до Main Menu.
// След провеждане на игра и изписване на финалния резултат или по време на игра, ако потребителя избере back, се връщаме в
// Main Menu.
// За момента ще интегрираме само морския шах, а избора на друга игра ще принтира съощение, че играта се разработва все
// още и ще има единствена опция за връщане в Main Menu чрез back.

#include <iostream>
#include <vector>
#include <string>
#include <map>


class Player
{
public:
    char m_playSign;  
    int moves;  
    std::string name;
    Player();
};

Player::Player()
{
    m_playSign = ' ';
    moves = 0;
    name ="";
}

struct TicTacToeGame
{
class TicTakToe
{
public:
    bool isEnded;
    std::vector<Player> players;
    std::vector<std::vector<int>> gameMap;
    std::vector<std::vector<char>> gameProgress;
    TicTakToe(){
    isEnded = false;
    players= {};
    gameMap = {};
    gameProgress = {};
}
};

// creating vector to store more than 1 game
std::vector<TicTakToe> allGames;
//  empty char for tracking progress
char loserChar {' '};
// methods for boards and game creation
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
            std::cout<< "| " << ++pos <<" |";
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
        std::vector<char> lines (gameMap.size(),loserChar);
        gameProgress[i] =lines;
    }
    return gameProgress;
}
TicTakToe createNewGame(std::vector<TicTakToe> & allGames){
    TicTakToe game;
    Player p;
    for (int i = 1; i <= 2; i++)
    {
        std::cout << "please enter player  " << i <<" details (name and playing charecter)" << std::endl;
        std::cin >> p.name >> p.m_playSign;
        std::cout << p.name << " will play with char "<< p.m_playSign<< std::endl;
        
        if (!game.players.empty() && (p.m_playSign == game.players[0].m_playSign || p.name == game.players[0].name))
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
// methods for making moves
void printProgressTable(const TicTakToe & game){
    for (int i = 0; i < game.gameMap.size(); i++)
    {
        for (int j = 0; j < game.gameMap.size(); j++)
        {
            if (game.gameProgress[i][j] != loserChar)
            {
                 std::cout<< game.gameProgress[i][j] <<" | ";
            }else{
                 std::cout<< game.gameMap[i][j] <<" | ";
            }
        }
        std::cout<< std::endl;
    }
};
Player & determineNextPlayer(TicTakToe & game){
    if (game.players[0].moves == game.players[1].moves)
    {
        return  game.players[0];
    }
    return game.players[1];
 }
bool takeWinningPosition(TicTakToe & game){
    int pos{0}, row{0}, col{0};
    Player & p = determineNextPlayer(game);
    //  making move
     while(true){
        std::cout<< "By choosing -1 will stop the game" << std::endl;
        std::cout<< p.name <<" is on the move, choosing position : " << std::endl;
        std::cin >> pos;
        if(pos == -1){
            return true;
        }
        // positions start from 1, but positions in vectors start from 0
        row = --pos / game.gameMap.size();
        col = pos - game.gameMap.size()*row; 
        if(game.gameProgress[row][col] == loserChar){
            game.gameProgress[row][col] = p.m_playSign;
            break;
        }else{
            std::cout<<"This position is taken. Choose another" << std::endl;
        }
    }
    p.moves++;
    printProgressTable(game);
    // checking for win
    if (checkForWin(game,row, col))
    {
        std::cout<< "Winner is "<< p.name << " with " << p.moves <<" moves"
        <<std::endl;
        game.isEnded = true;
        return true;
    }
    if (isStaleEnd(game))
    {
        game.isEnded = true;
        return true;
    }
    return false;
}
 // methods for checking game state (won or continuing)  
bool checkForWinningRow(const std::vector<std::vector<char>> & vectorsVec, int row, int col){
        for (size_t i = 0; i < vectorsVec.size(); i++)
        {
            if (vectorsVec[row][i]== loserChar || vectorsVec[row][i] != vectorsVec[row][col])
            {
                return false;
            }
        }
    return true;
}
bool checkForWinningCol(const std::vector<std::vector<char>> & vectorsVec, int row, int col){
    for (size_t i = 0; i < vectorsVec.size(); i++)
    {
        if (vectorsVec[i][col] == loserChar || vectorsVec[i][col] != vectorsVec[row][col])
        {
            return false;
        }
    }
    return true;
}
bool checkForWinningDioganalUL2DR(const std::vector<std::vector<char>> & vectorsVec, int row, int col){
    if (row != col)
    {
        return false;
    }
    for (size_t i = 0; i < vectorsVec.size(); i++)
    {
        if (vectorsVec[row][col] != vectorsVec[i][i] )
        {
            return false;
        }
    }
    return true;
}
bool checkForWinningDioganalDL2UR(const std::vector<std::vector<char>> & vectorsVec, int row, int col){
    for (size_t i = 0; i < vectorsVec.size(); i++)
    {
        if (vectorsVec[row][col] != vectorsVec[i][vectorsVec.size()-1 -i]
        || vectorsVec[i][vectorsVec.size()-1 -i] == loserChar)
        {
            return false;
        }
    }
    return true;
}
bool checkForWin(const TicTakToe & game, int row, int col){
    const std::vector<std::vector<char>> & mapProgress = game.gameProgress;
    if(checkForWinningCol(mapProgress,row, col)
    || checkForWinningRow(mapProgress,row, col)
    || checkForWinningDioganalDL2UR(mapProgress, row, col)
    || checkForWinningDioganalUL2DR(mapProgress,row,col)){
        return true;
    }
    return false;
 }
 bool isStaleEnd(const TicTakToe & game){
    bool isFilled{true};
    isFilled = (game.players[0].moves + game.players[1].moves)
     ==( game.gameProgress.size()*game.gameProgress.size()); 
    
    if (isFilled){
        std::cout<< "There is no winner "<< std::endl;
        return true;
    }
    return false;
 }
// game Menu management 
TicTakToe & accessGame(std::vector<TicTakToe> & allGames){
    int gameNumber{0};
    TicTakToe game;
    if(allGames.empty()){
        game = createNewGame(allGames);
        return allGames[0];
    }
    std::cout << "Please see list of games and choose the game number" << std::endl;
    for(int i = 0; i < allGames.size(); i++){
        if(!allGames[i].isEnded){
            std::cout<< "Game # " << i << " between "<< allGames[i].players[0].name << " and " << allGames[i].players[1].name << std::endl;
        }
    }
    std::cout<< "Game # " << allGames.size() << " is for NEW GAME " << std::endl;
    std::cin >> gameNumber;
    if (gameNumber == allGames.size())
    {
        game = createNewGame(allGames);
        return allGames.back();
    }
    
    printProgressTable(allGames[gameNumber]);
    return allGames[gameNumber];
}
void playTheTikTakToe(){
     Player currentPlayer{};
     TicTakToe currentGame{};
    currentGame = accessGame(allGames);
    while (!takeWinningPosition(currentGame))
    { 
        continue;
    }
    return; 
}
};
struct HangmanGame
{
    class Hangman
    {
    public:
        int mistakeCounter;
        std::string word;
        std::map<char,bool> usedWords;
        Hangman(){
            mistakeCounter =9;
            word = "";
            usedWords;
        };
    };
    
    Hangman setupGame(Player & p){
        int mistakes{0};
        std::string word{""};
        Hangman game;
        std::cout<< "Let's play a game, " << p.name << std::endl;
        std::cout<< "Enter a word, " << p.name << std::endl;
        std::cin>> word;
        while(true){
            std::cout<< "Enter number of mistakes that can be made (up to 9)" << std::endl;
            std::cin >> mistakes; 
            if (mistakes > 10 || mistakes < 0 || std::cin.fail())
            {
                std:: cout << "This is an unacceptable input. Mistakes can be from 0 to 9." << std:: endl;
                continue;
            }
            break;
        }
        game.word = word;
        game.mistakeCounter = mistakes;
        return game;
    }
    void makeMove(Hangman & game){
        // take char, check char, if --mistakes are 0 end, or win
    }

    
    


    // "  ___________"
    // "  |         |"
    // "  |         O"
    // "  |        /|\\"
    // "  |        /\\"
    // "  |"
    // "__|__"

};

void greetPlayer(Player & p){
    std::cout<<"Hi Player, what is your name?" << std::endl;
    std::cin >> p.name;
    std::cout << "Nice to meet you, " << p.name << std::endl;
}
void printMainMenu(){
    std::cout<<
    "_____Main Menu_____\n"
    "\n"
    "1. Tic Tac Toe\n"
    "2. Hangman \n"
    "3. Boggle \n"
    "\n"
    "___________________"
    "4.      Back       "
    "___________________";
}
void startMainMenu(Player & p){
    char gameChoice{' '};
    std::cout<<"Wanna play? Select a number, sweet " << p.name <<std::endl;
    TicTacToeGame ttt;
    while (true)
    {
        printMainMenu();
        std::cin >> gameChoice;
        switch (gameChoice)
        {
        case '1':
            ttt.playTheTikTakToe();
            continue;
        case '2':
            continue;
        case '3':
            continue;  
        case '4':
            greetPlayer(p);  
    default:
        std::cout<<"This is not a suggested number";
        continue;
    }
    }
}

int main(){
    Player p;
    greetPlayer(p);
    while (true)
    {
        startMainMenu(p);
    }
    
    return 0;
}
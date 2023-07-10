#include "Menu.hpp"

Menu::Menu(): m_StartFromBegin(true), m_isClosing(false)
{
}

void Menu::greetPlayer(){
    std::string name{""};
    std::cout<<"Hi Player, what is your name?" << std::endl;
    std::cin >> name;
    m_player.setName(name);
    std::cout << "Nice to meet you, " << m_player.getName() << std::endl;
    m_StartFromBegin = false;
}

void getInputForAccessingGame(int & gameNumber){
    std::string input;
    std::getline(std::cin, input);
    try
    {
        gameNumber = std::stoi(input);
    }
    catch(const std::exception& e)
    {
        gameNumber = -1;
    }
}

void Menu::accessTTTgame(std::vector<TicTacToe> & allGames){
    int gameNumber{0};
    TicTacToe game;
    if(allGames.empty()){
        game.playNew();
        if(!game.hasEnded()){
            allGames.push_back(game);
        }
    }
    std::cout << "Please see list of games and choose the game number, pressing anything else will lead you back" << std::endl;
    for(int i = 0; i < allGames.size(); i++){
        if(!allGames[i].hasEnded()){
            std::cout<< "Game # " << i << " between "<< allGames[i].getPlayers()[0].getName() << " and " << allGames[i].getPlayers()[1].getName() << std::endl;
        }
    }
    std::cout<< "Game # " << allGames.size() << " is for NEW GAME " << std::endl;
    
    getInputForAccessingGame(gameNumber);
    
    if (gameNumber == allGames.size())
    {
        game.playNew();
        if(!game.hasEnded()){
            allGames.push_back(game);
        }
    }else if( gameNumber < allGames.size() && gameNumber >=0 ){
        game = allGames[gameNumber];
        game.play();
    }
}

void Menu::accessHMgame(std::vector<Hangman> & allGames){
  int gameNumber{0};
  std::string line{""};
    Hangman game;
    if(allGames.empty()){
        game.playNew();
        if(!game.hasEnded()){
            allGames.push_back(game);
        }
    }
    std::cout << "Please see list of games and choose the game number" << std::endl;
    for(int i = 0; i < allGames.size(); i++){
        if(!allGames[i].hasEnded()){
            std::cout<< "Game # " << i << " for the definition - "<< allGames[i].getDescription() << std::endl;
        }
    }
    std::cout<< "Game # " << allGames.size() << " is for NEW GAME " << std::endl;

   getInputForAccessingGame(gameNumber);

    if (gameNumber == allGames.size())
    {
        game.playNew();
        if(!game.hasEnded()){
            allGames.push_back(game);
        }
    }else if( gameNumber < allGames.size() && gameNumber >=0 ){
        game = allGames[gameNumber];
        game.play();
    }
}

void Menu::printMainMenu(){
    std::cout<<
    "_____Main Menu_____\n"
    "\n"
    "1. Tic Tac Toe\n"
    "2. Hangman \n"
    "3. Boggle \n"
    "\n"
    "___________________\n"
    "4.      Back       \n"
    "5.      Exit       \n"
    "___________________\n";
}

void Menu::startMainMenu(){
    char gameChoice{' '};
    std::cout<<"Wanna play? Select a number, sweet " << m_player.getName() <<std::endl;
    
        printMainMenu();
        std::cin >> gameChoice;
        switch (gameChoice)
        {
        case '1':
            accessTTTgame(this->tttGames);
            break;
        case '2':
            accessHMgame(this->hmGames);
            break;
        case '3':
            std::cout<<"under construction"<<std::endl;
            break;  
        case '4':
            m_StartFromBegin = true;
            break;
        case '5':
            m_isClosing = true;
            break;   
        default:
            std::cout<<"This is not a suggested number";
    }
}

void Menu::run(){
    while (true)
    {
        if (m_StartFromBegin)
        {
            greetPlayer();
        }
        
        startMainMenu();
        
        if (m_isClosing)
        {
            break;
        }
    }   
}

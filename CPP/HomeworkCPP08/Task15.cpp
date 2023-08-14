// Задача 15
// Напишете игра на бесеница със следното примерно поведение:

#include<string>
#include<iostream>

struct HangmanGame{
    std::string description{""};
    std::string word{""};
    std::string attempts{""};
    unsigned int lives{10};
    std::string info{""};
    
    void printInfo(){
        std::cout<< "Description: "<< description<< std::endl;
        std::cout<< "Failed attempts: "<< attempts <<std::endl;
        std::cout<< "Remaining attempts: "<< lives<< std::endl;
        for (size_t i = 0; i < info.size(); i++)
        {
            std::cout << info[i]<<' ';
        }
        std::cout<<std::endl;
    };
    void setWord(){
        std::cout<< "Please enter a word, followed by brief desctiption on a new line \n";
        std::getline(std::cin, word);
        std::getline(std::cin, description);
        for (size_t i = 0; i < word.size(); i++)
        {
            info += '_';
        }
        
        ;
    };
    void checkTrial(std::string & trial){
        for(auto & a : trial){
            bool isFound{false};
            for (auto letter : attempts)
            {
                if (letter == a)
                {
                    std::cout << "You tried this \n\n";
                    return;
                } 
            }
        
    
            for (size_t i = 0; i < word.size(); i++)
            {
                if (word[i] == a)
                {
                    info[i] =a;
                    isFound = true;
                    std:: cout << "Found! \n\n"<<std::endl;
                }
            }
            if(!isFound){
                lives--;
                attempts += a;
                std:: cout << "Not Found!\n\n"<<std::endl;
            }
            if(lives == 0){
                std::cout<< "\n You died! \n"<<std::endl;
                return;
            }
        }
    };
    bool checkWin(){
        return word == info;
    };
    };

    void playHangman(){
        HangmanGame game;
        game.setWord();
        std::string trial{""};
        while (std::getline(std::cin,trial))
        {
            game.checkTrial(trial);
            if (game.checkWin() || game.lives == 0)
            {
                break;
            }
            game.printInfo(); 
        }
        
    }
    int main(int argc, char const *argv[])
    {
        playHangman();
        return 0;
    }
    

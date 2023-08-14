// Задача 11
// Напишете игра на Boggle, която работи с файла от предходните задачи.
// https://en.wikipedia.org/wiki/Boggle
// Направете потребителския интерфейс по ваш дизайн.
#include <iostream>
#include<string>
#include<vector>
#include<random>
#include <fstream>
class BoggleBoard
{
private:
    std::vector<std::vector<char>> m_board;
    
    int m_numOfDicesSides = 6;
    int m_sideSize = 4;
    std::vector<std::string> dices{
        "rifobx", 
        "ifehey",
        "denows",
        "utoknd",
        "hmsrao",
        "lupets",
        "acitoa",
        "ylgkue",
        "qbmjoa",
        "ehispn",
        "vetign",
        "baliyt",
        "ezavnd",
        "ralesc",
        "uwilrg",
        "pacemd"
    };
public:
    BoggleBoard(){
        std::vector<char> row(m_sideSize,' ');
        for (size_t i = 0; i < m_sideSize; i++)
        {
            m_board.push_back(row);
        }
        generateChars();
    };
    const int sideSize() const{
        return m_sideSize;
    };
    const char getChar (size_t row, size_t col) const{
            return this->m_board[row][col];
    };
    void print(){
        std::cout << "Board is: \n\n";
        for (size_t i = 0; i < m_board.size(); i++)
        {
            for (size_t j = 0; j < m_board[i].size(); j++)
            {
                std::cout<< " | "<< m_board[i][j];  
            }
            std::cout << " |\n"<< std::endl;
        }
    };
private:
    void generateChars(){
            for (size_t i = 0; i < m_sideSize; i++)
            {
                for (size_t j = 0; j < m_sideSize; j++)
                {
                    m_board[i][j] = dices[i*m_sideSize + j][std::rand()%m_numOfDicesSides];
                }
            }
        };
    
};

class Boggle
{
private:
    BoggleBoard b;
    int score;
    std::fstream dictionary; 
    
public:
    Boggle(): score{0} {};
    bool verifyWordInDictionary(const std::string & word);
    bool verifyWordOnBoardByCharBegin(const std::string & word, int wordIndex=0, int boardRow=0, int boardCol=0);
    bool verifyWordOnBoard(const std::string & word);
    void sumScore(int wordSize);
    void play();
};

bool Boggle::verifyWordInDictionary(const std::string & word){
    std::string dicWord{""};
    dictionary.open("words.txt", std::fstream::in);
    if (dictionary)
    {
        while (!std::getline(dictionary, dicWord).eof())
        {
            if (dicWord == word)
            {
                return true;
            }            
        }
        
    }
    std::cout << "This is not a word in the dictionary!! Try again!"<< std::endl;
    return false;
}

void Boggle::sumScore(int wordSize){
    switch (wordSize)
    {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
    case 4:
        this->score +=1;
        break;
    case 5:
        this->score +=2;
        break;
    case 6:
        this->score +=3;
        break;
    case 7:
        this->score +=5;
        break;
    default:
        this->score +=11;
        break;
    }
}

void Boggle::play(){
    b.print();
    std::cout<< "LETS PLAY! \nNow enter a word: "<< std::endl;
    std::string attempt{""};

    while (!std::getline(std::cin, attempt).eof())
    {
        if (attempt == "0")
        {
            std::cout << "The game is stopped by the player \n The final score is "<< this->score << std::endl;
            break;
        }

        if(verifyWordInDictionary(attempt) && verifyWordOnBoard(attempt)){
            this->sumScore(attempt.size());
            this->b.print();
        }
        std::cout << "You can exit by pressing 0 or add new word" << std::endl;
    }
}

bool Boggle::verifyWordOnBoardByCharBegin(const std::string & word, int wordIndex, int boardRow, int boardCol){
    
    if(boardRow < 0 || boardRow > (b.sideSize() -1)
        || boardCol < 0 || boardCol > (b.sideSize() -1)){
           return false;
    }
        
    if(word[wordIndex]!= b.getChar(boardRow,boardCol)){
        return false;
    }

    if(wordIndex == word.size()-1){
        return true;
    }
    
    // checking for other neibhour positions
    bool upperLeft{false}, upperCenter{false}, upperRight{false}, left{false}, right{false}, downLeft{false}, downCenter{false}, downRight{false}; 
    
       upperLeft = verifyWordOnBoardByCharBegin(word, wordIndex+1, boardRow -1, boardCol-1); 
       upperCenter = verifyWordOnBoardByCharBegin(word, wordIndex+1, boardRow -1, boardCol);
       upperRight = verifyWordOnBoardByCharBegin(word, wordIndex+1, boardRow -1, boardCol+1);
       left = verifyWordOnBoardByCharBegin(word, wordIndex+1, boardRow, boardCol-1);
       right = verifyWordOnBoardByCharBegin(word, wordIndex+1, boardRow, boardCol+1);
       downLeft = verifyWordOnBoardByCharBegin(word, wordIndex+1, boardRow +1, boardCol-1);
       downCenter = verifyWordOnBoardByCharBegin(word, wordIndex+1, boardRow +1, boardCol);
       downRight = verifyWordOnBoardByCharBegin(word, wordIndex+1, boardRow +1, boardCol+1);
    
    return upperLeft || upperCenter || upperRight || left || right || downLeft || downCenter || downRight; 
}

bool Boggle::verifyWordOnBoard(const std::string & word){
    for (size_t row = 0; row < b.sideSize(); row++)
    {
        for (size_t col = 0; col < b.sideSize(); col++)
        {
            if (verifyWordOnBoardByCharBegin(word,0,row,col))
            {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    Boggle b;
    b.play();
    return 0;
}

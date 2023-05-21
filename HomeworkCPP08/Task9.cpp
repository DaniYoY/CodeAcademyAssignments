// Задача 09
// Напишете игра на Камък-Ножица-Хартия с компютъра. Играта трябва да позволява на играча да въведе
// брой рундове преди провеждането на игра.

#include <iostream>
#include <random>
#include <vector>
#include <string>

    static unsigned int State = 1804289383;
unsigned int generateRandomNumber( unsigned int lower, unsigned int upper){
    unsigned int num = State;
    num ^= num << 13;
    num ^= num >> 17;
    num ^= num << 5;
    State = num;
    return (num % (upper - lower)) + lower;
}

enum Choice{
    Rock,
    Paper,
    Scissors 
};
int determineWin(Choice turn,Choice compTurn){
    if(turn == compTurn){
        return 0;
    }
    if ((turn == Choice::Rock && compTurn == Choice::Paper)
    || (turn == Choice::Scissors && compTurn == Choice::Rock)
    || (turn == Choice::Paper && compTurn == Choice::Scissors))
    {
        return -1;
    }else if ((turn == Choice::Rock && compTurn == Choice::Scissors)
    || (turn == Choice::Scissors && compTurn == Choice::Paper)
    || (turn == Choice::Paper && compTurn == Choice::Rock))
    {
        return  1;
    }
    return 0;
}

Choice takeTurn(){
    char turn{' '};
    std::cout<< "Please enter: \n"
    "\'r\' for rock \n"
    "\'p\' for paper \n"
    "\'s\' for scissors \n";
    
    while(!(std::cin >> turn).eof()){
        switch (turn)
        {
           
        case 'r':
            return  Choice::Rock;
        case 'p':
            return Choice::Paper;
        case 's':
            return Choice::Scissors;
        default:
            std::cout<< "invalid input. Choose between r/p/s"<<std::endl;
            continue;
        }
    }
}
// for win returns 1, for loss 0;
int playRound(){
    int result{0};
    Choice turn = takeTurn();
    std::vector<Choice> options{Choice::Rock, Choice::Paper, Choice::Scissors};
    Choice compTurn = options[generateRandomNumber(0,3)];
    result = determineWin(turn, compTurn);
    switch (result)
    {
    case 1:
        std::cout<< "Round won" << std::endl;
        break;
    case -1:
        std::cout<< "Round lost" << std::endl;
        break;
    default:
        std::cout<< "It is a tie" << std::endl;
        break;
    }
    return result;
}

void playRPS(int rounds){
    int result{0};
    for (size_t i = 0; i < rounds; i++)
    {
        result += playRound();
    }
    
    if (result > 0)
    {
        std::cout<< "Player won";
    }else if(result < 0){
        std::cout<< "Player lost";
    }else{
        std::cout<< "It is stalemate";
    }   
}
int main(int argc, char const *argv[])
{
    int rounds{0};
    std::cout<< "Enter number of rounds" << std::endl; 
    std::cin>> rounds;
    playRPS(rounds);
    return 0;
}


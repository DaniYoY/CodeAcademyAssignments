// Задача 10
// Напишете игра Познай Числото, където потребителя трябва да познае произволно число в даден интервал,
// като на всеки опит компютъра подсказва с:
// ● нагоре или надолу
// ● горещо, топло, хладно, студено, ледено (в зависимост от това, колко близо е опитът на играча до
// числото)

#include<string>
#include<iostream>
#include<ctime>
#include<cmath>
#include<random>

long generateTarget()
{
    int target{0}; 
    std::srand(std::time(0));
    target = std::rand();
    return static_cast<long>(target);
}

bool determineIfUp(long guess,long target){
    if (guess < target)
    {
        std::cout<<"Wrong! Target is up"<<std::endl;
        return true;
    }
        std::cout<<"Wrong! Target is down"<<std::endl;
        return false;
}

void determineHeat(long guess,long target,long lowerRange, long upperRange){
    long border{0}, step{0};
    std::vector<std::string> heatLevels{"icy","cold", "calm","warm","hot"};
    if (determineIfUp(guess, target))
    {
        border = lowerRange;

    }else{
        border = upperRange;
    }

    step = std::abs(border - target)/5;
//    this logic is not working properly
    if (guess < target)
    {
        for (size_t i = 1; i <= heatLevels.size(); i++)
        {
            if (guess < lowerRange +step*i)
            {
                std::cout<< "You are far way or not so much. The heat level is "<< heatLevels[i-1]<<std:: endl;
                break;
            }
        }
    }else
    {
        for (size_t i = 1; i <= heatLevels.size(); i++)
        {
            if (guess > upperRange -step*i)
            {
                std::cout<< "You are far way or not so much. The heat level is "<< heatLevels[i-1]<<std:: endl;
                break;
            }
        }
    }
}

void playGuessingNumberGame(){
    long long upperRange{0}, lowerRange{0}, guess{0}, target{0};
    std::cout<< "Enter range for the guessing game"<<std::endl;
    std::cin>> lowerRange>> upperRange;
    target = (generateTarget() % (upperRange - lowerRange)) + lowerRange;
    if (lowerRange> upperRange)
    {
        long temp{0}; 
        temp = lowerRange;
        lowerRange = upperRange;
        upperRange = temp;
    }
    std::cout<< "Let's the game begin! Enter the guess: \n";
    while (!(std::cin>>guess).eof())
    {
        if (guess < lowerRange || guess > upperRange)
        {
            std::cout << guess << " is out of range"<<std::endl;
            continue;
        }
        if (guess == target)
        {
            std::cout<< "You guessed it"<< std::endl;
            break;
        }
        determineHeat(guess, target, lowerRange,upperRange);
    }
}

int main(int argc, char const *argv[])
{
    playGuessingNumberGame();
    return 0;
}


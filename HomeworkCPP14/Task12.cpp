// Задача 12
// Напишете Word-Chain игра, в която на играча се дават две произволни думи и целта на играта е с последователност от
// промени по думата, да се стигне от едната до другата дума. Промените могат да са само: промяна на буква, добавяне на буква,
// премахване на буква, размяна на две букви. Един ход е валиден само ако новообразуваната от играча дума съществува (е
// открита във файла от предходните задачи). Пример: slow > flow > flog > frog > frig > brig > brag > bag > sag > sat > fat > fast

// actions for funtions
// change
// add
// remove
// swap
// verify

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <random>
#include <chrono>
#include <algorithm>

int numberOfWordInFile{370105};

bool isRealWord(const std::string &word)
{
    std::fstream dictionary;
    std::string dicWord{""};
    dictionary.open("words.txt", std::ios::in);

    while (!std::getline(dictionary, dicWord).eof())
    {
        if (dicWord == word)
        {
            dictionary.close();
            return true;
        }
    }
    dictionary.close();
    return false;
}

std::pair<std::string, std::string> generateRandomWord()
{
    std::pair<std::string, std::string> result;
    std::fstream dictionary;
    std::string dicWord{""};
    dictionary.open("words.txt", std::ios::in);
    // generating random number for random word
    double seed = (std::chrono::duration<double>((std::chrono::system_clock::now()).time_since_epoch())).count();
    std::srand(static_cast<unsigned int>(seed));
    int randomRange{0};
    randomRange = rand() % numberOfWordInFile;

    int i{0};
    while (!std::getline(dictionary, dicWord).eof() && i++ != randomRange)
    {
        if (i == (rand() % numberOfWordInFile) / 17)
        {
            result.first = dicWord;
        }
    }
    result.second = dicWord;
    dictionary.close();
    return result;
}

void changeChar(std::string &word)
{
    std::string changedWord{""};
    while (true)
    {
        int changes{0};
        std::cout << "Please enter word with one char different than " << word << std::endl;
        std::cin >> changedWord;
        if (!isRealWord(changedWord))
        {
            std::cout << "You must submit a real word. Try again" << std::endl;
            continue;
        }
        
        if (word.size() != changedWord.size())
        {
            std::cout << "You must change only one character" << std::endl;
            continue;
        }
        
        for (size_t i = 0; i < word.size(); i++)
        {
            if (word[i] != changedWord[i])
            {
                changes++;
            }
        }

        if ((changes == 1) && (word.size() == changedWord.size()))
        {
            word = changedWord;
            break;
        }
    }
}

void addChar(std::string &word)
{
    std::string changedWord{""};
    while (true)
    {
        int changes{0};
        std::cout << "Please enter word with one added char in " << word << std::endl;
        std::cin >> changedWord;
        if (!isRealWord(changedWord))
        {
            std::cout << "You must submit a real word. Try again!" << std::endl;
            continue;
        }
        
        if (word.size() +1 != changedWord.size())
        {
            std::cout << "You must add only one character. Try again!" << std::endl;
            continue;
        }
        
        for (size_t i = 0; i < word.size(); i++)
        {
            if (word[i] != changedWord[i])
            {
                changes++;
                i++;
            }
        }

        if ((changes == 1) && (word.size() +1 == changedWord.size()))
        {
            word = changedWord;
            break;
        }
    }
}

void removeChar(std::string &word)
{
    std::string changedWord{""};
    while (true)
    {
        int changes{0};
        std::cout << "Please enter word with one added char in " << word << std::endl;
        std::cin >> changedWord;
        if (!isRealWord(changedWord))
        {
            std::cout << "You must submit a real word. Try again!" << std::endl;
            continue;
        }
        
        if (word.size() -1 != changedWord.size())
        {
            std::cout << "You must remove only one character. Try again!" << std::endl;
            continue;
        }
        
        for (size_t i = 0; i < word.size(); i++)
        {
            if (word[i] != changedWord[i])
            {
                changes++;
                i--;
            }
        }

        if ((changes == 1) && (word.size() -1 == changedWord.size()))
        {
            word = changedWord;
            break;
        }
    }
}

void swapChars(std::string &word)
{
    std::string changedWord{""};
    while (true)
    {
        int changes{0};
        std::cout << "Please enter word with 2 swapped chars from " << word << std::endl;
        std::cin >> changedWord;
        if (!isRealWord(changedWord))
        {
            std::cout << "You must submit a real word. Try again!" << std::endl;
            continue;
        }
        
        if (word.size() != changedWord.size())
        {
            std::cout << "You must one swap 2 characters, not shorten or extend the word. Try again!" << std::endl;
            continue;
        }
        
        bool isSwapped{false};
        for (size_t i = 0; i < word.size(); i++)
        {
            if (word[i] != changedWord[i])
            {
                changes++;
                
                for (size_t k = i+1; i < word.size(); k++)
                {
                    if(word[i] == word[k] && changedWord[i] == changedWord[k]){
                        isSwapped = true;
                        break;
                    }
                } 
            }
        }

        if ((changes == 1) && (word.size() -1 == changedWord.size()))
        {
            word = changedWord;
            break;
        }
    }
}

bool checkForWin(std::pair<std::string, std::string> pairWords){
    if (pairWords.first == pairWords.second)
            {
                std:: cout << "You won";
                return true;
            }
    return false;
}

void playSteppingStones(){
    std::pair<std::string, std::string> wordPath = generateRandomWord();
    std::string interimWord{""};
    int n {0};  
    bool exitNow{false};  
    while (!exitNow)
    {
        std::cout << wordPath.first << " is the beginning. Now choose an action\n" 
        "1 for adding a char \n"
        "2 for removing a char \n"
        "3 for changing a char\n"
        "4 for swapping 2 chars\n"
        "any other number for exiting\n"
        "reach " << wordPath.second 
        << std::endl;
        std::cin >> n;
        switch (n)
        {
        case 1:
            addChar(wordPath.first);
            exitNow = checkForWin(wordPath); 
            break;
        case 2:
            removeChar(wordPath.first);
            exitNow = checkForWin(wordPath); 
            break;
        case 3:
            changeChar(wordPath.first);
            exitNow = checkForWin(wordPath); 
            break;
        case 4:
            swapChars(wordPath.first);
            exitNow = checkForWin(wordPath); 
            break;    
        default:
            exitNow = true;
            break;
        }  
    }
    

}

int main(int argc, char const *argv[])
{
    playSteppingStones();
    return 0;
}

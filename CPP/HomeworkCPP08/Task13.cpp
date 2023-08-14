// Задача 13
// Напишете игра за трениране на писане на клавиатура. Играта трябва да дава серия от произволни неща,
// които потребителя да напише правилно.
// ● След правилно въведена дума/текст, програмата трябва да принтира времето, отнело за вярно
// изписване, както и броя грешни опити.
// ● На края на играта, програмата трябва да принтира общото време, за което потребителя е въвел
// всички думи, както и общия брой грешки.

#include<string>
#include<iostream>
#include<chrono>
#include<cmath>
#include<random>

static unsigned int State = 1804289383;
unsigned int generateRandomNumber( unsigned int lower, unsigned int upper){
    unsigned int num = State;
    num ^= num << 13;
    num ^= num >> 17;
    num ^= num << 5;
    State = num;
    return (num % (upper - lower)) + lower;
}

std::string generateWord(){
    unsigned int asciiA = 97;
    unsigned int asciiZ = 122;
    unsigned int wordLen = generateRandomNumber(2,11);
    std::string word{""};

    for (size_t i = 0; i < wordLen; i++)
    {
        char letter = generateRandomNumber(asciiA,asciiZ+1);
        word +=letter;
    }
    return word;
}

int testQuestion(){
    std::string answer{""};
    std::string word{""};
    int mistakes{0};
    word = generateWord();
    using std::chrono::high_resolution_clock;
    using std::chrono::seconds;
    using std::chrono::duration_cast;
    auto tBegin = high_resolution_clock::now(); 
    std::cout<< "Please enter the word: "<< word<< std::endl;
    while (!(std::cin >> answer).eof())
    {
        std::cout<< "Please enter the word: "<< word<< std::endl;
        if (answer == word)
        {
            std::cout<< "Correct"<<std::endl;
            break;
        }else
        {
            ++mistakes;
            std::cout<< "Try again"<<std::endl;
        }
    }
    auto tEnd = high_resolution_clock::now(); 
    auto time = duration_cast<seconds>(tEnd- tBegin);
    std::cout<<" The word is typed on "<< mistakes +1 <<" trials for "<< time.count() <<" sec"<<std::endl;
    return mistakes;
}

void undertakeTest(){
    int mistakes{0}, interimMistakes{0};
    int numberOfQuestions{0};
    using std::chrono::high_resolution_clock;
    using std::chrono::seconds;
    using std::chrono::duration_cast;
    std::cout<< "Please submit how many questions will you be answering?"<<std::endl;
    std::cin>>numberOfQuestions;
    auto tBegin = high_resolution_clock::now(); 
    for (size_t i = 0; i < numberOfQuestions; i++)
    {
        interimMistakes = testQuestion();
        std::cout<< "You got the answer with "<< interimMistakes<<" mistakes"<<std::endl;
        mistakes += interimMistakes;
    }
    auto tEnd =high_resolution_clock::now();
    auto time = duration_cast<seconds>(tEnd- tBegin);
    std::cout<<" The test is complete with "<< mistakes <<"mistakes for "<< time.count() <<" sec"<<std::endl;
}

int main(int argc, char const *argv[])
{
    undertakeTest();
    return 0;
}

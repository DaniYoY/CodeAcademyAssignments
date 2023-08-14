// Задача 14
// Напишете игра за трениране на смятане на таблицата за умножение. Програмата трябва да задава серия от
// произволни въпроси и да засича и принтира времето, отнело на потребителя за въвеждане на верен
// отговор.
// ● За всеки въпрос, потребителя трябва да може да даде неограничен брой грешни отговори до
// въвеждането на правилен, преди да продължи към следващия въпрос.
// ● Накрая на серията с въпроси, програмата трябва да принтира общото време, за което потребителя е
// отговорил на въпросите, както и броя грешни отговори.

#include<iostream>
#include<chrono>
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

int testQuestion(){
    unsigned int multiplicand{0}, multiplier{0},product{0}, answer{0};
    int mistakes{0};
    multiplicand = generateRandomNumber(1,11);
    multiplier = generateRandomNumber(1,11);
    product = multiplicand*multiplier; 
    std::cout<< multiplier<<" x "<<multiplicand<<" = ?"<<std::endl;
    while (!(std::cin >> answer).eof())
    {
        if (answer == product)
        {
            std::cout<< "Correct"<<std::endl;
            break;
        }else
        {
            ++mistakes;
            std::cout<< "Try again"<<std::endl;
        }
    }
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
    std::cout<<" The test is complete with "<< mistakes <<" for "<< time.count() <<" sec"<<std::endl;
}

int main(int argc, char const *argv[])
{
    undertakeTest();
    return 0;
}


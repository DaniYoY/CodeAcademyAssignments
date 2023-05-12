// Задача 16
// За програма за упражняване на теоретични знания, напишете класове за:
// ● Тест с въпроси с множество възможни отговори - колекция от въпроси +
// текст с начално описание на теста.
// ● Въпрос от теста: Текст на въпроса + колекция от възможни отговори.
// Може да има повече от един верен отговор.
// ● Отговор от теста: Текст на отговора + текст с пояснение защо този
// отговор е верен или не + точки, давани за верен отговор + точки
// отнемани за грешен отговор.
// Напишете функционалност за:
// ● Въвеждане на данните за тест
// ● Провеждане на тест, завършващо с принтиране на резултат, в брой точки

#include <iostream>
#include <string>
#include <vector>

class Answer
{
public:
    std::string response;
    std::string clarification;
    int rewardPoints;
    int penaltyPoints;
    Answer();
};

Answer::Answer()
{
    response ="";
    clarification="";
    rewardPoints =0;
    penaltyPoints =0;
}

class Question
{
public:
    std::string query;
    std::vector<Answer> choices;
public:
    Question();

};
Question::Question(){
    query="";
    choices = {};
}
class Test
{
public:
    std::string description;
    std::vector<Question> qiestionnaire;
    Test();
};

Test::Test()
{
    description ="";
    qiestionnaire ={};
}

Test test;
Question createQuestion(int counter);
Answer createAnswer();
void takeTest(const Test & test);
Test createTest();

Test createTest(){
    
    Test test{};
    Question q{};
    int qCount{0};
    std::cout<< "You are about to create a test. You must enter description of the test and the number of questions. \n Then adding a questions start \n "
    << "For each Qestion you start with the query and number of answers, then continue to the answers \n" 
    << "For each Answer you must provide its text, clarification why it is wrong, reward Points, penalty points. \n"
    << "To move onto the next question type \"NA\" or \"na\" for next question"
    << "To Finalize the test type \"eof\" and press Enter" << std::endl<<std::endl;
    
    std::cout<<"Please enter number of description of the test on 1 line: "<<std::endl;
    std::getline(std::cin, test.description);
    std::cout << std::endl;
    std::cout<<"Please enter number of questions: "<< std::endl;
    std::cin >> qCount;
    std::cout << std::endl;
    for(int i =0; i < qCount; i++)
    {
    int number{0};
    std::cout<< "How many possible answers to the question are expected?"<<std::endl;
    std::cin >> number; 
    std::cout<< "Please enter next question: \n"<<std::endl;
    q = createQuestion(number);
    test.qiestionnaire.push_back(q);   
    }
    
    return test;
}

Question createQuestion(int counter){
    Question q{};
    Answer a{};
    for(int i = 0; i < counter; i++)
    {
        a = createAnswer();
        q.choices.push_back(a);
    }
    return q;
}

Answer createAnswer(){
    Answer a{};
    std::cout << "Enter response:";
    std::cin >> a.response;
    std::cout <<std::endl<< "Enter clarification:";
    std::cin >> a.clarification;
    std::cout <<std::endl<< "Enter reward points(must be positive):";
    std::cin >> a.rewardPoints;
    std::cout << std::endl<<"Enter penalty points (must be positive number):";
    std::cin >> a.penaltyPoints;

    return a;
}

void takeTest(const Test & test){
    int score{0};
    int responseNumber{0};

    std::cout<< "You are taking a test. Description: \n" << test.description << std::endl
    << "After each question provide the number of the correct response!" << std::endl;

    for (Question q : test.qiestionnaire)
    { 
        std::cout<< std::endl<< q.query<< std::endl;
        for (int i =1; i <= q.choices.size(); i++)
        {
            std::cout << i <<". "<< q.choices[i-1].response<<std::endl;
        }
        std::cout<< "Provide the number of your answer: "<< std::endl;
        std::cin >> responseNumber;
        score += q.choices[responseNumber-1].rewardPoints - q.choices[responseNumber-1].penaltyPoints;
    }
    std::cout <<"Your score is: "<< score;
}



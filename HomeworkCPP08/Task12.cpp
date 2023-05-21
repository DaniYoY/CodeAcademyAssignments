// Задача 12
// Добавете функционалност в програмата за multiple-choice tests/quizzes (тема 05, задача 16) за
// сериализация и десериализация на отделните тестове.
// ● За целта дефинирайте функции за сериализация и десериализация на: отговор, въпрос и тест обекти.
// ● За всеки тест трябва да имаме отделен файл, който програмат да достъпва - за целта добавете член
// на класа тест за име на теста и кръщавайте файла на всеки тест с името на теста.
// ● Програмата трябва да прочита всички тестове от файл при стартиране и да ги записва при промяна
// от страна на потребителя в същия файл.

#include<string>
#include<iostream>
#include <fstream>
#include <vector>
struct TestSerializationConsts
{
    const std::string endOfTestDescription{"#!ENDDESCRIPTIOOFTEST!#"};
    const std::string endOfQestionQuery{"#!ENDQUESTIONQUERY!#"};
    const std::string endOfQestion{"#!ENDOFQUESTION!#"};
    const std::string beginOfQestion{"#!BEGOFQUESTION!#"};
    const std::string endOfAnswerResponse{"#!ENDANSWERRESPONSE!#"};
    const std::string endOfAnswerClarification{"#!ENDANSWERCLARIFICATION!#"};
    const std::string endOfAnswer{"#!ENDOFANSWER!#"};
    const std::string beginOfAnswer{"#!BEGOFANSWER!#"};
};

class Answer
{
public:
    std::string response;
    std::string clarification;
    int rewardPoints;
    int penaltyPoints;
    Answer(){
    response ="";
    clarification="";
    rewardPoints =0;
    penaltyPoints =0;
    };
    void clear(){
        this->response.clear();
        this->clarification.clear();
        this->rewardPoints =0;
        this->penaltyPoints =0;
    }
};

class Question
{
public:
    std::string query;
    std::vector<Answer> choices;
    Question(){
    query="";
    choices = {};
    };
    void clear(){
        this->query.clear();
        this->choices.clear();
    }

};

class Test
{
public:
    std::string description;
    std::vector<Question> qiestionnaire;
    Test(){
    description ="";
    qiestionnaire ={};
    };
};

void seriallizeAnswer(std::fstream & file,Answer & a){
   TestSerializationConsts t;
    file<< t.beginOfAnswer <<'\n';
    file<< a.response << '\n' << t.endOfAnswerResponse <<'\n';
    file<< a.clarification << '\n' << t.endOfAnswerClarification <<'\n';
    file << a.rewardPoints<< '\n'<< a.penaltyPoints<<'\n';
    file << t.endOfAnswer <<'\n';
}

void seriallizeQuestion(std::fstream & file,Question & q){
   TestSerializationConsts t;
    file << t.beginOfQestion <<'\n';
    file<< q.query << '\n' << t.endOfQestionQuery <<'\n';
    for (auto &&ans : q.choices)
    {
        seriallizeAnswer(file,ans);
    }
    file << t.endOfQestion <<'\n';
}

void seriallizeTest(Test & test){
    TestSerializationConsts t;
    std::fstream file;
    file.open("test.txt", std::ios::app);
    if(!file){
        std::cerr<< "file did not open"<<std::endl;
    }
    
    file << test.description <<'\n' << t.endOfTestDescription << '\n';
    for (auto & q : test.qiestionnaire)
    {
        seriallizeQuestion(file, q);
    }
    file.close();
}

Test deseriallizeTest(const std::string & fileName){
    TestSerializationConsts t;
    std::fstream file;
    file.open(fileName);
    std::string line{""};
    if(!file){
        std::cerr<< "File did not open" <<std::endl;
    }

    Test test;
    Question q;
    Answer a;

    while (std::getline(file, line))
    {
        if (test.description.empty())
        {
            while (line != t.endOfTestDescription)
            {
                test.description += line;
                std::getline(file, line);
            }
        }
        if (line == t.beginOfQestion)
        {
            while (std::getline(file, line))
            {
                if (line == t.endOfQestionQuery)
                {
                    break;
                }
                q.query += line;
            }    
        }
        
        bool endResponse{true},endClarif{false}, isTimeForPoints{false};
        if (line == t.beginOfAnswer){
            while (line != t.endOfAnswer)
            {
                std::getline(file, line);
                if (endResponse)
                {
                    if (line == t.endOfAnswerResponse)
                    {
                        endResponse = false;
                        endClarif = true;
                        continue;
                    }
                    a.response += line;
                }

                if (endClarif)
                {
                    if (line == t.endOfAnswerClarification)
                    {
                        isTimeForPoints = true;
                        endClarif = false;
                        continue;
                    }
                    a.clarification += line;
                }

                if (isTimeForPoints)
                {
                    a.rewardPoints = std::stoi(line);
                    std::getline(file, line);
                    a.penaltyPoints = std::stoi(line);
                    std::getline(file, line);
                }
                if (line == t.endOfAnswer)
                {
                    q.choices.push_back(a);
                    a.clear();
                }
                
            }
            
        }
        if(line == t.endOfQestion)
        {
            test.qiestionnaire.push_back(q);
            q.clear();
        }
    }
    return test;    
}

int main(int argc, char const *argv[])
{
    Answer a1, a2, a3,a4;
    Question q1,q2;
    Test test1;
    test1.description ="Test 1 is a test";
   
    q1.query ="How much is 6 * 4?";
    q2.query ="How much is 5 * 5?";
   
    a1.response = "24";
    a1.clarification = "1. Math!";
    a1.rewardPoints = 24;
    a1.penaltyPoints = 0;
    a2.response = "10";
    a2.clarification = "2. Math!";
    a2.rewardPoints = 0;
    a2.penaltyPoints = -25;
    a3.response = "10";
    a3.clarification = "3. Math!";
    a3.rewardPoints = 0;
    a3.penaltyPoints = -25;
    a4.response = "25";
    a4.clarification = "4. Math!";
    a4.rewardPoints = 25;
    a4.penaltyPoints = 0;

    q1.choices.push_back(a1);
    q1.choices.push_back(a2);
    q2.choices.push_back(a3);
    q2.choices.push_back(a4);

    test1.qiestionnaire.push_back(q1);
    test1.qiestionnaire.push_back(q2);

    seriallizeTest(test1);
    Test test2 = deseriallizeTest("test.txt");
    std::cout<< test2.description <<'\n'<<'\n';
    std::cout<< test2.qiestionnaire[0].query <<'\n';
    std::cout<< test2.qiestionnaire[0].choices[0].response <<'\n';
    std::cout<< test2.qiestionnaire[0].choices[0].response <<'\n'<<'n';
    std::cout<< test2.qiestionnaire[1].query <<'\n';
    std::cout<< test2.qiestionnaire[1].choices[0].response <<'\n';
    std::cout<< test2.qiestionnaire[1].choices[1].response <<'\n';
    return 0;
}

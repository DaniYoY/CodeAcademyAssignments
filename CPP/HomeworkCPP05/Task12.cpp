// Задача 12
// Дефинирайте тип Person с член данни за име, години, пол и височина. Дефинирайте type alias за контейнер от
// Person обекти - използвайте vector.
// Напишете програма, която позволява на потребителя да въвежда данните за група хора до въвеждане на EOF,
// след което принтира следната информация за групата хора:
// ● Брой мъже и брой жени.
// ● Средна възраст.
// ● Средна височина.
// ● Най-възрастните мъж и жена (цялата информация за тях).
// Използвайте type alias за типа на контейнера, enum за пол и помощни функции за въвеждане и извеждане на
// данните за човек, както и за изчисляване на необходимата информация, която трябва да се принтира.

#include <iostream>
#include <string>
#include <vector>


enum gender{
    m,
    f
};

class Person
{
public:
    std::string name;
    unsigned int age;
    gender gender;
    unsigned int height;
    Person();
};

using people = std::vector<Person>;

int averageAge(const people & crowd);
int averageHeight(const people & crowd);
int numM(const people &crowd);
int numF(const people & crowd);
void printInfoOfElders(const people &crowd);
void printPerson(const Person & p);

gender strToGender(std::string & gen){
    switch (gen[0])
    {
    case 'm':
    case 'M':
        return gender::m;
    case 'f':
    case 'F':
        return gender::f;
    }
}


Person::Person(){
    name = "";
    age= 0;
    height = 0;
}

Person makePerson(std::string nameInsert, int ageInsert, std::string g, int heightInsert ){
    Person p{};
    p.age = ageInsert;
    p.gender = strToGender(g);
    p.height = heightInsert;
    p.name = nameInsert;
    return p;
}

int averageAge(const people & crowd){
    int avg{0};
    if (crowd.empty())
    {
        return 0;
    }
    
    for (Person p : crowd)
    {
        avg += p.age;
    }
    return avg/crowd.size();
};

int averageHeight(const people & crowd){
    int avg{0};
    if (crowd.empty())
    {
        return 0;
    }
    
    for (Person p : crowd)
    {
        avg += p.height;
    }
    return avg/crowd.size();
};

int numM(const people & crowd){
    int num{0};
    for (Person p : crowd)
    {
        if(p.gender == gender::m){
            ++num;
        }
    }
    return num;
};

int numF(const people & crowd){
    int num{0};
    for (Person p : crowd)
    {
        if(p.gender == gender::f){
            ++num;
        }
    }
    return num;
};

void printInfoOfElders( const people & crowd){
    Person eldestMale{};
    Person eldestFemale{};

    for(Person p : crowd){
        if(p.gender == gender::f){
            if (p.age>eldestFemale.age)
            {
                eldestFemale = p;
            }
            
        }else{
            if (p.age>eldestFemale.age)
                {
                    eldestMale = p;
                }
        }
    }
    std::cout<< "Oldest female:" << std::endl;
    printPerson(eldestFemale);
    std::cout<< "Oldest male:" << std::endl;
    printPerson(eldestMale);
};

void printPerson(const Person & p){
 std::cout << "Person is "<< p.name << ", age " << p.age << std::endl
    <<  p.name << " is "<< p.gender <<" and " << p.height <<" tall"<< std::endl;
};

int main(){
    int age{0};
    int height{0};
    std::string name{""};
    std::string sex{""};
    people crowd;
    
    std::cout << "Please enter a person's information (name, age, first letter of the sex (m/f) and height)" << std::endl;
    std::cout << "After each entry you will be asked if you want to continue." << std::endl;
    char doContinue {' '};
    while (std::cin>>name>>age>>sex>>height)
    {
        Person p = makePerson(name,age, sex, height);
        crowd.push_back(p);

        std::cout << "Do you continue? Y/N" <<std::endl;
        std::cin >> doContinue;
        std::cout<<std::endl;
        if(doContinue == 'N' || doContinue == 'n'){
            break;
        }
    }

    std:: cout<<"Average age: "<< averageAge(crowd)<<std::endl;
    std:: cout<<"Average height: "<< averageHeight(crowd)<<std::endl;
    std:: cout<<"Number of females: "<< numF(crowd)<<std::endl;
    std:: cout<<"Number of males: "<< numM(crowd)<<std::endl;
    printInfoOfElders(crowd);
    std::cout<<std::endl;
    
}
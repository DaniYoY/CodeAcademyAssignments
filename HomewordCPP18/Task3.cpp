// Задача 03
// Напишете функция, която приема контейнер с Person обекти и преброява хората, които
// влизат в определен възрастов интервал [от, до].

#include <vector>
#include <iostream>
#include <algorithm>

class Person
{
private:
    int age;
public:
    Person(int year): age{year}{};
    int getAge() const{
        return this->age;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<Person> group {Person(4),Person(5),Person(16),Person(17),Person(3),Person(4),Person(5),Person(25),Person(0),Person(89),Person(30),Person(60),Person(45),Person(2)};
    int lowerRange{16},upperRange{40};
    int result = std::count_if(group.begin(),group.end(),
    [=](Person a){
        return a.getAge()>= lowerRange && a.getAge()<=upperRange;
    });
    std::cout<<result;
    return 0;
}

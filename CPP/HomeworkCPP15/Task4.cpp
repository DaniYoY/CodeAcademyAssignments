// Задача 04
// Напишете функция, която приема колекция от указатели, сочещи към Person обекти и ги сортира по име
// (лексикографски) на човека, към които сочат, използвайки selection sort.

#include <algorithm>
#include<string>
#include<iostream>
#include<vector>

class Person
{
private:
    std::string name;
public:
    Person(const std::string & val): name{val} {};
    const std::string getName () const{
        return this->name;
    }
};

void slctnSort(std::vector<Person> & v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        Person interimPerson = v[i];
        for (size_t j = 0; j < v.size(); j++)
        {
            if (v[j].getName() > interimPerson.getName())
            {
                interimPerson = v[j];   
            }
        
        if (v[i].getName() != interimPerson.getName())
        {
            std::swap(v[i],v[j]);
        }
        }
    }  
}

int main(int argc, char const *argv[])
{
    std::vector<Person> v;
    v = {Person("az"),Person("ab"),Person("zas"),Person("ar")};
    slctnSort(v);
    std::cout << v[0].getName() << ' ' << v[v.size()-1].getName();
    return 0;
}

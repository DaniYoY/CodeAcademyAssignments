// Задача 01
// Напишете функция, която приема последователно наредени в паметта Person обекти и ги сортира по име
// (лексикографски), използвайки bubble sort.
// Използвайте два указателя с имена beg и end за интерфейс на функцията, както ползваме iterator ranges

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

void bblSort(std::vector<Person> & v)
{
    Person * begin = & v[0];
    Person * end = & v[v.size()-1];
    auto size = end -begin;
    for (size_t i = 0; i < size; i++)
    {
        for (auto j = begin; j != end; j++)
        {
            if ((j)->getName() > (j+1)->getName())
            {
                std::swap(*j, *(j+1));
            }
            
        }
        
    }  
}

int main(int argc, char const *argv[])
{
    std::vector<Person> v;
    v = {Person("az"),Person("ab"),Person("zas"),Person("ar")};
    bblSort(v);
    std::cout << v[0].getName() << ' ' << v[v.size()-1].getName();
    return 0;
}

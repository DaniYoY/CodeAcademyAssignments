// Задача 05
// Използвайте binary search за да намерите човек по име в колекция от указатели към Person обекти.

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
        if (this == nullptr)
        {
            return "Person is not found";
        }
        
        return this->name;
    }
    static bool compare(Person p1, Person p2){
        return p1.getName() < p2.getName();
    }
};

Person * bs(std::vector<Person> & v,const std::string & name)
{
    std::sort(v.begin(),v.end(), Person::compare);
    size_t highBorder = v.size();
    size_t lowBorder = 0;

    while (highBorder - lowBorder > 1)
    {
        size_t midIdx = (highBorder+lowBorder)/2;
        if (v[midIdx].getName() < name)
        {
            lowBorder = midIdx;
        }else{
            highBorder = midIdx;
        }
    }

    if (v[highBorder].getName() == name)
    {
        return & v[highBorder];
    }

    if (v[lowBorder].getName() == name)
    {
        return & v[lowBorder];
    }
    return nullptr;
}

int main(int argc, char const *argv[])
{
    std::vector<Person> v;
    v = {Person("az"),Person("ab"),Person("zas"),Person("ar")};
    
    std::cout << bs(v, "zas")->getName();
    return 0;
}
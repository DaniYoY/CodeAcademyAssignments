// Задача 04
// Напишете функция, която сортира масив от указатели към Person обекти по височина

#include <iostream>

class Person
{
    public:
    float height;
    Person(){
        this->height =0.0;
    };
    Person(float h){
        this->height =h;
    };
};

void sort(Person * begin, Person * end){
    for (; begin != end; begin++)
    {
        for (Person* it = begin +1; it != end; it++)
        {
            Person temp = *begin;
            if ((begin)->height > (it)->height)
            {
                *begin = *it;
                *it =temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    Person g1(1.75),g2(1.85),g3(1.45),g4(1.5),g5(1.26),g6(2.26);
    Person group[] ={g1,g3,g2,g4,g5,g6};
    sort(std::begin(group), std::end(group));
    for (Person p : group)
    {
        std::cout << p.height<<' ';
    }
    
    return 0;
}

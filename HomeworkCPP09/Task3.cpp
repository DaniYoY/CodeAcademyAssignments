// Задача 03
// Напишете функция, която приема два масива от Person обекти и проверява дали всеки човек от единия масив
// има равна височина (в километри - използвайте float) със съответстващият му по индекс човек от втория масив.

#include <string>
#include <iostream>
#include <array>

// template <std::size_t SIZE>

#define SIZE 6
//  100 000cm == 1km , so 1km is 10 by power of 5
int km2cm = 5; 
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

bool compare(float n1, float n2,unsigned int precision){
     float epsilon {0.1f};
    for (int i = 0; i < precision; i++)
    {
        epsilon /= 10;
    }
    return std::abs(n1 -n2) < epsilon;
}
bool areAlignedByHeight(Person group1[], Person * group2, size_t sizeOfArr){
    for (size_t i = 0; i < sizeOfArr; i++)
    {
        float p1h = (group1+i) ->height;
        float p2h =  (group2+i)->height;
        if (!compare(p1h,p2h, km2cm)){
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    Person g1(0.00185),g2(0.00195f),g3(0.00185f),g4(0.00155f);
    Person group1[] = {g1,g2};
    Person group2[] = {g3,g4};
    std::cout<< areAlignedByHeight(group1, group2, 2);
    return 0;
}

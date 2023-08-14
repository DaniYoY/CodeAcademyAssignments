// Задача 01
// Напишете функция за принтиране на колекция от всякакъв тип, с всякакъв брой елементи (който дефинира оператор <<, работещ с ostream обект)


#include <iostream>
#include<algorithm>
#include<vector>
#include<list>
template <class T>

void printAll(std::ostream& s, T begin, T last)
{
   for (T  i = begin; i != last; i++)
   {
    s << *i << ' ';
   }
}

int main(int argc, char const *argv[])
{
    std::list<int> lst = {1,2,3,4,5};
    std::vector<char> vec = {'a','b','c','d'};
    printAll(std::cout, lst.begin(),lst.end());
    std::cout<< std:: endl;
    printAll(std::cout, vec.begin(),vec.end());
    return 0;
}

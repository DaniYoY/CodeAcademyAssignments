// Задача 01
// Напишете функция за принтиране на колекция от всякакъв тип, с всякакъв брой елементи (който
// дефинира оператор <<, работещ с ostream обект)
#include <iostream>
#include<algorithm>
#include<vector>
#include<list>
template <class T>

void printAll(T begin, T last)
{
   for (T  i = begin; i != last; i++)
   {
    typename std::iterator_traits<T>::value_type n = *i; 
    std:: cout << n << ' ';
   }
}

int main(int argc, char const *argv[])
{
    std::list<int> lst = {1,2,3,4,5};
    std::vector<char> vec = {'a','b','c','d'};
    printAll(lst.begin(),lst.end());
    std::cout<< std:: endl;
    printAll(vec.begin(),vec.end());
    return 0;
}

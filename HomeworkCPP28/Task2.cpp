// Задача 02
// Дефинирайте class template със статичен метод getInfo, който връща низ “unknown”.
// Специализирайте класа за няколко типа по избор и принтирайте името на типа в статичния метод.
#include<string>
#include<iostream>
template<typename T>
class Templ{
public:
Templ(){};
static const char* getInfo(const T& ){
    return "unknown\n";
}
};

template<> const char* Templ<int>:: getInfo(const int& ){
    return "int\n";
};
template<> const char* Templ<const char*>::getInfo (const char* const & ){
    return "const char\n";
}
template<> const char* Templ<double>::getInfo (const double & ){
    return "double\n";
}

int main(int argc, char const *argv[])
{
    int a {123};
    const char * b{"gfdhre"};
    double c {23.36};
    float d {0.668};
    std::cout << Templ<int>::getInfo(a);
    std::cout << Templ<const char*>::getInfo(b);
    std::cout << Templ<double>::getInfo(c);
    std::cout << Templ<float>::getInfo(d);
    return 0;
}

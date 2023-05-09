#include <iostream>

int main (){
using namespace std;
    int h = 0x10;
    int o = 010;
    int d = 10;
    int b = 0b10;
    int u = 10U;
    long l = 10l;
    unsigned long ul = 10ul;
    long long ll = 10ll;
    unsigned long long ull = 10ull;

    double f = 1.5;
    double fe = 1.5e+2;
    double fl = 1.5+50l;

    bool trueest = true;
    bool falseest = false;

    wchar_t widechr = L'a';
    char chr = 'a';
    char chrNum = 65;

    string str = "string literal";

    cout << h << endl 
         << o<< endl
         << d<< endl
         << b<< endl
         << u<< endl
         << l<< endl
         << ul<< endl
         << ll<< endl
         << ull<< endl
         << f<< endl
         << fe<< endl
         << fl<< endl
         << trueest<< endl
         << falseest<< endl
         << widechr<< endl
         << chr<< endl
         << chrNum<< endl
        << str << endl;
    return 0;
}
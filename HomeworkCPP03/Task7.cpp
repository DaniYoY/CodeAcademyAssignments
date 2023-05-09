#include <iostream>

int main (){
using namespace std;
    cout <<"Bool is " <<sizeof(bool) << " bytes" << endl;
    cout <<"Signed int is " <<sizeof(signed int) << " bytes" << endl;
    cout <<"Unsigned int is " <<sizeof(unsigned int) << " bytes"<< endl;
    cout <<"Short is " <<sizeof(short) << " bytes"<< endl;
    cout <<"Long is " <<sizeof(long) << " bytes"<< endl;
    cout <<"Long int is " <<sizeof(long int) << " bytes"<< endl;
    cout <<"Long long int is " <<sizeof(long long int) << " bytes"<< endl;
    cout <<"Char is " <<sizeof(char) << " bytes"<< endl;
    cout <<"WChar is " <<sizeof(wchar_t) << " bytes"<< endl;
    cout <<"Float is " <<sizeof(float) << " bytes"<< endl;
    cout <<"Double is " <<sizeof(double) << " bytes"<< endl;
    cout <<"Long double is " <<sizeof(long double) << " bytes"<< endl;

    return 0;
}
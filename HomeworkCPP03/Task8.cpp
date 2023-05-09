#include <iostream>

int main (){
using namespace std;
    unsigned long long int year{0}, ms{0},msInSec{100}, secInMin{60},minInHr{60},hrInDay{24}, dInYear{356}, dInLeapYear{366};
    cout << "I tell the miliseconds in a year, so enter a year: "<< endl;
    cin >> year;
    cout <<"Miliseconds are: ";
    if (year % 4 == 0){
        ms = msInSec*secInMin*minInHr*hrInDay*dInYear;
    }else{
        ms = msInSec*secInMin*minInHr*hrInDay*dInLeapYear;
    }
    cout << ms << "ms" << endl;
    return 0;
}
#include <iostream>

int main (){
using namespace std;
    unsigned long long int ms{0}, msInSec{100}, secInMin{60},minInHr{60},hrInDay{24};
    int sec{0}, min{0},hours{0},days{0};
    cout << "Please enter miliseconds: " << endl;
    cin >> ms;
    days = ms /(msInSec*secInMin*minInHr*hrInDay);
    ms %= (msInSec*secInMin*minInHr*hrInDay);
    hours = ms /(msInSec*secInMin*minInHr);
    ms %= (msInSec*secInMin*minInHr);
    min = ms /(msInSec*secInMin);
    ms %= (msInSec*secInMin);
    sec = ms /(msInSec);
    ms %= (msInSec);
    cout << days << " " << hours << " " << min << " " << sec << " " << ms <<endl;
    
    return 0;
}
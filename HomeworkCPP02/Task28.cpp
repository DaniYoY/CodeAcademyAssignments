#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>



int main(){
    using namespace std;
    int  minNum{INT_MAX}, maxNum{INT_MIN}, sminNum{INT_MAX}, smaxNum{INT_MIN}, interim{0};
    string input {" "};

    while (true)
    {
       try
       {
        cin >> input;
        interim = stoi(input);
        minNum = min(interim, minNum);
        sminNum = max(sminNum, minNum);
        maxNum = max(interim, maxNum);
        smaxNum = min(smaxNum, maxNum);
       }
       catch(const std::exception& e)
       {
        cout << setprecision(2) << "Second biggest num is "<< smaxNum << " and second smallest is " << sminNum << endl;
        break;
       }
       
    }
    
  
    return 0;
}
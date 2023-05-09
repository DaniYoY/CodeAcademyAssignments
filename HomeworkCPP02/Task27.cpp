#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>



int main(){
    using namespace std;
    int  minNum{INT_MAX}, maxNum{INT_MIN}, interim{0};
    string input {" "};

    while (true)
    {
       try
       {
        cin >> input;
        interim = stoi(input);
        minNum = min(interim, minNum);
        maxNum = max(interim, maxNum);
       }
       catch(const std::exception& e)
       {
        cout << setprecision(2) << "Biggest num is "<< maxNum << " and smallest is " << minNum << endl;
        break;
       }
       
    }
    
  
    return 0;
}
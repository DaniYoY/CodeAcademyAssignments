#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>

int main(){
    using namespace std;
    int counter{0};
    float sum{0.0f};
    string input {" "};

    while (true)
    {
       try
       {
        cin >> input;
        sum += stoi(input);
        counter++;
       }
       catch(const std::exception& e)
       {
        cout << setprecision(2) << sum / counter << endl;
        break;
       }
       
    }
    
  
    return 0;
}
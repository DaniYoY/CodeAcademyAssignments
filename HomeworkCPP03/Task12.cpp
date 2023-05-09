#include <iostream>
#include <string>
#include <cmath>

int main (){
using namespace std;
long result{0};
cout << "Enter a binary number only with 0s ans 1s: ";
// cin >> input;
cin >> hex >> result;
cout << result << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <cmath>

int main (){
using namespace std;
string input{" "};
long result{0};
cout << "Enter a binary number only with 0s ans 1s: ";
cin >> input;
for (size_t i = 0; i <input.size() ; i++)
{
   if (input[input.size() -1- i] == '1'){
    result += (long) powl(2,i);
   }
}
cout << result << endl;
    return 0;
}
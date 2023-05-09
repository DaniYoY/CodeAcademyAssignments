#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

int action (int num1, int num2, char oprt){
    
    switch (oprt)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;    
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;    
    default:
        return num1;
    }
}

bool isMathSign( std::string sign){
    if (sign == "+" || sign == "-" || sign == "*" || sign == "/"){
        return true;
    }
    return false;
}

int main(){
    using namespace std;
    int a{0},interim{0};
    char oprtr{' '};
    bool isFirstTime = true;
    string input {" "};

    while (true)
    {
try
{
   if (isFirstTime){
            isFirstTime = false;
            cin >> input;
            interim = stoi(input);
            cin >> input;
            oprtr = input[0];
            cin >> input;
            a= stoi(input);
            a = action(a, interim, oprtr);
        }else{
            cin >> input;
            if (isMathSign(input)){
            oprtr = input[0];
            }else{
                cout << a << endl;
                break;
            }
            cin >> input;
            interim = stoi(input);
            a = action(a, interim, oprtr);
        }
}
catch(const std::exception e)
{
    cout <<  a << endl;
    break;
}
   
    }
  
    return 0;
}

  
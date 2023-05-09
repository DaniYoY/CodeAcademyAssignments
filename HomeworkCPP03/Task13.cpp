#include <iostream>

int main (){
using namespace std;
    int x{0U};
    string input{" "};
    
    cin >> input;
   
   if(input[0] == '0'){
    if(input[1] == 'b'){
        x = stoi(input.substr(2),0,2);
    }else if (input[1] == 'x')
    {
        x = stoi(input.substr(2),0,16);
    }else if(isdigit(input[1])){
        x = stoi(input.substr(1),0,8);
    }
   }else{
        x = stoi(input,0,10);
   }
   
    cout << x <<endl; 
    return 0;
}
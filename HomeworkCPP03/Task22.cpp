#include <iostream>
#include <string>

int main (){
using namespace std;
    string str{""};
    string output{""};
    bool isPalindrome {true};
    getline(cin, str);
   
    for (size_t i = 0; i < str.size(); i++)
    {
        if(str[i] == '.'){
            output +="!!!";
            continue;
        }
        output += toupper(str[i]);
    }
    
    cout << output << endl;
    


    return 0;
}
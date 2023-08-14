#include <iostream>
#include <string>

int main (){
using namespace std;
    string str{""};
    bool isPalindrome {true};
    getline(cin, str);
   
    for (size_t i = 0, z = str.size()-1; i < str.size()/2; )
    {
        if (!isalnum(str[i]))
        {
            i++;
            continue;
        }
        if(!isalnum(str[z])){
            z--;
            continue;
        }
         
        
        if (tolower(str[i]) != tolower( str[z]))
        {
            isPalindrome =false;
            break;
        }   
        i++;
        z--;

    }
    
    if (isPalindrome)
    {
        cout << "This is a palindrome" << endl;
    }else{
        cout << "This is not a palindrome" << endl;

    }
    


    return 0;
}
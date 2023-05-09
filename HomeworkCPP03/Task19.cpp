#include <iostream>
#include <string>

int main (){
using namespace std;
    string str{""};
    bool isPalindrome {true};
    getline(cin, str);
   
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] != str[str.size() -1-i])
        {
            isPalindrome =false;
        }   
    }
    
    if (isPalindrome)
    {
        cout << "This is a palindrome" << endl;
    }else{
        cout << "This is not a palindrome" << endl;

    }
    


    return 0;
}
#include <iostream>
#include <string>

int main (){
using namespace std;
    string str{""};
   int lineCounter{0}, wordCounter{0},charCounter{0};
   while (cin)
   {
    getline(cin, str);
    
    
   
    for (size_t i = 0; i < str.size(); i++)
    { 
    
    if (isalpha(str[i]))
    {
        charCounter++;
    }

    if ((str[i] == ' ' && str[i+1] != ' ') || (str[i] == '\t' && str[i+1] != ' '))
    {
        wordCounter++;
        
    }
    if (i == str.size()-1)
    {
            lineCounter++;
    }
        
    }
   }
   
   cout <<"line: " << lineCounter << endl
        << "words: " << wordCounter << endl
        << "chars: " << charCounter << endl;


    return 0;
}
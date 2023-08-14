#include <iostream>
#include <string>

int main (){
using namespace std;
    string str{""};
    int wordsLen{0}, wordsCounter {0}; 
    getline(cin,str);
    if (isalpha(str[0]))
    {
        wordsCounter++;
    }
    
    for (size_t i = 0; i < str.size(); i++)
    {
        if (isalpha(str[i]))
        {
            wordsLen++;
        }

        if (i !=str.size()-1 && !isalpha(str[i]) && isalpha(str[i+1]) )
        {
            wordsCounter++;
        }
    }
    
    cout << "Avg len: " << wordsLen / wordsCounter;

    return 0;
}
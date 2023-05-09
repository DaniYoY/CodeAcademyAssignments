#include <iostream>
#include <string>
#include <cctype>

int main (){
using namespace std;
    string str{""}, result{""};
    getline(cin,str);
   for (size_t i = 0; i < str.size()-1; i++)
    {
        if (isspace(str[i]) && isspace(str[i+1]) )
        {
            continue;
        }
        result += str[i];
    }
        result += str[str.size()-1];
    cout << result;

    return 0;
}
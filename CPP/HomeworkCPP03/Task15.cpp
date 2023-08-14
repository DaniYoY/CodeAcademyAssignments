#include <iostream>
#include <string>

int main (){
using namespace std;
    string str{" "};
    cin >> str;
    for (size_t i = 0u; i < str.size(); i++)
    {
        cout << str[str.size() -1 -i];
    }
    
    return 0;
}
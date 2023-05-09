#include <iostream>
#include <string>

int main (){
using namespace std;
    string str{""};
    char a {' '};
    int counter {0};

    getline(cin, str);
    cout << endl;
    cin >> a;
    for (char s:str)
    {
        if (s == a){
            counter++;
        }
    }
    cout << endl << counter <<endl;
    return 0;
}
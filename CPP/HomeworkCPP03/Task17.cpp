#include <iostream>
#include <string>

int main (){
using namespace std;
    string str{""};
    char a {' '};
    int firstPos {-1};
    int lasttPos {-1};
    bool firstPosDone {false};
    getline(cin, str);
    cout << endl;
    cin >> a;
    for (size_t i = 0; i < str.size(); i++)
    {
        if(str[i]== a && !firstPosDone){
            firstPos = i;
            lasttPos =i;
            firstPosDone = true;
        }
        if(str[i]==a){
            lasttPos = i;
        }
    }
    
    cout << endl << firstPos << " " << lasttPos <<endl;
    return 0;
}
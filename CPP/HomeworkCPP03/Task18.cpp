#include <iostream>
#include <string>

int main (){
using namespace std;
    string str{""};
    int begin {0};
    int end {0};

    cout << "Please enter a string" << endl;
    getline(cin, str);
    cout << endl;
    cout << "Please numbers of the substring" << endl;
    cin >> begin, end;

    if (begin < end){
        cout << str.substr(begin,end);
    }else{
        cout << str.substr(end,begin);
    }
    
    return 0;
}
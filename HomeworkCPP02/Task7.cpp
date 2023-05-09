#include <iostream>

int main(){
    using namespace std;
    int b {0};
    cin >> b;
    b % 2 == 0 ? cout << "The number is even" : cout << "The number is odd";
    cout << endl;
    return 0;
}
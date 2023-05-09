#include <iostream>

int main(){
    using namespace std;
    int a{0},b{0}, interim {0};
    cout << "Please enter num A: " << endl;
    cin >> a;
    cout << "Please enter num B: " << endl;
    cin >> b;
    interim = a;
    a = b;
    b = interim;
    cout << "A is now " << a << " and B is " << b << endl; 

    return 0;
}
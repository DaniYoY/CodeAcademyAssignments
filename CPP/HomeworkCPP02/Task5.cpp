#include <iostream>

int main(){
    using namespace std;
    float a{0.0f}, b{0.0f}, c{0.0f};
    cin >> a >> b >> c;
    a > b ? a = b : a ;
    a < c ? cout << a : cout << c;
    cout << endl; 
    return 0;
}
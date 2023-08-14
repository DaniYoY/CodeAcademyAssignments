#include <iostream>

int main(){
    using namespace std;
    float a{0.0f}, b{0.0f};
    cin >> a >> b;
    a > b ? cout << a : cout << b << endl;
    return 0;
}
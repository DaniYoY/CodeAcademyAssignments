#include <iostream>

int main(){
    using namespace std;
    int a{0}, b{0};
    cin >> a >> b;
    for (int i = a+1; i < b; i++)
    {
        a += i;
    }
    cout << a << endl;
  
    return 0;
}
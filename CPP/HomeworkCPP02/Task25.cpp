#include <iostream>

int main(){
    using namespace std;
    int a{0}, b{0}, sum{0};
    cin >> a >> b;
    for (int i = a; i < b; i++)
    {
        if(i % 2 == 0){
            sum += i;
        }
    }
    cout << sum << endl;
  
    return 0;
}